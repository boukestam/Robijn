#include "WebInterfaceController.hpp"

WebInterfaceController::WebInterfaceController( WashingProgramController* washingProgramController,
                            HardwareSensor* temperatureSensor,
                            HardwareSensor* waterLevelSensor,
                            HardwareSensor* rotationSensor,
                            HardwareSensor* washingMachineStatusSensor):
	task(3, "webInterfaceController")
{
    this->washingProgramController = washingProgramController;

    this->temperatureSensor = temperatureSensor;
    this->temperatureSensor->addListener(this);

    this->waterLevelSensor = waterLevelSensor;
    this->waterLevelSensor->addListener(this);

    this->rotationSensor = rotationSensor;
    this->rotationSensor->addListener(this);

    this->washingMachineStatusSensor = washingMachineStatusSensor;
    this->washingMachineStatusSensor->addListener(this);
    
    this->currentWashingProgramStatus = new WashingProgramStatus();

    // TODO(Yorick): Load washing programs from file
	
    WashingProgramStep step;
    step.duration = 100;
    step.rotationSpeed = 1200;
    step.temperature = 45;
    step.waterLevel = 80;

    WashingProgram* wp = new WashingProgram();
    wp->addStep(step);
    wp->addStep(step);
    wp->addStep(step);

    washingPrograms.push_back(wp);
}

void WebInterfaceController::main()
{
    while(true){
        // TODO(Yorick): Update the time of the status object?
        SocketMessage* msg;
        bool msgReceived = socketServer->receiveMessage(msg);

        if(msgReceived){
        	std::cout << "Web interface received message" << std::endl;
        
            std::string eventKey("event");
            rapidjson::Document& document = msg->getJSON();
            rapidjson::Value& val = document["event"];
			std::string event = val.GetString();
			
			std::cout << "Web interface after json event get" << std::endl;
			
			std::cout << "Event type: " << event << std::endl;

            // check events
            if(event == "startWashingProgram"){
                // start washing program
                // Using a reference for consecutive access is handy and faster.
                WashingProgram wp;
                rapidjson::Value& stp = document["steps"];
                for (rapidjson::SizeType i = 0; i < stp.Size(); i++){ // Uses SizeType instead of size_t
                    WashingProgramStep step;
                    step.temperature = stp[i]["degrees"].GetInt();
                    step.rotationSpeed = stp[i]["rpm"].GetInt();
                    step.waterLevel = stp[i]["water"].GetInt();
                    step.duration = stp[i]["time"].GetInt();
                    wp.addStep(step);
                }

                washingProgramController->startWashingProgram(wp);
            } else if(event == "stopWashingProgram") {
                // Stop current washing program
                washingProgramController->stopWashingProgram();
            } else if(event == "statusUpdate"){
                // Get data parse to msg and send back
                std::cout << "Before send message call" << std::endl;
                SocketMessage* msg2 = currentWashingProgramStatus->toSocketMessage();
                std::cout << "After getting message" << std::endl;
                socketServer->sendMessage(msg2);
            } else if(event == "getWashingPrograms"){
                // Show washing program list
                socketServer->sendMessage(createSocketMessageFromWashingList());
            }
            
            std::cout << "Web interface processed message" << std::endl;
        }
    }
}

void WebInterfaceController::valueChanged(HardwareSensor* sensor, unsigned char value)
{
    if(sensor == temperatureSensor){
        currentWashingProgramStatus->temperature = value;
    } else if (sensor == waterLevelSensor) {
        currentWashingProgramStatus->waterLevel = value;
    } else if (sensor == rotationSensor) {
        currentWashingProgramStatus->rotationSpeed = value;
    } else if (sensor == washingMachineStatusSensor) {
        WashingMachineStatus stats;
        switch(value){
            case 0:
                stats = WashingMachineStatus::idle;
                break;
            case 1:
                stats = WashingMachineStatus::running;
                break;
            case 2:
                stats = WashingMachineStatus::stopped;
                break;
            case 3:
                stats = WashingMachineStatus::halted;
                break;
            case 4:
                stats = WashingMachineStatus::failed;
                break;
        }

        currentWashingProgramStatus->status = stats;
    }
}

SocketMessage* WebInterfaceController::createSocketMessageFromWashingList()
{
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);

    writer.StartObject();
    writer.Key("event");
    writer.String("washingProgramList");
    writer.Key("washingPrograms");
    writer.StartArray();
    for(unsigned int i = 0; i < washingPrograms.size(); i++)
    {
        WashingProgram* wp = washingPrograms.at(i);
        writer.StartObject();
        writer.Key("discription");
        writer.String(wp->dicription.c_str());
        writer.Key("steps");
        writer.StartArray();
        for (unsigned int j = 0; j < wp->getStepSize(); j++) {
            WashingProgramStep step = wp->getStep(j);
            writer.StartObject();
            writer.Key("degrees");
            writer.Uint(step.temperature);
            writer.Key("rpm");
            writer.Uint(step.rotationSpeed);
            writer.Key("water");
            writer.Uint(step.waterLevel);
            writer.Key("time");
            writer.Uint(step.duration);
            writer.EndObject();
        }
        writer.EndArray();
        writer.EndObject();
    }
    writer.EndArray();
    writer.EndObject();

    SocketMessage* msg = new SocketMessage();
    msg->parseJSONString(s.GetString());
    return msg;
}

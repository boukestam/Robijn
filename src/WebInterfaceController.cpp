#include "WebInterfaceController.hpp"

WebInterfaceController::WebInterfaceController( WashingProgramController* washingProgramController,
                            HardwareSensor* temperatureSensor,
                            HardwareSensor* waterLevelSensor,
                            HardwareSensor* rotationSensor,
                            HardwareSensor* washingMachineStatusSensor):
	task(3, "webInterfaceController"),
	sleepTimer(this, "webInterfaceController")
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
	loadWashingPrograms();
}

void WebInterfaceController::loadWashingPrograms()
{
	std::ifstream file("wasprograms.json");
	std::string str;
	std::string file_contents;
	while (std::getline(file, str))
	{
		file_contents += str;
	}  


	rapidjson::Document document;
	document.Parse(file_contents.c_str());

	const rapidjson::Value& a = document["washingPrograms"];
	
	for(rapidjson::SizeType j = 0; j < a.Size(); j++)
	{
		const rapidjson::Value& jsonsteps = a[j]["steps"];

		WashingProgram* wp = new WashingProgram();
		wp->dicription = a[j]["description"].GetString();
	
		// rapidjson uses SizeType instead of size_t.
		for (rapidjson::SizeType i = 0; i < jsonsteps.Size(); i++){
			const rapidjson::Value& setting = jsonsteps[i];

			WashingProgramStep step;
		    step.temperature = stoi(setting["degrees"].GetString());
		    step.rotationSpeed = stoi(setting["rpm"].GetString());
		    step.waterLevel = stoi(setting["water"].GetString());
		    step.duration = stoi(setting["time"].GetString());
            step.rotationInterval = stoi(setting["rotationInterval"].GetString());
            
            std::cout << " Rotation interval: " << step.rotationInterval << std::endl;
		    
		    wp->addStep(step);
		}
		washingPrograms.push_back(wp);
	}

}

void WebInterfaceController::main()
{
    while(true){
        SocketMessage* msg;
        bool msgReceived = socketServer->receiveMessage(msg);

        if(msgReceived){
            std::string eventKey("event");
            rapidjson::Document& document = msg->getJSON();
            rapidjson::Value& val = document["event"];
			std::string event = val.GetString();

            // check events
            if(event == "startWashingProgram"){
                // start washing program
                // Using a reference for consecutive access is handy and faster.
				const rapidjson::Value& a = document["washingProgram"];
				const rapidjson::Value& jsonsteps = a["steps"];

				WashingProgram* wp = new WashingProgram();

				// rapidjson uses SizeType instead of size_t.
				for (rapidjson::SizeType i = 0; i < jsonsteps.Size(); i++){
					const rapidjson::Value& setting = jsonsteps[i];

					WashingProgramStep step;

                    step.temperature = stoi(setting["degrees"].GetString());
                    step.rotationSpeed = stoi(setting["rpm"].GetString());
                    step.waterLevel = stoi(setting["water"].GetString());
                    step.duration = stoi(setting["time"].GetString());
                    step.rotationInterval = stoi(setting["rotationInterval"].GetString());

                    wp->addStep(step);
				}

				washingProgramController->startWashingProgram(wp);

            } else if(event == "stopWashingProgram") {
                // Stop current washing program
                washingProgramController->stopWashingProgram();
            } else if(event == "statusUpdate"){
                // Get data parse to msg and send back
                SocketMessage* msg2 = currentWashingProgramStatus->toSocketMessage();
                socketServer->sendMessage(msg2);
            } else if(event == "getWashingPrograms"){
                // Show washing program list
                socketServer->sendMessage(createSocketMessageFromWashingList());
            }
        }

		sleepTimer.set(1000 MS);
		wait(sleepTimer);
		// Send status update every 1000MS
		if(currentWashingProgramStatus->status ==  WashingMachineStatus::running){
			currentWashingProgramStatus->totalSteptime = washingProgramController->getCurrentStep().duration;
            currentWashingProgramStatus->duration = washingProgramController->getStepTimeRunning();
			SocketMessage* msg2 = currentWashingProgramStatus->toSocketMessage();
        	socketServer->sendMessage(msg2);
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

	std::cout << "New status: " << (int)value << std::endl;

        switch(value){
            case 0x01:
                stats = WashingMachineStatus::halted;
                break;
            case 0x02:
                stats = WashingMachineStatus::idle;
                break;
            case 0x04:
                stats = WashingMachineStatus::running;
                break;
            case 0x08:
                stats = WashingMachineStatus::stopped;
                break;
            case 0x00:
                stats = WashingMachineStatus::failed;
                break;
			default:
				stats = WashingMachineStatus::running;
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
        writer.Key("description");
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
            writer.Key("rotationInterval");
            writer.Uint(step.rotationInterval);
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

#include "WebInterfaceController.hpp"

WebInterfaceController::WebInterfaceController( WashingProgramController* washingProgramController,
                            HardwareSensor* temperatureSensor,
                            HardwareSensor* waterLevelSensor,
                            HardwareSensor* rotationSensor,
                            HardwareSensor* washingMachineStatusSensor)
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

    // TODO(Yorick): Load washing programs from file

    WashingProgramStep step;
    step.duration = 100;
    step.rotationSpeed = 1200;
    step.temperature = 45;
    step.waterLevel = 80;

    WashingProgram* wp;
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
            std::string eventKey("event");
            std::string event = msg->getValue<std::string>(eventKey);
            std::string idkey("id");

            // check events
            if(event == "startWashingProgram"){
                // start washing program
                std::string id = msg->getValue<std::string>(idkey);
                int iId = std::stoi(id);
                if(washingPrograms.at(iId) != nullptr){
                    washingProgramController->startWashingProgram(*washingPrograms.at(iId));
                }
            } else if(event == "stopWashingProgram") {
                // Stop current washing program
                washingProgramController->stopWashingProgram();
            } else if(event == "statusUpdate"){
                // Get data parse to msg and send back
                socketServer->sendMessage(currentWashingProgramStatus->toSocketMessage());
            } else if(event == "washingProgramList"){
                // Show washing program list
                socketServer->sendMessage(createSocketMessageFromWashingList());
            }
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
                stats = WashingMachineStatus.idle;
                break;
            case 1:
                stats = WashingMachineStatus.running;
                break;
            case 2:
                stats = WashingMachineStatus.stopped;
                break;
            case 3:
                stats = WashingMachineStatus.halted;
                break;
            case 4:
                stats = WashingMachineStatus.failed;
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
    for(int i = 0; i < washingPrograms.size(); i++)
    {
        WashingProgram* wp = washingPrograms.at(i);
        writer.StartObject();
        writer.Key("discription");
        writer.String(wp->dicription.c_str());
        writer.Key("steps");
        writer.StartArray();
        for (unsigned int i = 0; i < wp->getTotalSteps(); i++) {
            WashingProgramStep step = wp->getStep(i);
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

    SocketMessage* msg;
    msg->parseJSONString(s.GetString());
    return msg;
}

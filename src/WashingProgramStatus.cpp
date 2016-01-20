#include "WashingProgramStatus.hpp"

#include <iostream>

SocketMessage* WashingProgramStatus::toSocketMessage(){
    // TODO(Yorick): Get the name of the washing program
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);

    int stat = 0x00;
    switch(status){
        case WashingMachineStatus::halted:
            stat = 0x01;
            break;
        case WashingMachineStatus::idle:
            stat = 0x02;
            break;
        case WashingMachineStatus::running:
            stat = 0x04;
            break;
        case WashingMachineStatus::stopped:
            stat = 0x08;
            break;
        case WashingMachineStatus::failed:
            stat = 0x00;
            break;
    }

    writer.StartObject();
        writer.Key("event");
        writer.String("statusUpdate");
        writer.Key("washingProgram");
        writer.StartObject();
            writer.Key("description");
            writer.String("No description in status");
            writer.Key("currentStep");
            writer.Uint(currentStep);
            writer.Key("totalSteps");
            writer.Uint(totalSteps);
            writer.Key("data");
            writer.StartObject();
                writer.Key("status");
                writer.Uint(stat);
                writer.Key("currentDegrees");
                writer.Uint(temperature);
                writer.Key("currentRpm");
                writer.Uint(rotationSpeed);
                writer.Key("currentWaterLevel");
                writer.Uint(waterLevel);
                writer.Key("timeRunning");
                writer.Uint(totalSteptime - timeLeft);
                writer.Key("totalTime");
                writer.Uint(totalSteptime);
            writer.EndObject();
        writer.EndObject();
    writer.EndObject();

    SocketMessage* msg = new SocketMessage();
    msg->parseJSONString(s.GetString());
    return msg;
}

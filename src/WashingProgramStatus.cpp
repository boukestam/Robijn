#include "WashingProgramStatus.hpp"

#include <iostream>

SocketMessage* WashingProgramStatus::toSocketMessage(){
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);

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
                writer.Uint(status);
                writer.Key("currentDegrees");
                writer.Uint(temperature);
                writer.Key("currentRpm");
                writer.Uint(rotationSpeed);
                writer.Key("currentWaterLevel");
                writer.Uint(waterLevel);
                writer.Key("timeRunning");
                writer.Uint(duration);
                writer.Key("totalTime");
                writer.Uint(totalSteptime);
            writer.EndObject();
        writer.EndObject();
    writer.EndObject();

    SocketMessage* msg = new SocketMessage();
    msg->parseJSONString(s.GetString());
    return msg;
}

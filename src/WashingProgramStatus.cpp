#include "WashingProgramStatus.hpp"

SocketMessage* WashingProgramStatus::toSocketMessage()
{
    // TODO(Yorick): Get the name of the washing program
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);

	//int stats = stats;

    writer.StartObject();
        writer.Key("event");
        writer.String("statusUpdate");
        writer.Key("washingProgram");
        writer.StartObject();
            writer.Key("description");
            writer.String("Change name in washingprogramstatus.cpp");
            writer.Key("currentStep");
            writer.Uint(currentStep);
            writer.Key("totalSteps");
            writer.Uint(totalSteps);
            writer.Key("data");
            writer.StartObject();
                writer.Key("status");
                writer.Uint(0);
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

    SocketMessage* msg;
    msg->parseJSONString(s.GetString());
    return msg;
}

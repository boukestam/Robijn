#pragma once

#include "pRTOS.h"

#include "SocketServer.hpp"
#include "WebServer.hpp"

#include "WashingProgramController.hpp"

#include "HardwareSensor.hpp"

#include "WashingProgramStatus.hpp"

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include "HardwareListener.hpp"

class WebInterfaceController: public RTOS::task, public HardwareListener{
public:
    WebInterfaceController( WashingProgramController* washingProgramController,
                            HardwareSensor* temperatureSensor,
                            HardwareSensor* waterLevelSensor,
                            HardwareSensor* rotationSensor,
                            HardwareSensor* washingMachineStatusSensor);
	void main() override;

	void valueChanged(HardwareSensor* sensor, unsigned char value);
	void GenerateStatusUpdate();

private:
    SocketMessage* createSocketMessageFromWashingList();

    SocketServer* socketServer = new SocketServer(8081);
    WebServer* webServer = new WebServer(80, "/www");

	WashingProgramController* washingProgramController;

	HardwareSensor* temperatureSensor;
	HardwareSensor* waterLevelSensor;
	HardwareSensor* rotationSensor;
	HardwareSensor* washingMachineStatusSensor;

	WashingProgramStatus* currentWashingProgramStatus;
    std::vector<WashingProgram*> washingPrograms;
};

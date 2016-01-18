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

	RTOS::timer sleepTimer;

    WebServer* webServer = new WebServer(8080, "www/"); // Starts the WebServer on its own thread (.detach)
    SocketServer* socketServer = new SocketServer(8081); // Starts the SocketServer on its own thread (.detach)

	WashingProgramController* washingProgramController;

	HardwareSensor* temperatureSensor;
	HardwareSensor* waterLevelSensor;
	HardwareSensor* rotationSensor;
	HardwareSensor* washingMachineStatusSensor;

	WashingProgramStatus* currentWashingProgramStatus;
    std::vector<WashingProgram*> washingPrograms;
};

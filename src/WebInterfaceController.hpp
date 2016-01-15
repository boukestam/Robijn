#pragma once

#include "pRTOS.h"

#include "SocketServer.hpp"
#include "WebServer.hpp"

#include "WashingProgramController.hpp"

#include "HardwareSensor.hpp"

#include "WashingProgramStatus.hpp"

class WebInterfaceController: public RTOS::task{
public:
	//void main() override;

private:
	SocketServer socketServer;
	WebServer webServer;

	WashingProgramController washingProgramController;

	HardwareSensor temperatureSensor;
	HardwareSensor waterLevelSensor;
	HardwareSensor rotationSensor;
	HardwareSensor washingMachineStatusSensor;

	WashingProgramStatus currentWashingProgramStatus;
};

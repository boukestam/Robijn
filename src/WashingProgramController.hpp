#pragma once

#pragma once

#include "pRTOS.h"

#include "WashingProgram.hpp"
#include "WashingProgramScheduler.hpp"

#include "WaterLevelController.hpp"
#include "RotationController.hpp"
#include "TemperatureController.hpp"

#include "Door.hpp"
#include "SignalLed.hpp"
#include "WashingMachine.hpp"

#include "HardwareSensor.hpp"

class WashingProgramController: public RTOS::task{
public:
	void main() override;
	
	void startWashingProgram(WashingProgram program);
	void stopWashingProgram();
	
private:
	WashingProgramScheduler scheduler;
	
	WaterLevelController waterLevelController;
	RotationController rotationController;
	TemperatureController temperatureController;
	
	Door door;
	SignalLed signalLed;
	WashingMachine washingMachine;
	
	HardwareSensor washingMachineStatusSensor;
};
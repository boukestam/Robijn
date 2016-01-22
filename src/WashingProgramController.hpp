#pragma once

#include <iostream>

#include "pRTOS.h"

#include "WashingProgram.hpp"
#include "WashingProgramScheduler.hpp"

#include "WaterLevelController.hpp"
#include "RotationController.hpp"
#include "TemperatureController.hpp"

#include "Door.hpp"
#include "SignalLed.hpp"
#include "WashingMachine.hpp"
#include "SoapTray.hpp"

#include "HardwareSensor.hpp"

#include "HardwareComponent.hpp"
#include "HardwareListener.hpp"



/**
 * @class WashingProgramController
 * @author Thijs Hendrickx
 * @date 15/01/16
 * @file WashingProgramController.hpp
 * @brief This class gets the goal values from current Washing Program Step and passes them to the hardware controllers.
 */
 
class WashingProgramController: public RTOS::task, public HardwareListener{
public:
	//! Main method derrived from RTOS::Task
	void main() override;
	
	//! Constructor for WashingProgramController
	WashingProgramController(
		WaterLevelController* waterLevelController,
		RotationController* rotationController,
		TemperatureController* temperatureController,
		Door* door, 
		SignalLed* signalLed, 
		WashingMachine* washingMachine,
		HardwareSensor* washingMachineStatusSensor,
		SoapTray* soapTray,
		HardwareSensor* doorSensor);
		
	//! Starts a washing program
	void startWashingProgram(WashingProgram* program);
	
	//! Stops current washing program
	void stopWashingProgram();
	
	//! Gets called if sensor detects a change in currentValue
	void valueChanged(HardwareSensor* sensor, unsigned char value);
    
    //! Returns the amount of time from the start from the scheduler
    int getTimeRunning();
    
    //! Returns the current step index from the scheduler
	int getCurrentStepIndex();
private:
	WashingProgramScheduler* scheduler;
	
	WaterLevelController* waterLevelController;
	RotationController* rotationController;
	TemperatureController* temperatureController;
	
	Door* door;
	SignalLed* signalLed;
	WashingMachine* washingMachine;
	HardwareSensor* washingMachineStatusSensor;
	SoapTray* soapTray;
	HardwareSensor* doorSensor;
	
	RTOS::flag startFlag;
	unsigned char washingMachineStatus;
	
	bool hasStarted = false;
	unsigned char doorStatus = 0x01;
};


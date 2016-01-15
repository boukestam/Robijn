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
/**
 * @brief Main method derrived from RTOS::Task
 */
	void main() override;
	
/**
 * @brief Constructor for WashingProgramController
 * @param waterLevelController Pointer to the water level controller
 * @param rotationController Pointer to the rotation controller
 * @param temperatureController Pointer to the temperature controller
 * @param door Pointer to the door
 * @param signalLed Pointer to the signal led
 * @param washingMachine Pointer to the washing machine
 * @param washingMachineStatusSensor Pointer to the washing machine status sensor
 */
	WashingProgramController(
		WaterLevelController* waterLevelController,
		RotationController* rotationController,
		TemperatureController* temperatureController,
		Door* door, 
		SignalLed* signalLed, 
		WashingMachine* washingMachine,
		HardwareSensor* washingMachineStatusSensor);
		
/**
 * @brief Starts a washing program
 * @param program The program to start
 */
	void startWashingProgram(WashingProgram program);
	
/**
 * @brief Stops current washing program
 */
	void stopWashingProgram();
	
/**
 * @brief Gets called if sensor detects a change in currentValue
 * @param sensor Which sensor called the method
 * @param value The changed value
 */
	void valueChanged(HardwareSensor* sensor, unsigned char value);
private:
	WashingProgramScheduler* scheduler;
	
	WaterLevelController* waterLevelController;
	RotationController* rotationController;
	TemperatureController* temperatureController;
	
	Door* door;
	SignalLed* signalLed;
	WashingMachine* washingMachine;
	
	HardwareSensor* washingMachineStatusSensor;
	
	unsigned char washingMachineStatus;
	RTOS::timer updateStatusSensorTimer;
};
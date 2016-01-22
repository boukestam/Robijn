#pragma once

#include "pRTOS.h"
#include "HardwareListener.hpp"
#include "HardwareSensor.hpp"

#include <vector>

/**
 * @class HardwareController
 * @author Thijs Hendrickx
 * @date 15/01/16
 * @file HardwareController.hpp
 * @brief Interface for hardware controllers. Holds the protected goalState, given by Washing Program, 
 * and currentState, given by the Hardware Sensors.
 */
 
class HardwareController: public RTOS::task, public HardwareListener{
public:
	HardwareController();

	//! Main method derrived from RTOS::task
	void main() override;
	
	//! Gets called if sensor detects a change in currentValue
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	
	//! Set the goalState with state
	void setGoalState(unsigned char state);
	
	//! Set the currentState and check if goal is reached
	void setCurrentState(unsigned char state);

	//! Sets the flag when the goal is reached
	bool signalWhenDone(RTOS::flag* flag);
	
protected:
	//! Goal state
	unsigned char goalState;
	
	//! Current state
	unsigned char currentState;

private:
	//! Flags waiting for goal to be reached
	std::vector<RTOS::flag*> waitingFlags;
};

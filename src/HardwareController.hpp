#pragma once

#include "pRTOS.h"
#include "HardwareListener.hpp"
#include "HardwareSensor.hpp"

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

/**
 * @brief Main method derrived from RTOS::task
 */
	void main() override;
	
/**
 * @brief Gets called if sensor detects a change in currentValue
 * @param sensor Which sensor called the method
 * @param value The changed value
 */
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	
/**
 * @brief Set the goalState with state
 * @param state New goalState value
 */
	void setGoalState(unsigned char state);
	
/**
 * @brief Set the currentState with state
 * @param state New currentState value
 */
	void setCurrentState(unsigned char state);
	
protected:
	unsigned char goalState;
	unsigned char currentState;
};

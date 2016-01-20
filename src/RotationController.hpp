#pragma once

#include "HardwareController.hpp"
#include "HardwareSensor.hpp"
#include "Motor.hpp"

#include <time.h>

/**
 * @class RotationController
 * @author Thijs
 * @date 15/01/16
 * @file RotationController.hpp
 * @brief This class interfaces with the Motor and handles the motor state based on the goal value. 
 */
class RotationController: public HardwareController{
public:

/**
 * @brief Constructor for RotationController
 * @param motor Pointer to the washing machine motor
 * @param rotationSensor Pointer to the rotation sensor 
 */
	RotationController(Motor* motor, HardwareSensor* rotationSensor);
	
/**
 * @brief Gets called if sensor detects a change in currentValue
 * @param sensor Which sensor called the method
 * @param value The changed value
 */
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	
/**
 * @brief Main method derrived from RTOS::Task
 */
	void main() override;

	void setRotationInterval(int interval);
	
private:
	Motor* motor;
	HardwareSensor* rotationSensor;

	time_t lastRotationSwitch;
	int rotationInterval = 0;
};

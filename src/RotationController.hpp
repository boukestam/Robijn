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

	//! Constructor for RotationController
	RotationController(Motor* motor, HardwareSensor* rotationSensor);
	
	//! Gets called if sensor detects a change in currentValue
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	
	//! Main method derrived from RTOS::Task
	void main() override;
	
	//! Set rotation interval
	void setRotationInterval(int interval);
	
private:
	//! Motor
	Motor* motor;
	
	//! Rotation sensor
	HardwareSensor* rotationSensor;
	
	//! Last time the rotation switched side (left or right)
	time_t lastRotationSwitch;
	
	//! Interval between rotation switches
	int rotationInterval = 0;
};

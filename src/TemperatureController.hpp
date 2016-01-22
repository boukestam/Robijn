#pragma once

#include "HardwareController.hpp"
#include "Heating.hpp"
#include "HardwareSensor.hpp"

/**
 * @class TemperatureController
 * @author Thijs Hendrickx
 * @date 15/01/16
 * @file TemperatureController.hpp
 * @brief This class interfaces with the Heating and handles the heating state based on the goal value.  
 */
 
class TemperatureController: public HardwareController{
public:

	//! Constructor for TemperatureController
	TemperatureController(Heating* heating, HardwareSensor* temperatureSensor);
	
	//! Gets called if sensor detects a change in currentValue
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	
	//! Main method derrived from RTOS::Task
	void main() override;
	
private:
	//! Heating
	Heating* heating;
	
	//! Temperature sensor
	HardwareSensor* temperatureSensor;
};

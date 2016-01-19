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

/**
 * @brief Constructor for TemperatureController
 * @param heating Pointer to the washing machine heating unit
 * @param temperatureSensor Pointer to the temperature sensor
 */
	TemperatureController(Heating* heating, HardwareSensor* temperatureSensor);
	
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
	
private:
	Heating* heating;
	HardwareSensor* temperatureSensor;
};
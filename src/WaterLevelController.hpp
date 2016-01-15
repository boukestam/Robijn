#pragma once

#include "HardwareController.hpp"
#include "Pump.hpp"
#include "Tap.hpp"
#include "HardwareSensor.hpp"

/**
 * @class WaterLevelController
 * @author Thijs Hendrickx
 * @date 15/01/16
 * @file WaterLevelController.hpp
 * @brief This class interfaces with the Tap and Pump and handles the pump/tap state based on the goal value. 
 */
class WaterLevelController: public HardwareController{
public:

/**
 * @brief Constructor for WaterLevelController
 * @param pump Pointer to the washing machine pump
 * @param tap Pointer to the washing machine tap
 * @param waterLevelSensor Pointer to the water level sensor
 */
	WaterLevelController(Pump* pump, Tap* tap, HardwareSensor* waterLevelSensor);
	
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
	Pump* pump;
	Tap* tap;
	HardwareSensor* waterLevelSensor;
};
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

	//! Constructor for WaterLevelController
	WaterLevelController(Pump* pump, Tap* tap, HardwareSensor* waterLevelSensor);
	
	//! Gets called if sensor detects a change in currentValue
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	
	//! Main method derrived from RTOS::Task
	void main() override;
	
private:
	Pump* pump;
	Tap* tap;
	HardwareSensor* waterLevelSensor;
};

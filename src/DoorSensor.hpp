#pragma once

#include "HardwareSensor.hpp"

/**
 * @class DoorSensor
 * @author Bouke Stam
 * @date 20/01/16
 * @file DoorSensor.hpp
 * @brief Boundary class for the door sensor
 */
 
class DoorSensor: public HardwareSensor{
public:
	//! Constructor
	DoorSensor(UARTInterface* uartInterface);
	
	//! Update sensor
	void update() override;
	
	//! Callback from uart
	void responseReceived(UARTMessage response) override;
};

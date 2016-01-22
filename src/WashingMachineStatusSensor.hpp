#pragma once

#include "HardwareSensor.hpp"

/**
 * @class WashingMachineStatusSensor
 * @author Bouke Stam
 * @date 20/01/16
 * @file WashingMachineStatusSensor.hpp
 * @brief Checks the status off the washing machine
 */

class WashingMachineStatusSensor: public HardwareSensor{
public:
	//! Constructor
	WashingMachineStatusSensor(UARTInterface* uartInterface);
	
	//! Updates the sensor
	void update() override;
	
	//! Callback from uart interface
	void responseReceived(UARTMessage response) override;
};

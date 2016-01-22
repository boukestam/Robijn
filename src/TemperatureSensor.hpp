#pragma once

#include "HardwareSensor.hpp"

/**
 * @class TemperatureSensor
 * @author Bouke Stam
 * @date 20/01/16
 * @file TemperatureSensor.hpp
 * @brief Boundary class for the Temperature Sensor in the washing machine
 */

class TemperatureSensor: public HardwareSensor{
public:
	//! Constructor for TemperatureSensor
	TemperatureSensor(UARTInterface* uartInterface);

	//! Calls an update on the currentValue for TemperatureSensor
	void update() override;

	//! Gets called if UART recieves a response directed to this sensor
	void responseReceived(UARTMessage response) override;
};

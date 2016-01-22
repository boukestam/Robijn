#pragma once

#include "HardwareSensor.hpp"

/**
 * @class RotationSensor
 * @author Bouke Stam
 * @date 20/01/16
 * @file RotationSensor.hpp
 * @brief Boundary class for the Rotation Sensor in the washing machine
 */

class RotationSensor: public HardwareSensor{
public:
	//! Constructor for RotationSensor
	RotationSensor(UARTInterface* uartInterface);

	//! Calls an update on the currentValue for TemperatureSensor
	void update() override;

	//! Gets called if UART recieves a response directed to this sensor
	void responseReceived(UARTMessage response) override;
};

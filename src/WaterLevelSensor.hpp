#pragma once

#include "HardwareSensor.hpp"

/**
 * @class WaterLevelSensor
 * @author Bouke Stam
 * @date 20/01/16
 * @file WaterLevelSensor.hpp
 * @brief Boundary class for the Water Level Sensor in the washing machine
 */

class WaterLevelSensor: public HardwareSensor{
public:
	//! Constructor for WaterLevelSensor
	WaterLevelSensor(UARTInterface* uartInterface);

	//! Calls an update on the currentValue for TemperatureSensor
	void update() override;

	//! Gets called if UART recieves a response directed to this sensor
	void responseReceived(UARTMessage response) override;
};

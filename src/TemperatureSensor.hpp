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
/**
 * @brief Constructor for TemperatureSensor
 */
	TemperatureSensor(UARTInterface* uartInterface);

/**
 * @brief Calls an update on the currentState for TemperatureSensor
 */
	void update() override;

/**
 * @brief Gets called if UART recieves a response directed to this sensor
 * @param response The message that was send by the UART
 */
	void responseReceived(UARTMessage response) override;
};

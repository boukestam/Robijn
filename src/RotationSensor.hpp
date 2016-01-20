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
/**
 * @brief Constructor for RotationSensor
 */
	RotationSensor(UARTInterface* uartInterface);

/**
 * @brief Calls an update on the currentState for RotationSensor
 */
	void update() override;

/**
 * @brief Gets called if UART recieves a response directed to this sensor
 * @param response The message that was send by the UART
 */
	void responseReceived(UARTMessage response) override;
};

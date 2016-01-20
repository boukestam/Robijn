#pragma once

#include "HardwareSensor.hpp"

/**
 * @class DoorSensor
 * @author Bouke Stam
 * @date 20/01/16
 * @file DoorSensor.hpp
 * @brief Boundary class for the Door Sensor in the washing machine
 */

class DoorSensor: public HardwareSensor{
public:
/**
 * @brief Constructor for DoorSensor
 */
	DoorSensor(UARTInterface* uartInterface);

/**
 * @brief Calls an update on the currentState for DoorSensor
 */
	void update() override;

/**
 * @brief Gets called if UART recieves a response directed to this sensor
 * @param response The message that was send by the UART
 */
	void responseReceived(UARTMessage response) override;
};

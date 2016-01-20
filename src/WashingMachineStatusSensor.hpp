#pragma once

#include "HardwareSensor.hpp"

/**
 * @class WashingMachineStatusSensor
 * @author Bouke Stam
 * @date 20/01/16
 * @file WashingMachineStatusSensor.hpp
 * @brief Boundary class for the Washing Machine Status Sensor in the washing machine
 */

class WashingMachineStatusSensor: public HardwareSensor{
public:
/**
 * @brief Constructor for WashingMachineStatusSensor
 */
	WashingMachineStatusSensor(UARTInterface* uartInterface);

/**
 * @brief Calls an update on the currentState for WashingMachineStatusSensor
 */
	void update() override;

/**
 * @brief Gets called if UART recieves a response directed to this sensor
 * @param response The message that was send by the UART
 */
	void responseReceived(UARTMessage response) override;
};

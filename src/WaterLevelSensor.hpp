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
/**
 * @brief Constructor for WaterLevelSensor
 */
	WaterLevelSensor(UARTInterface* uartInterface);

/**
 * @brief Calls an update on the currentValue for TemperatureSensor
 */
	void update() override;

/**
 * @brief Gets called if UART recieves a response directed to this sensor
 * @param response The message that was send by the UART
 */
	void responseReceived(UARTMessage response) override;
};

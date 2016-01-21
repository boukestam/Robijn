#pragma once

#include "HardwareComponent.hpp"

/**
 * @class Motor
 * @author Bouke Stam
 * @date 20/01/16
 * @file Motor.hpp
 * @brief Boundary class for the washing machine Motor
 */

class Motor: public HardwareComponent{
public:
/**
 * @brief Constructor for Motor
 */
	Motor(UARTInterface* uartInterface);

/**
 * @brief Set the RPM for the motor
 * @param rotation The RPM that the motor will be set to
 */
	void setRotation(unsigned char rotation);
};

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
	//! Constructor for Motor
	Motor(UARTInterface* uartInterface);

	//! Set the RPM for the motor
	void setRotation(unsigned char rotation);
};

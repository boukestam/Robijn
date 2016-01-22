#pragma once

#include "HardwareComponent.hpp"

/**
 * @class Pump
 * @author Bouke Stam
 * @date 20/01/16
 * @file Pump.hpp
 * @brief Boundary class for the washing machine Pump
 */

class Pump: public HardwareComponent{
public:
	//! Constructor for Pump
	Pump(UARTInterface* uartInterface);

	//! Turns the pump on, emptying water from the washing machine
	void on();

	//! Turns the pump off, stopping the emptying off water from the washing machine
	void off();
};

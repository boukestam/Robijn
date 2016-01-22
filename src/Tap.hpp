#pragma once

#include "HardwareComponent.hpp"

/**
 * @class Tap
 * @author Bouke Stam
 * @date 20/01/16
 * @file Tap.hpp
 * @brief Boundary class for the washing machine Tap
 */

class Tap: public HardwareComponent{
public:
	//! Constructor for Tap
	Tap(UARTInterface* uartInterface);

	//! Turns the tap on, allowing water to flow in
	void on();

	//! Turns the tap off, stopping the water flow
	void off();
};

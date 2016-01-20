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
/**
 * @brief Constructor for Pump
 */ 
	Pump(UARTInterface* uartInterface);

/**
 * @brief Turns the pump on, emptying water from the washing machine
 */
	void on();

/**
 * @brief Turns the pump off, stopping the emptying from the washing machine
 */
	void off();
};

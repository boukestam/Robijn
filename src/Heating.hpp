#pragma once

#include "HardwareComponent.hpp"

/**
 * @class Heating
 * @author Bouke Stam
 * @date 20/01/16
 * @file Heating.hpp
 * @brief Boundary class for the washing machine Heating unit
 */

class Heating: public HardwareComponent{
public:
/**
 * @brief Constructor for Heating
 */
	Heating(UARTInterface* uartInterface);

/**
 * @brief Turns the heating unit on
 */
	void on();

/**
 * @brief Turns the heating unit off
 */
	void off();
};

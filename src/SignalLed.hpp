#pragma once

#include "HardwareComponent.hpp"

/**
 * @class SignalLed
 * @author Bouke Stam
 * @date 20/01/16
 * @file SignalLed.hpp
 * @brief Boundary class for the Signal Led
 */
 
class SignalLed: public HardwareComponent{
public:
/**
 * @brief Constructor for SignaLed
 */
	SignalLed(UARTInterface* uartInterface);

/**
 * @brief Turns the signal led on
 */
	void on();

/**
 * @brief Turns the signal led off
 */
	void off();
};

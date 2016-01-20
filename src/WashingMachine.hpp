#pragma once

#include "HardwareComponent.hpp"

/**
 * @class WashingMachine
 * @author Bouke Stam
 * @date 20/01/16
 * @file WashingMachine.hpp
 * @brief Boundary class for the Washing Machine 
 */
 
class WashingMachine: public HardwareComponent{
public:
/**
 * @brief Constructor for WashingMachine
 */
	WashingMachine(UARTInterface* uartInterface);

/**
 * @brief Starts the washing machine
 */
	void start();

/**
 * @brief Stops the washing machine
 */
	void stop();
};

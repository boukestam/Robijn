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
	//! Constructor for WashingMachine
	WashingMachine(UARTInterface* uartInterface);

	//! Starts the washing machine
	void start();

	//! Stops the washing machine
	void stop();
};

#pragma once

#include "HardwareComponent.hpp"

/**
 * @class Door
 * @author Bouke Stam
 * @date 20/01/16
 * @file Door.hpp
 * @brief Boundary class for the washing machine Door
 */

class Door: public HardwareComponent{
public:
/**
 * @brief Constructor for Door
 */
	Door(UARTInterface* uartInterface);

/**
 * @brief Locks the door
 */
	void lock();

/**
 * @brief Unlocks the door
 */
	void unlock();
};

#pragma once

#include "HardwareComponent.hpp"

class Door: public HardwareComponent{
public:
	Door(UARTInterface* uartInterface);
	
	void lock();
	void unlock();
};

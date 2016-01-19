#pragma once

#include "HardwareComponent.hpp"

class Tap: public HardwareComponent{
public:
	Tap(UARTInterface* uartInterface);
	
	void on();
	void off();
};

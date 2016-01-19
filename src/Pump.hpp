#pragma once

#include "HardwareComponent.hpp"

class Pump: public HardwareComponent{
public:
	Pump(UARTInterface* uartInterface);
	
	void on();
	void off();
};

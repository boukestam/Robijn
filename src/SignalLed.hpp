#pragma once

#include "HardwareComponent.hpp"

class SignalLed: public HardwareComponent{
public:
	SignalLed(UARTInterface* uartInterface);
	
	void on();
	void off();
};

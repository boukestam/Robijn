#pragma once

#include "HardwareComponent.hpp"

class Heating: public HardwareComponent{
public:
	Heating(UARTInterface* uartInterface);

	void on();
	void off();
};

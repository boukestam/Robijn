#pragma once

#include "HardwareComponent.hpp"

class WashingMachine: public HardwareComponent{
public:
	WashingMachine(UARTInterface* uartInterface);
	
	void start();
	void stop();
};

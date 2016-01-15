#pragma once

#include "HardwareComponent.hpp"

class Motor: public HardwareComponent{
public:
	Motor(UARTInterface* uartInterface);
	
	void setRotation(unsigned char rotation);
};

#pragma once

#include "HardwareComponent.hpp"

class SoapTray: public HardwareComponent{
public:
	SoapTray(UARTInterface* uartInterface);
	
	void open();
	void close();
};

#pragma once

#include "HardwareSensor.hpp"

class TemperatureSensor: public HardwareSensor{
public:
	TemperatureSensor(UARTInterface* uartInterface);
	
	void update() override;
	void responseReceived(UARTMessage response) override;
};

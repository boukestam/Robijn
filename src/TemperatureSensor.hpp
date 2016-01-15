#pragma once

#include "HardwareSensor.hpp"

class TemperatureSensor: public HardwareSensor{
public:
	void update() override;
	void responseReceived(UARTMessage response) override;
	
private:
	unsigned char getTemperature();
};
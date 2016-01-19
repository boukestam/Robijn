#pragma once

#include "HardwareSensor.hpp"

class RotationSensor: public HardwareSensor{
public:
	RotationSensor(UARTInterface* uartInterface);
	
	void update() override;
	void responseReceived(UARTMessage response) override;
};

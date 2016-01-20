#pragma once

#include "HardwareSensor.hpp"

class DoorSensor: public HardwareSensor{
public:
	DoorSensor(UARTInterface* uartInterface);
	
	void update() override;
	void responseReceived(UARTMessage response) override;
};

#pragma once

#include "HardwareSensor.hpp"

class WaterLevelSensor: public HardwareSensor{
public:
	WaterLevelSensor(UARTInterface* uartInterface);
	
	void update() override;
	void responseReceived(UARTMessage response) override;
};

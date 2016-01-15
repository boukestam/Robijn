#pragma once

#include "HardwareSensor.hpp"

class WaterLevelSensor: public HardwareSensor{
public:
	void update() override;
	void responseReceived(UARTMessage response) override;
	
private:
	unsigned char getWaterLevel();
};
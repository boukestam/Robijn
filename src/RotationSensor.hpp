#pragma once

#include "HardwareSensor.hpp"

class RotationSensor: public HardwareSensor{
public:
	void update() override;
	void responseReceived(UARTMessage response) override;
	
private:
	unsigned char getRotation();
};
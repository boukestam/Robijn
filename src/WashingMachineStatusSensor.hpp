#pragma once

#include "HardwareSensor.hpp"

class WashingMachineStatusSensor: public HardwareSensor{
public:
	void update() override;
	void responseReceived(UARTMessage response) override;
	
private:
	void getStatus();
};
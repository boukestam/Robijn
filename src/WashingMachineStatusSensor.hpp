#pragma once

#include "HardwareSensor.hpp"

class WashingMachineStatusSensor: public HardwareSensor{
public:
	WashingMachineStatusSensor(UARTInterface* uartInterface);
	
	void update() override;
	void responseReceived(UARTMessage response) override;
};

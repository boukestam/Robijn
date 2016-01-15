#pragma once

#include "HardwareComponent.hpp"

class WashingMachine: public HardwareComponent{
public:
	void start();
	void stop();
	
	void responseReceived(UARTMessage response) override;
};
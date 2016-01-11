#pragma once

#include "pRTOS.h"

#include "HardwareListener.hpp"
#include "HardwareSensor.hpp"

class HardwareController: public RTOS::task, public HardwareListener{
public:
	void main() override;
	
	void valueChanged(HardwareSensor sensor, unsigned char value);
	
	void setGoalState(unsigned char state);
	
private:
	unsigned char goalState;
};
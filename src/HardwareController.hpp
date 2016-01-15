#pragma once

#include "pRTOS.h"
#include "HardwareListener.hpp"
#include "HardwareSensor.hpp"

class HardwareController: public RTOS::task, public HardwareListener{
public:
	void main() override;
	
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	
	void setGoalState(unsigned char state);
	
	void setCurrentState(unsigned char state);
	
protected:
	unsigned char goalState;
	unsigned char currentState;
};
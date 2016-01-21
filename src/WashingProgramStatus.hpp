#pragma once

#include "SocketMessage.hpp"

class WashingProgramStatus{
public:
	int rotationSpeed = 0;
	int waterLevel = 0;
	int temperature = 0;

	int currentStep = 0;

	int totalSteps = 0;
	int totalSteptime = 0;
    
    int duration = 0;

	int status = 0x02;

	SocketMessage* toSocketMessage();
};

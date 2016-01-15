#pragma once

#include "SocketMessage.hpp"
#include "WashingMachineStatus.hpp"

class WashingProgramStatus{
public:
	int rotationSpeed = 0;
	int waterLevel = 0;
	int temperature = 0;

	int timeLeft = 0;
	int stepTimeLeft = 0;
	int currentStep = 0;

	int totalSteps = 0;
	int totalSteptime = 0;

	WashingMachineStatus status;

	SocketMessage* toSocketMessage();
};

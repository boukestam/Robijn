#pragma once

#include "SocketMessage.hpp"
#include "WashingMachineStatus.hpp"

class WashingProgramStatus{
public:
	int rotationSpeed;
	int waterLevel;
	int temperature;
	
	int timeLeft;
	int stepTimeLeft;
	
	WashingMachineStatus status;
	
	SocketMessage toSocketMessage();
};
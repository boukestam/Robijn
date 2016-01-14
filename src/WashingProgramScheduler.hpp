#pragma once

#include <time.h>

#include "WashingProgram.hpp"
#include "WashingProgramStep.hpp"

class WashingProgramScheduler{
public:
	void startWashingProgram(WashingProgram washingProgram);
	
	WashingProgramStep getCurrentStep();
	
	bool isRunning();
	
	void update();
	
private:
	time_t startTime;
	time_t stepStartTime;
	
	int currentStepIndex;
	WashingProgram currentWashingProgram;
	
	bool running;
};
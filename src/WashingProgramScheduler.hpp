#pragma once

#include <time.h>
#include <iostream>
#include "pRTOS.h"

#include "WashingProgram.hpp"
#include "WashingProgramStep.hpp"
class WashingProgramController;

class WashingProgramScheduler{
public:	
	void start(WashingProgram washingProgram);
	void pause();
	void unpause();
	void stop();
	
	WashingProgramStep getCurrentStep();
	
	bool isRunning();
	bool isPaused();
	
	void update();
	
private:
	WashingProgram currentWashingProgram;
	
	time_t stepStartTime, stepStopTime;
	time_t programStartTime;

	unsigned int currentStepIndex;
	
	bool running;
	bool paused;
};

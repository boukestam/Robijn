#pragma once

#include <time.h>
#include <chrono>
#include <iostream>
#include "pRTOS.h"

#include "WashingProgram.hpp"
#include "WashingProgramStep.hpp"
class WashingProgramController;

class WashingProgramScheduler{
public:	
	void startWashingProgram(WashingProgram* washingProgram);
	
	WashingProgramStep getCurrentStep();
	
	bool isRunning();
	
	void update();
	
private:
	WashingProgram* currentWashingProgram;
	
	std::chrono::time_point<std::chrono::system_clock> timePoint1, timePoint2, timePoint3;
	time_t stepStartTime, stepStopTime;
	time_t programStartTime;

	int stepDuration;
	unsigned int currentStepIndex;
	
	bool running;
};

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
	
	
	//WashingProgramScheduler(WashingProgramController * wpc);
	
	void startWashingProgram(WashingProgram washingProgram);
	
	WashingProgramStep getCurrentStep();
	
	bool isRunning();
	
	void update();
	
private:
	//clock will be put in start and end
	std::chrono::time_point<std::chrono::system_clock> timePoint1, timePoint2, timePoint3;

	//to show the start and end will be converted to type time_t	
	time_t stepStartTime, stepStopTime;
	time_t programStartTime;
	//RTOS::timer schedularTimer;
	int stepDuration;
	unsigned int currentStepIndex;
	WashingProgram currentWashingProgram;
	
	bool running;
};
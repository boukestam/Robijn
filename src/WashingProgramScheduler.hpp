#pragma once

#include <time.h>
#include <chrono>
#include <iostream>
#include <thread>

#include "WashingProgram.hpp"
#include "WashingProgramStep.hpp"

class WashingProgramScheduler{
public:
	void startWashingProgram(WashingProgram washingProgram);
	
	WashingProgramStep getCurrentStep();
	
	bool isRunning();
	
	void update();
	
private:
	std::chrono::time_point<std::chrono::system_clock> start;

	time_t startTime;
	time_t stepStartTime, stepStopTime;
	

	int currentStepIndex;
	WashingProgram currentWashingProgram;
	
	bool running;
};
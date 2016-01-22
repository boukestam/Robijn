#pragma once
#include <time.h>
#include <iostream>
#include "pRTOS.h"

#include "WashingProgram.hpp"
#include "WashingProgramStep.hpp"

/**
 * @class WashingProgramScheduler
 * @author Waila Woe 
 * @date 21/01/16
 * @file WashingProgramScheduler.hpp
 * @brief A scheduler that keeps track of time whenever the washing program has 
 * been started by calling WashingProgramScheduler::startWashingProgram().
 */
 
class WashingProgramScheduler{
public:	
	WashingProgramScheduler(WashingProgram* washingProgram);

	//! Starts the washing program
	void start();
	
	//! Stops the current washing program
	void stop();
	
	//! Pauses the current washing program
	void pause();
	
	//! Unpauses the current washing program
	void unpause();
	
	//! Retrieve the current step of the washing program.
	WashingProgramStep getCurrentStep();
	
	//! Checks the washing program wether it is in a running state
	bool isRunning();
	
	//! Checks the washing program wether it is in a paused state
	bool isPaused();
	
	//! Updates the washing program scheduler by keeping track of the elapse time since
	//! WashingProgram has been started. update() also checkes wether a step has been finished 
	//! so it can jump to next step or finish the program
	void update();
    
	//! The time elapsed from start
    int getElapsedTime();
	
	//! The current step index
	int getCurrentStepIndex();
	
private:
	WashingProgram* currentWashingProgram;
	
	time_t stepStartTime = 0;
	time_t stepStopTime = 0;
	time_t programStartTime = 0;
	time_t beforePauseTime = 0;

	unsigned int currentStepIndex = 0;
	
	bool running = false;
	bool paused = false;
};

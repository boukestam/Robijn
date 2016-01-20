#pragma once
#include <time.h>
#include <iostream>
#include "pRTOS.h"

#include "WashingProgram.hpp"
#include "WashingProgramStep.hpp"

//! A scheduler that keeps track of time whenever the washing program has been started by calling WashingProgramScheduler::startWashingProgram().
 /*! 
  \class WashingProgramScheduler
  \file WashingProgramScheduler.hpp
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
	
	//!Retrieve the current step of the washing program. 
	/*!
	  \return returns the current step of type WashingProgramStep
	*/
	WashingProgramStep getCurrentStep();
	
	//!Checks the washing program wether it is in a running state
	/*!
	 \return returns the value of running (0 for "not running" and 1 for "is running")
	*/
	bool isRunning();
	bool isPaused();
	
	//!Updates the washing program scheduler
	/*!Update will calculate the elapse time since the program and step has been started. 
	 A step is finished then the elapse time gets higher then the duration of the step.		
	 When that happends the currentStepIndex will be incremented by one which only can happen, 
	 whenever currentStepIndex is smaller than the total size of steps							
	*/
	 
	void update();
    
    /**
     * @brief The time elapsed in this step
     */
    int GetElapsedStepTime();
	
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

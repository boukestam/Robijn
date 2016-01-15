#pragma once
#include <time.h>
#include <chrono>
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
	void startWashingProgram(WashingProgram* washingProgram);

	//! Starts the washing program
	/*!
	 Save the current time of system and also retrieve the duration of the first step of the washing program.
	 Calling this function will set the currentStepIndex to 0
	 \param washingProgram
	*/
	void startWashingProgram(WashingProgram washingProgram);
	
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
	
	//!Updates the washing program scheduler
	/*!Update will calculate the elapse time since the program and step has been started. 
	 A step is finished then the elapse time gets higher then the duration of the step.		
	 When that happends the currentStepIndex will be incremented by one which only can happen, 
	 whenever currentStepIndex is smaller than the total size of steps							
	*/
	 
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

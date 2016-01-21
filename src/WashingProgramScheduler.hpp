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

	/**
	 * @brief Starts the washing program
	 */
	void start();
	
	/**
	 * @brief Stops the current washing program
	 */
	void stop();
	
	/**
	 * @brief Pauses the current washing program
	 */
	void pause();
	
	/**
	 * @brief Unpauses the current washing program
	 */
	void unpause();
	
	/**
	 * @brief Retrieve the current step of the washing program. 
	 * @return The step of WashingProgramStep which is currently running in
	 */
	WashingProgramStep getCurrentStep();
	
	/**
	 * @brief Checks the washing program wether it is in a running state
	 * @return 1 for "running" and 0 for "is not running"
	 */
	bool isRunning();
	
	/**
	 * @brief Checks the washing program wether it is in a paused state
	 * @return 1 for "running" and 0 for "is not running"
	 */
	bool isPaused();
	
	/**
	* @brief Updates the washing program scheduler by keeping track of the elapse time since
	* WashingProgram has been started. update() also checkes wether a step has been finished 
	* so it can jump to next step or finish the program
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

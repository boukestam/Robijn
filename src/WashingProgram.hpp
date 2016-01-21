#pragma once

#include <vector>
#include <iostream>
#include "WashingProgramStep.hpp"

/**
 * @class WashingProgram
 * @author Waila Woe
 * @date 15/01/16
 * @file WashingProgram.hpp
 * @brief A washing program with steps which is able to store values like rotationspeed, waterLevel, temperature and the duration a step.
 */
class WashingProgram{
public:
	
	/**
	 * @brief Calculates the duration of all steps.
	 * @return int::total which contains the total duration of steps
	 */
	int getTotalDuration();


	std::string dicription;
	
	/**
	 * @brief Retrieves the step of the given index
	 * @param index An integer of the step
	 * @return The WashingProgramStep of given index
	 */
	WashingProgramStep getStep(unsigned int index);
	
	/**
	 * @brief  Retrieves size of the step 
	 * @return Number of the total size of the vector steps
	 */
	size_t getStepSize();
	
	/**
	 * @brief Retrieves the given step and adds that step by pushing it to the vector:steps
	 * @param step Contains data of the given step
	 */
	void addStep(WashingProgramStep step);
private:
	std::vector<WashingProgramStep> steps;	
};

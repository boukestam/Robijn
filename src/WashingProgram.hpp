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
	
	//! Calculates the duration of all steps.
	int getTotalDuration();


	std::string dicription;
	
	//! Retrieves the step of the given index
	WashingProgramStep getStep(unsigned int index);
	
	//! Retrieves size of the step
	size_t getStepSize();
	
	//! Retrieves the given step and adds that step by pushing it to the vector:steps
	void addStep(WashingProgramStep step);
private:
	std::vector<WashingProgramStep> steps;	
};

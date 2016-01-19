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
	 * @brief returns the total duration of all steps combined
	 * @return 
	 */
	int getTotalDuration();


	std::string dicription;
	
	/**
	 * @brief returns step of the given index
	 * @param index
	 * @return 
	 */

	WashingProgramStep getStep(unsigned int index);
	
	/**
	 * @brief returns the size of the vector steps
	 * @return 
	 */
	size_t getStepSize();
	
	/**
	 * @brief retrieves the given step and adds that step by pushing it to the vector:steps
	 * @param step
	 */
	void addStep(WashingProgramStep step);
private:
	std::vector<WashingProgramStep> steps;	
};

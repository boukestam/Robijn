#pragma once

#include <vector>
#include <iostream>
#include "WashingProgramStep.hpp"

class WashingProgram{
public:
	int getTotalDuration();
	WashingProgramStep getStep(unsigned int index);
	size_t getStepSize();
	void addStep(WashingProgramStep step);
	
private:
	std::vector<WashingProgramStep> steps;	
};

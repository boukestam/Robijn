#pragma once

#include <vector>
#include <iostream>
#include "WashingProgramStep.hpp"

class WashingProgram{
public:
	int getTotalDuration();
	std::string dicription;
	WashingProgramStep getStep(unsigned int index);
	size_t getStepSize();
	void addStep(WashingProgramStep step);
private:
	std::vector<WashingProgramStep> steps;	
};

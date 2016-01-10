#pragma once

#include <vector>

#include "WashingProgramStep.hpp"

class WashingProgram{
public:
	int getTotalDuration();
	WashingProgramStep getStep(int index);
	
private:
	std::vector<WashingProgramStep> steps;
};

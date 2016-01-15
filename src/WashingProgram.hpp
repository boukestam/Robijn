#pragma once

#include <vector>

#include "WashingProgramStep.hpp"

class WashingProgram{
public:
	int getTotalDuration();
	int getTotalSteps();
	std::string dicription;
	void addStep(WashingProgramStep step);
	WashingProgramStep getStep(int index);

private:
	std::vector<WashingProgramStep> steps;
};

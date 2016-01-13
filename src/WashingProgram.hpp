#pragma once

#include <vector>
#include <iostream>
#include "WashingProgramStep.hpp"

class WashingProgram{
public:
	int getTotalDuration();
	WashingProgramStep getStep(int index);
	void addStep(WashingProgramStep step);
	
private:
	std::vector<WashingProgramStep> steps;	
};

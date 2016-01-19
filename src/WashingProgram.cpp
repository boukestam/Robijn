#include "WashingProgram.hpp"

int WashingProgram::getTotalDuration (){
	int total;	

	for(unsigned int i = 0; i <steps.size(); i++){
		total = total + steps[i].duration;	
	}

	return total;
}

WashingProgramStep WashingProgram::getStep(unsigned int index){	
	if(index >= 0 && index < steps.size()){
		return steps[index];
	}

	return WashingProgramStep();
}

size_t WashingProgram::getStepSize(){
	return steps.size();
}

void WashingProgram::addStep(WashingProgramStep wPS){	
	steps.push_back(wPS);
}

#include "WashingProgram.hpp"

int WashingProgram::getTotalDuration (){
	int total;	
	unsigned int i;
	for(i = 0; i <steps.size(); i++){
		total = total + steps[i].duration;	
	}
	std::cout << "The total duration of the washing program is: " << total << "seconds, with " << i << "steps" << std::endl;
	return total;
}

WashingProgramStep WashingProgram::getStep(int index){	
	std::cout << "returning step: " << index << std::endl;
	return steps[index];
}

size_t WashingProgram::getStepSize(){
	return steps.size();
}

void WashingProgram::addStep(WashingProgramStep wPS){
	steps.push_back(wPS);
}
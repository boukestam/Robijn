#include "WashingProgram.hpp"

int WashingProgram::getTotalDuration (){
	int total;	
	for(unsigned int i = 0; i <steps.size(); i++){
		total = total + steps[i].duration;	
	}
	std::cout << "This washing program has  " << steps.size() 
	<< " steps and will take in total" << total << " seconds" << std::endl;	
	return total;
}

WashingProgramStep WashingProgram::getStep(unsigned int index){	
	try{
		return steps[index];	
		std::cout << "returning step: " << index << std::endl;
	}
	catch(int& e){
		std::cout << "ERROR " << e << ", the given index is probably too high" << std::endl;		
	}	
}

size_t WashingProgram::getStepSize(){
	std::cout << "the current step size is: " << steps.size() << std::endl;
	return steps.size();
}

void WashingProgram::addStep(WashingProgramStep wPS){	
	std::cout << "step size has increased from " << steps.size();
	steps.push_back(wPS);
	std::cout << "to" << steps.size() << std::endl;;	
}

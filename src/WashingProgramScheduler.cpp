#include "WashingProgramScheduler.hpp"

void WashingProgramScheduler::startWashingProgram(WashingProgram program){	
	running = 1;
	currentStepIndex = 0;
	stepDuration = currentWashingProgram.getStep(currentStepIndex).duration;
	// get current time of the system
	timePoint1 = std::chrono::system_clock::now();		
	timePoint3 = std::chrono::system_clock::now();		
	// convert timePoint to ProgramStartTime of the type time_t to enable to print its time
	programStartTime = std::chrono::system_clock::to_time_t(timePoint1);
	std::cout << "Started washing program at" << std::ctime(&programStartTime);	
}

WashingProgramStep WashingProgramScheduler::getCurrentStep(){
	std::cout << "returning step: " << currentStepIndex << std::endl;
	return currentWashingProgram.getStep(currentStepIndex);
}

bool WashingProgramScheduler::isRunning(){
	if(running){
		std::cout << "WashingProgram is currently still running";
	}
	else{
		std::cout << "WashingProgram is currently not running";
	}
	return running;
}

void WashingProgramScheduler::update(){		
	timePoint2 = std::chrono::system_clock::now();		
	//check the difference.
	std::chrono::duration<double> elapsed_seconds = timePoint2-timePoint3;			
	std::cout << "time passed: " << elapsed_seconds.count() << "seconds";					
	
	if(elapsed_seconds.count() > stepDuration) {
		if(currentStepIndex > currentWashingProgram.getStepSize()){
			std::cout << "Step: " << currentStepIndex << "has finished/nMoving to step: " 
			<< currentStepIndex++ << std::endl;
			timePoint3 = std::chrono::system_clock::now();		
		}
		else{
			running = 0;
		}
	}
	else{				
		stepDuration = currentWashingProgram.getStep(currentStepIndex).duration;
	}
}
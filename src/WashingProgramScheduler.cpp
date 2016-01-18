#include "WashingProgramScheduler.hpp"

WashingProgramScheduler::WashingProgramScheduler(WashingProgram* washingProgram):
	currentWashingProgram(washingProgram)
{}

void WashingProgramScheduler::start(){	
	running = 1;
	currentStepIndex = 0;
	
	// get current time of the system
	time(&programStartTime);
	time(&stepStartTime);
	
	std::cout << "Started washing program at" << std::ctime(&programStartTime);	
}

void WashingProgramScheduler::stop(){
	running = false;
}

WashingProgramStep WashingProgramScheduler::getCurrentStep(){
	std::cout << "returning step: " << currentStepIndex << std::endl;
	return currentWashingProgram->getStep(currentStepIndex);
}

bool WashingProgramScheduler::isRunning(){
	return running;
}

bool WashingProgramScheduler::isPaused(){
	return paused;
}

void WashingProgramScheduler::pause(){
	paused = true;
}

void WashingProgramScheduler::unpause(){
	paused = false;
}

void WashingProgramScheduler::update(){	
	if(running && !paused){	
		time_t now;
		time(&now);
				
		//check the difference.
		time_t elapsedSeconds = now - stepStartTime;			
		std::cout << "time passed: " << elapsedSeconds << "seconds";					
	
		if(elapsedSeconds >= currentWashingProgram->getStep(currentStepIndex).duration) {
			if(currentStepIndex >= currentWashingProgram->getStepSize() - 1){
				currentStepIndex++;
				
				std::cout << "Step: " << currentStepIndex - 1 << "has finished/nMoving to step: " 
				<< currentStepIndex << std::endl;
				
				time(&stepStartTime);	
			}else{
				running = false;
			}
		}
	}
}

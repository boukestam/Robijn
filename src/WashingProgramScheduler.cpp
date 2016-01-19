#include "WashingProgramScheduler.hpp"

WashingProgramScheduler::WashingProgramScheduler(WashingProgram* washingProgram):
	currentWashingProgram(washingProgram)
{}

void WashingProgramScheduler::start(){	
	running = true;
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

		std::cout << "Now: " << now << std::endl;
		std::cout << "Step start: " << stepStartTime << std::endl;

		//check the difference
		int elapsedSeconds = now - stepStartTime;

		std::cout << "Did the substraction" << std::endl;

		std::cout << "Elapsed: " << elapsedSeconds << std::endl;

		std::cout << "Step time: " << currentWashingProgram->getStep(currentStepIndex).duration << std::endl; 

		if(elapsedSeconds >= currentWashingProgram->getStep(currentStepIndex).duration){
			if(currentStepIndex >= currentWashingProgram->getStepSize() - 1){
				currentStepIndex++;

				std::cout << "Step: " << currentStepIndex - 1 << "has finished/nMoving to step: " << currentStepIndex << std::endl;

				time(&stepStartTime);
			}else{
				running = false;
			}
		}

		std::cout << "End of update" << std::endl;
	}
}

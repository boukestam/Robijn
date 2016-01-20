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
}

void WashingProgramScheduler::stop(){
	running = false;
}

WashingProgramStep WashingProgramScheduler::getCurrentStep(){
	return currentWashingProgram->getStep(currentStepIndex);
}

bool WashingProgramScheduler::isRunning(){
	return running;
}

bool WashingProgramScheduler::isPaused(){
	return paused;
}

void WashingProgramScheduler::pause(){
	time(&beforePauseTime);
	paused = true;
}

void WashingProgramScheduler::unpause(){
	time_t afterPauseTime;
	time(&afterPauseTime);

	int pauseDuration = afterPauseTime - beforePauseTime;
	stepStartTime += pauseDuration;

	paused = false;
}

void WashingProgramScheduler::update(){	
	if(running && !paused){	
		time_t now;
		time(&now);

		//check the difference
		int elapsedSeconds = now - stepStartTime;

		if(elapsedSeconds >= currentWashingProgram->getStep(currentStepIndex).duration){
			if(currentStepIndex < currentWashingProgram->getStepSize() - 1){
				currentStepIndex++;

				std::cout << "Step: " << currentStepIndex - 1 << "has finished/nMoving to step: " << currentStepIndex << std::endl;

				time(&stepStartTime);
			}else{
				std::cout << "Scheduler done" << std::endl;
				running = false;
			}
		}
	}
}

int WashingProgramScheduler::GetElapsedStepTime(){
    time_t now;
    time(&now);

	int pauseDuration = now - beforePauseTime;
    
    int elapsedSeconds = now - stepStartTime + pauseDuration;
    
    return elapsedSeconds;
}

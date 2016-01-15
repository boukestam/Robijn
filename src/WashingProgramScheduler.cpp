#include "WashingProgramScheduler.hpp"

/*
	WashingProgramScheduler::WashingProgramScheduler(WashingProgramController * wpc):	
	schedularTimer(wpc, "schedularTimer");	
	{
		//t1.set(1000 MS);
	}
	
*/
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
/*	
	void WashingProgramScheduler::stopWashingProgram(WashingProgram program){		
		stepStopTime = clock();		
		running = 0;	
		 * }
*/
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

	//missing: sleep from RTOS
	
	timePoint2 = std::chrono::system_clock::now();		
	std::chrono::duration<double> elapsed_seconds = timePoint2-timePoint3;			
	std::cout << "time passed: " << elapsed_seconds.count() << "seconds";					
	
	if(elapsed_seconds.count() > stepDuration) {
		if(currentStepIndex > currentWashingProgram.getStepSize()){
			std::cout<< "Step: " << currentStepIndex << "has finished/nMoving to step: " << currentStepIndex++ << std::endl;
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
#include "WashingProgramScheduler.hpp"


	void WashingProgramScheduler::startWashingProgram(WashingProgram program){
		start = std::chrono::system_clock::now();			
		startTime = std::chrono::system_clock::to_time_t(start);
		stepStartTime = std::chrono::system_clock::to_time_t(start);

		running = 1;
		
		std::cout << "Started washing program at" << std::ctime(&startTime);
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
		for(;;){
			if(running){
				end = std::chrono::system_clock::now();		
				stepStopTime = std::chrono::system_clock::to_time_t(end);
				std::chrono::duration<double> elapsed_seconds = end-start;
				
				std::cout << "time passed: " << elapsed_seconds.count() << "seconds";
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			else{
				break;
			}
		}
	}	
	/*
	time_t startTime;
	time_t stepStartTime;
	
	int currentStepIndex;
	WashingProgram currentWashingProgram;
	
	bool running;
	*/
	

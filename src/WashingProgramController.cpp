#include "WashingProgramController.hpp"

WashingProgramController::WashingProgramController(
	WaterLevelController* waterLevelController,
	RotationController* rotationController,
	TemperatureController* temperatureController,
	Door* door, 
	SignalLed* signalLed, 
	WashingMachine* washingMachine,
	HardwareSensor* washingMachineStatusSensor):
	
	RTOS::task(2, "washingProgramController"),
	waterLevelController(waterLevelController),
	rotationController(rotationController),
	temperatureController(temperatureController),
	door(door),
	signalLed(signalLed),
	washingMachine(washingMachine),
	washingMachineStatusSensor(washingMachineStatusSensor),
	updateStatusSensorTimer(this, "updateTimer"),
	startFlag(this, "startFlag")
{}


void WashingProgramController::startWashingProgram(WashingProgram* program){
	if(!hasStarted){
		scheduler = new WashingProgramScheduler(program);

		startFlag.set();

		std::cout << "Set start flag" << std::endl;
	}
}

void WashingProgramController::stopWashingProgram(){
	if(hasStarted){
		scheduler->stop();
	}
}

void WashingProgramController::valueChanged(HardwareSensor* sensor, unsigned char value){
	std::cout << "New sensor value: " << (int)value << std::endl;

	if(sensor == washingMachineStatusSensor){
		std::cout << "Set sensor value" << std::endl;
		washingMachineStatus = value;
	}
}

void WashingProgramController::main(){
	RTOS::timer washingProgramTimer(this, "stepTimer");
	RTOS::flag stateReachedFlag(this, "stateReachedFlag");

	while(true){
		wait(startFlag);

		std::cout << "Done waiting for flag" << std::endl;
		
		hasStarted = true;
	
		door->lock();
		washingMachine->start();
	
		scheduler->start();
		
		bool startedRunning = false;
	
		while(true){
			std::cout << "Start loop" << std::endl;

			if(washingMachineStatus == RUNNING){
				std::cout << "Status: RUNNING" << std::endl;

				if(!startedRunning){
					startedRunning = true;
				}
				
				if(scheduler->isRunning()){
					std::cout << "Scheduler: RUNNING" << std::endl;

					if(scheduler->isPaused()){
						scheduler->unpause();
					}
					
					WashingProgramStep currentStep = scheduler->getCurrentStep();
				
					waterLevelController->setGoalState(currentStep.waterLevel);
					temperatureController->setGoalState(currentStep.temperature);
					rotationController->setGoalState(currentStep.rotationSpeed / 25);
				}
				
				scheduler->update();
			}else if(washingMachineStatus == FAILED){
				std::cout << "Status: FAILED" << std::endl;

				scheduler->pause();
			}else{
				std::cout << "Status: ELSE" << std::endl;
				if(startedRunning){
					break;
				}
			}
			
			washingMachineStatusSensor->update();
			
			std::cout << "Set timer" << std::endl;

			washingProgramTimer.set(1000 MS);
			wait(washingProgramTimer);

			std::cout << "Timer done" << std::endl;
		}

		rotationController->setGoalState(0);

		rotationController->signalWhenDone(&stateReachedFlag);
		wait(stateReachedFlag);

		waterLevelController->setGoalState(0);

		waterLevelController->signalWhenDone(&stateReachedFlag);
		wait(stateReachedFlag);

		temperatureController->setGoalState(20);

		washingMachine->stop();
		door->unlock();
		
		delete scheduler;
		
		hasStarted = false;
		
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Stopped washing program" << std::endl;
		std::cout << "-------------------------------------" << std::endl;
	}
}

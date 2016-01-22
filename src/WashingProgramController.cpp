#include <iostream>
#include "WashingProgramController.hpp"

WashingProgramController::WashingProgramController(
	WaterLevelController* waterLevelController,
	RotationController* rotationController,
	TemperatureController* temperatureController,
	Door* door, 
	SignalLed* signalLed, 
	WashingMachine* washingMachine,
	HardwareSensor* washingMachineStatusSensor,
	SoapTray* soapTray,
	HardwareSensor* doorSensor):
	
	RTOS::task(2, "washingProgramController"),
	waterLevelController(waterLevelController),
	rotationController(rotationController),
	temperatureController(temperatureController),
	door(door),
	signalLed(signalLed),
	washingMachine(washingMachine),
	washingMachineStatusSensor(washingMachineStatusSensor),
	soapTray(soapTray),
	doorSensor(doorSensor),
	startFlag(this, "startFlag")
{}


void WashingProgramController::startWashingProgram(WashingProgram* program){
	if(!hasStarted){
		scheduler = new WashingProgramScheduler(program);

		startFlag.set();
	}
}

void WashingProgramController::stopWashingProgram(){
	if(hasStarted){
		scheduler->stop();
	}
}

void WashingProgramController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == washingMachineStatusSensor){
		washingMachineStatus = value;
	}else if(sensor == doorSensor){
		doorStatus = value;
	}
}

void WashingProgramController::main(){
	RTOS::timer washingProgramTimer(this, "stepTimer");
	RTOS::flag stateReachedFlag(this, "stateReachedFlag");

	RTOS::timer doorTimer(this, "doorTimer");

	while(true){
		wait(startFlag);

		std::cout << "Started washing program" << std::endl;

		std::cout << "Waiting for door to close" << std::endl;

		while(doorStatus == OPENED){
			doorSensor->update();

			doorTimer.set(500 MS);
			wait(doorTimer);
		}
		
		std::cout << "Closed door" << std::endl;
		
		washingMachine->start();
		
		std::cout << "Started washing machine" << std::endl;
		
		while(doorStatus != LOCKED){
			door->lock();
			doorSensor->update();
			
			doorTimer.set(500 MS);
			wait(doorTimer);
		}

		std::cout << "Locked door" << std::endl;

		soapTray->open();
		
		std::cout << "Opened soap tray" << std::endl;

		scheduler->start();

		hasStarted = true;

		bool startedRunning = false;

		WashingProgramStep step;

		while(true){
			if(washingMachineStatus == RUNNING){
				scheduler->update();

				if(!startedRunning){
					startedRunning = true;
				}

				if(scheduler->isRunning()){
					WashingProgramStep currentStep = scheduler->getCurrentStep();

					if(currentStep != step){
						scheduler->pause();
						
						temperatureController->setGoalState(currentStep.temperature);
						rotationController->setGoalState(0);

						waterLevelController->setGoalState(currentStep.waterLevel);
						
						std::cout << "Starting step: waiting for water level to reach " << (int)currentStep.waterLevel << "%" << std::endl;

						if(waterLevelController->signalWhenDone(&stateReachedFlag)){
							wait(stateReachedFlag);
						}
						
						std::cout << "Reached water level" << std::endl;

						temperatureController->setGoalState(currentStep.temperature);

						rotationController->setRotationInterval(currentStep.rotationInterval);
						rotationController->setGoalState(currentStep.rotationSpeed / 25);

						step = currentStep;

						scheduler->unpause();
					}
				}else{
					std::cout << "Washing program finished" << std::endl;
					break;
				}
			}else if(washingMachineStatus == FAILED){
				if(!scheduler->isPaused()){
					scheduler->pause();
					std::cout << "Status failed: paused washing program" << std::endl;
				}
			}else if(washingMachineStatus == STOPPED){
				if(startedRunning){
					scheduler->unpause();
					washingMachine->start();
					std::cout << "Status running: resumed washing program" << std::endl;
				}
			}else if(washingMachineStatus == HALTED){
				std::cout << "Status halted: restart washing machine" << std::endl;
			}

			washingProgramTimer.set(1000 MS);
			wait(washingProgramTimer);
		}
		
		hasStarted = false;
		
		scheduler->stop();

		std::cout << "Stopping washing program..." << std::endl;

		soapTray->close();

		rotationController->setGoalState(0);

		std::cout << "Waiting for motor to stop" << std::endl;

		if(rotationController->signalWhenDone(&stateReachedFlag)){
			wait(stateReachedFlag);
		}

		std::cout << "Motor stopped" << std::endl;

		std::cout << "Waiting for water to drain" << std::endl;

		waterLevelController->setGoalState(0);

		if(waterLevelController->signalWhenDone(&stateReachedFlag)){
			wait(stateReachedFlag);
		}

		std::cout << "Water drained" << std::endl;

		temperatureController->setGoalState(20);
		
		while(doorStatus == LOCKED){
			door->unlock();
			doorSensor->update();
			
			doorTimer.set(500 MS);
			wait(doorTimer);
		}

		std::cout << "Door unlocked" << std::endl;
		
		washingMachine->stop();
		
		std::cout << "Washing machine stopped" << std::endl;
		
		std::cout << "Stopped washing program" << std::endl;
	}
}

int WashingProgramController::getTimeRunning(){
	if(hasStarted){
		return scheduler->getElapsedTime();
	}else{
		return 0;
	}
    
}

int WashingProgramController::getCurrentStepIndex(){
	if(hasStarted){
		return scheduler->getCurrentStepIndex();
	}else{
		return 0;
	}
}

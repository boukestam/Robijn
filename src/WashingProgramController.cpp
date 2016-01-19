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
		doorClosed = value != 0x01;
	}
}

void WashingProgramController::main(){
	RTOS::timer washingProgramTimer(this, "stepTimer");
	RTOS::flag stateReachedFlag(this, "stateReachedFlag");

	while(true){
		wait(startFlag);

		std::cout << "Started washing program" << std::endl;
		
		hasStarted = true;
		
		std::cout << "Waiting for door to close" << std::endl;
		
		while(!doorClosed){
			doorSensor->update();
			
			washingProgramTimer.set(100 MS);
			wait(washingProgramTimer);
		}
	
		door->lock();
		
		washingMachine->start();
		
		soapTray->open();
	
		scheduler->start();
		
		bool startedRunning = false;
	
		while(true){
			if(washingMachineStatus == RUNNING){
				if(!startedRunning){
					startedRunning = true;
				}
				
				if(scheduler->isRunning()){
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
				scheduler->pause();
			}else{
				if(startedRunning){
					break;
				}
			}
			
			washingMachineStatusSensor->update();

			washingProgramTimer.set(1000 MS);
			wait(washingProgramTimer);
		}
		
		soapTray->close();

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
		
		std::cout << "Stopped washing program" << std::endl;
	}
}

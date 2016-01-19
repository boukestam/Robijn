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
	startFlag(this, "startFlag"),
	soapTray(soapTray)
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
	}
}

void WashingProgramController::main(){
	RTOS::timer washingProgramTimer(this, "stepTimer");
	
	while(true){
		wait(startFlag);
		
		hasStarted = true;
	
		door->lock();
		
		washingMachine->start();
	
		scheduler->start();
		
		soapTray->open();
		
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
					rotationController->setGoalState(currentStep.rotationSpeed);
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
		washingMachine->stop();
		door->unlock();
		
		delete scheduler;
		
		hasStarted = false;
	}
}

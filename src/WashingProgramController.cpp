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
	scheduler = WashingProgramScheduler(program);

	startFlag.set();
}

void WashingProgramController::stopWashingProgram(){
	scheduler.stop();
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
	
		door->lock();
		washingMachine->start();
	
		scheduler.start();
		
		bool started = false;
	
		while(true){
			if(washingMachineStatus == RUNNING){
				started = true;
				
				if(scheduler.isRunning()){
					if(scheduler.isPaused()){
						scheduler.unpause();
					}
				
					waterLevelController->setGoalState(scheduler.getCurrentStep().waterLevel);
					temperatureController->setGoalState(scheduler.getCurrentStep().temperature);
					rotationController->setGoalState(scheduler.getCurrentStep().rotationSpeed);
				}
				
				scheduler.update();
			}else if(washingMachineStatus == FAILED){
				scheduler.pause();
			}else{
				if(started){
					break;
				}
			}
			
			washingMachineStatusSensor->update();
			washingProgramTimer.set(1000);
			wait(washingProgramTimer);
		}
		
		washingMachine->stop();
		door->unlock();
	}
}

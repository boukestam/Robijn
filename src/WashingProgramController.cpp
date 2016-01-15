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
	updateStatusSensorTimer(this, "updateTimer")
{
	
}


void WashingProgramController::startWashingProgram(WashingProgram program){
	door->lock();
	washingMachine->start();
	washingMachineStatusSensor->update();
	updateStatusSensorTimer.set(50);
	wait(updateStatusSensorTimer);
	if(washingMachineStatus == IDLE){
		scheduler = WashingProgramScheduler();
		scheduler.start(program);
	}
	else{
		std::cout << "Status is: " << washingMachineStatus << ". Did not start washing program." << std::endl;
	}
}

void WashingProgramController::stopWashingProgram(){
	washingMachine->stop();
	door->unlock();
	washingMachineStatusSensor->update();
	updateStatusSensorTimer.set(50);
	wait(updateStatusSensorTimer);
	if(washingMachineStatus == STOPPED){
		scheduler.stop();
	}
	else{
		std::cout << "Washing Machine not stopped. Status: " << washingMachineStatus << std::endl;
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
		if(washingMachineStatus == RUNNING){
			if(scheduler.isRunning()){
				if(scheduler.isPaused()){
					scheduler.unpause();
				}
				waterLevelController->setGoalState(scheduler.getCurrentStep().waterLevel);
				temperatureController->setGoalState(scheduler.getCurrentStep().temperature);
				rotationController->setGoalState(scheduler.getCurrentStep().rotationSpeed);
			}
			scheduler.update();
		}
		else if(washingMachineStatus == FAILED){
			scheduler.pause();
		}
		else{
			std::cout << "Washing Machine not running. Status: " << washingMachineStatus << std::endl;
		}
		washingMachineStatusSensor->update();
		washingProgramTimer.set(1000);
		wait(washingProgramTimer);
	}
}

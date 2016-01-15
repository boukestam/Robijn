#include "WashingProgramController.hpp"

WashingProgramController::WashingProgramController(
	WaterLevelController* waterLevelController,
	RotationController* rotationController,
	TemperatureController* temperatureController,
	Door* door, 
	SignalLed* signalLed, 
	WashingMachine* washingMachine,
	HardwareSensor* washingMachineStatusSensor):
	
	waterLevelController(waterLevelController),
	rotationController(rotationController),
	temperatureController(temperatureController),
	door(door),
	signalLed(signalLed),
	washingMachine(washingMachine),
	washingMachineStatusSensor(washingMachineStatusSensor)
{}

void WashingProgramController::startWashingProgram(WashingProgram* program){
	door->lock();
	washingMachine->start();
	scheduler = new WashingProgramScheduler();
	scheduler->startWashingProgram(program);
}

void WashingProgramController::stopWashingProgram(){
	washingMachine->stop();
	door->unlock();
}

void WashingProgramController::main(){
	RTOS::timer washingProgramTimer(this, "stepTimer");
	while(true){
		waterLevelController->setGoalState(scheduler->getCurrentStep().waterLevel);
		temperatureController->setGoalState(scheduler->getCurrentStep().temperature);
		rotationController->setGoalState(scheduler->getCurrentStep().rotationSpeed);
		scheduler->update();
		washingProgramTimer.set(1000);
		wait(washingProgramTimer);
	}
}

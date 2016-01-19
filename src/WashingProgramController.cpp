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
	startFlag(this, "startFlag"),
	soapTray(soapTray),
	doorSensor(doorSensor)
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

		RTOS::timer doorTimer(this, "doorTimer");

		while(!doorClosed){
			doorSensor->update();

			doorTimer.set(100 MS);
			wait(doorTimer);
		}

		door->lock();

		std::cout << "Locked door" << std::endl;

		washingMachine->start();

		soapTray->open();

		scheduler->start();

		bool startedRunning = false;

		WashingProgramStep step;

		while(true){
			if(washingMachineStatus == RUNNING){
				scheduler->update();

				if(!startedRunning){
					startedRunning = true;
				}

				if(scheduler->isRunning()){
					if(scheduler->isPaused()){
						scheduler->unpause();
					}

					WashingProgramStep currentStep = scheduler->getCurrentStep();

					if(currentStep != step){
						waterLevelController->setGoalState(currentStep.waterLevel);

						waterLevelController->signalWhenDone(&stateReachedFlag);
						wait(stateReachedFlag);

						temperatureController->setGoalState(currentStep.temperature);
						rotationController->setGoalState(currentStep.rotationSpeed / 25);

						step = currentStep;
					}
				}else{
					std::cout << "Washing program done" << std::endl;
					break;
				}
			}else if(washingMachineStatus == FAILED){
				scheduler->pause();
			}else{
				if(startedRunning){
					std::cout << "Washing program done" << std::endl;
					break;
				}
			}

			washingMachineStatusSensor->update();

			washingProgramTimer.set(1000 MS);
			wait(washingProgramTimer);
		}

		std::cout << "Stopping washing program..." << std::endl;

		soapTray->close();

		rotationController->setGoalState(0);

		std::cout << "Waiting for motor to stop" << std::endl;

		rotationController->signalWhenDone(&stateReachedFlag);
		wait(stateReachedFlag);

		std::cout << "Motor stopped" << std::endl;

		std::cout << "Waiting for water to drain" << std::endl;

		waterLevelController->setGoalState(0);

		waterLevelController->signalWhenDone(&stateReachedFlag);
		wait(stateReachedFlag);

		std::cout << "Water drained" << std::endl;

		temperatureController->setGoalState(20);
		
		washingMachine->stop();
		door->unlock();

		std::cout << "Door unlocked" << std::endl;
		
		delete scheduler;
		
		hasStarted = false;
		
		std::cout << "Stopped washing program" << std::endl;
	}
}

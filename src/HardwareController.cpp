#include "HardwareController.hpp"

HardwareController::HardwareController():
	RTOS::task(1, "hardwareController")
{}

void HardwareController::main(){
	
}

void HardwareController::valueChanged(HardwareSensor* sensor, unsigned char value){

}

#include <iostream>

void HardwareController::setGoalState(unsigned char state){
	std::cout << "Goal state: " << (int)state << std::endl;
	goalState = state;
}

void HardwareController::setCurrentState(unsigned char state){
	currentState = state;

	if(currentState == goalState && waitingFlags.size() > 0){
		for(RTOS::flag* flag : waitingFlags){
			flag->set();
		}
	}
}

void HardwareController::signalWhenDone(RTOS::flag* flag){
	waitingFlags.push_back(flag);
}

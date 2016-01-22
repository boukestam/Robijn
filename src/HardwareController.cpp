#include <iostream>
#include <iostream>
#include "HardwareController.hpp"

HardwareController::HardwareController():
	RTOS::task(1, "hardwareController")
{}

void HardwareController::main(){
	
}

void HardwareController::valueChanged(HardwareSensor* sensor, unsigned char value){

}

void HardwareController::setGoalState(unsigned char state){
	goalState = state;
}

void HardwareController::setCurrentState(unsigned char state){
	currentState = state;

	if(currentState == goalState && waitingFlags.size() > 0){
		for(RTOS::flag* flag : waitingFlags){
			flag->set();
		}
		waitingFlags.clear();
	}
}

bool HardwareController::signalWhenDone(RTOS::flag* flag){
	if(currentState != goalState){
		waitingFlags.push_back(flag);
		return true;
	}else{
		return false;
	}
}

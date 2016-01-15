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
}

#include "RotationController.hpp"
#include <thread>
#include <chrono>

RotationController::RotationController(Motor* motor, HardwareSensor* rotationSensor) :
	motor(motor), 
	rotationSensor(rotationSensor)
{}

void RotationController::main(){
	while(true){
		rotationSensor->update();
		motor->setRotation(goalState);
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}

void RotationController::valueChanged(HardwareSensor* sensor, unsigned char value){
	
}
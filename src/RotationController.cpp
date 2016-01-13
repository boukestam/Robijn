#include "RotationController.hpp"

RotationController::RotationController(Motor* motor, HardwareSensor* rotationSensor) :
	motor(motor), 
	rotationSensor(rotationSensor)
{}

void RotationController::main(){
	while(true){
		rotationSensor->update();
		motor->setRotation(goalState);
		sleep(5000);
	}
}

void RotationController::valueChanged(HardwareSensor* sensor, unsigned char value){
	
}
#include "RotationController.hpp"

RotationController::RotationController(Motor* motor, HardwareSensor* rotationSensor) :
	motor(motor), 
	rotationSensor(rotationSensor)
{}

void RotationController::main(){
	RTOS::timer *rotationTimer = new RTOS::timer(this, "rotationTimer");
	while(true){
		rotationSensor->update();
		motor->setRotation(goalState);
		rotationTimer->set(5000);
		wait(*rotationTimer);
	}
}

void RotationController::valueChanged(HardwareSensor* sensor, unsigned char value){
	
}
#include "RotationController.hpp"

RotationController::RotationController(Motor* motor, HardwareSensor* rotationSensor) :
	motor(motor), 
	rotationSensor(rotationSensor)
{}

void RotationController::main(){
	RTOS::timer rotationTimer(this, "rotationTimer");

	while(true){
		motor->setRotation(goalState);

		rotationSensor->update();

		rotationTimer.set(500 MS);
		wait(rotationTimer);
	}
}

void RotationController::valueChanged(HardwareSensor* sensor, unsigned char value){

}

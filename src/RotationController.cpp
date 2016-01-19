#include "RotationController.hpp"

RotationController::RotationController(Motor* motor, HardwareSensor* rotationSensor) :
	motor(motor), 
	rotationSensor(rotationSensor)
{}

void RotationController::main(){
	RTOS::timer rotationTimer(this, "rotationTimer");

	while(true){
		std::cout << "Start motor loop" << std::endl;

		motor->setRotation(goalState);

		std::cout << "Set rotation" << std::endl;

		rotationSensor->update();

		rotationTimer.set(500 MS);

		std::cout << "End motor loop" << std::endl;
		wait(rotationTimer);
	}
}

void RotationController::valueChanged(HardwareSensor* sensor, unsigned char value){

}

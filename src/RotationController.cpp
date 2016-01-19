#include "RotationController.hpp"

RotationController::RotationController(Motor* motor, HardwareSensor* rotationSensor) :
	motor(motor), 
	rotationSensor(rotationSensor)
{}

void RotationController::main(){
	RTOS::timer rotationTimer(this, "rotationTimer");

	unsigned char rotation = 0;
	const unsigned char rotationChangeAmount = 1;

	while(true){
		if(rotation < goalState){
			rotation += rotationChangeAmount;

			if(rotation > goalState){
				rotation = goalState;
			}
		}else if(rotation > goalState){
			rotation -= rotationChangeAmount;

			if(rotation < goalState){
				rotation = goalState;
			}
		}

		motor->setRotation(rotation);

		rotationSensor->update();

		rotationTimer.set(500 MS);
		wait(rotationTimer);
	}
}

void RotationController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == rotationSensor){
		setCurrentState(value);
	}
}

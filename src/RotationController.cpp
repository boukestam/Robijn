#include <iostream>
#include <iostream>
#include "RotationController.hpp"

RotationController::RotationController(Motor* motor, HardwareSensor* rotationSensor) :
	motor(motor), 
	rotationSensor(rotationSensor)
{}

void RotationController::main(){
	RTOS::timer rotationTimer(this, "rotationTimer");

	int rotation = 0;
	int rotationChangeAmount = 50;

	int rotationDirection = 1;

	while(true){
		time_t now;
		time(&now);

		if(rotationInterval <= 0){
			lastRotationSwitch = now;
		}else if(now - lastRotationSwitch >= rotationInterval){
			rotationDirection = -rotationDirection;
			lastRotationSwitch = now;
		}

		int goalRotation = goalState * 25 * rotationDirection;

		if(rotation < goalRotation){
			rotation += rotationChangeAmount;

			if(rotation > goalRotation){
				rotation = goalRotation;
			}
		}else if(rotation > goalRotation){
			rotation -= rotationChangeAmount;

			if(rotation < goalRotation){
				rotation = goalRotation;
			}
		}

		unsigned char realRotation = abs(rotation / 25);

		if(rotation < 0){
			realRotation |= 0x80;
		}

		motor->setRotation(realRotation);

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

void RotationController::setRotationInterval(int interval){
	rotationInterval = interval;
}

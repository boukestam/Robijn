#include "TemperatureController.hpp"

TemperatureController::TemperatureController(Heating* heating, HardwareSensor* temperatureSensor) :
	heating(heating),
	temperatureSensor(temperatureSensor)
{}

void TemperatureController::main(){
	RTOS::timer temperatureTimer(this, "temperatureTimer");
	while(true){
		if(currentState >= goalState+1){
			heating->off();
		}
		else if(currentState <= goalState-1){
			heating->on();
		}
		temperatureSensor->update();
		temperatureTimer.set(500 MS);
		wait(temperatureTimer);
	}
}

void TemperatureController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == temperatureSensor){
		setCurrentState(value);
	}
}

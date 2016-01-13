#include "TemperatureController.hpp"

TemperatureController::TemperatureController(Heating* heating, HardwareSensor* temperatureSensor) :
	heating(heating),
	temperatureSensor(temperatureSensor)
{}

void TemperatureController::main(){
	RTOS::timer *temperatureTimer = new RTOS::timer(this, "temperatureTimer");
	while(true){
		temperatureSensor->update();
		if(currentState < goalState){
			heating->on();
		}
		else{
			heating->off();
		}
		temperatureTimer->set(5000);
		wait(*temperatureTimer);
	}
}

void TemperatureController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == temperatureSensor){
		setCurrentState(value);
	}
}
#include <chrono>
#include "TemperatureController.hpp"

TemperatureController::TemperatureController(Heating* heating, HardwareSensor* temperatureSensor) :
	heating(heating),
	temperatureSensor(temperatureSensor)
{}

void TemperatureController::main(){
	while(true){
		temperatureSensor->update();
		if(currentState < goalState){
			heating->on();
		}
		else{
			heating->off();
		}
		sleep(5000);
	}
}

void TemperatureController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == temperatureSensor){
		setCurrentState(value);
	}
}
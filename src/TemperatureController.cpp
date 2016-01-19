#include "TemperatureController.hpp"

TemperatureController::TemperatureController(Heating* heating, HardwareSensor* temperatureSensor) :
	heating(heating),
	temperatureSensor(temperatureSensor)
{}

void TemperatureController::main(){
	RTOS::timer temperatureTimer(this, "temperatureTimer");
	while(true){
		std::cout << "Start temperature loop" << std::endl;

		if(currentState >= goalState+1){
			heating->off();
		}else if(currentState <= goalState-1){
			heating->on();
		}

		temperatureSensor->update();

		std::cout << "End temperature loop" << std::endl;

		temperatureTimer.set(500 MS);
		wait(temperatureTimer);
	}
}

void TemperatureController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == temperatureSensor){
		setCurrentState(value);
	}
}

#include <chrono>
#include <thread>
#include "TemperatureController.hpp"

TemperatureController::TemperatureController(Heating* heating, HardwareSensor* temperatureSensor) :
	heating(heating),
	temperatureSensor(temperatureSensor)
{}

void TemperatureController::main(){
	while(true){
		temperatureSensor->update();
		if(getTemperatureDifference(currentState, goalState) == 0){
			heating->on();
		}
		else if(getTemperatureDifference(currentState, goalState) > 0){
			heating->off();
		}
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}

void TemperatureController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == temperatureSensor){
		setCurrentState(value);
	}
}

//Current temperature is higher then the Goal temperature: 2
//Current temperature is lower then the Goal temperature: 0
//Current temperature is the same as Goal Temperature: 1
int TemperatureController::getTemperatureDifference(unsigned char currentTemp, unsigned char goalTemp){
	if(currentTemp > goalTemp){
		return 2;
	}
	else if(currentTemp < goalTemp){
		return 0;
	}
	else{
		return 1;
	}
}
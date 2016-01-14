#include "WaterLevelController.hpp"

WaterLevelController::WaterLevelController(Pump* pump, Tap* tap, HardwareSensor* waterLevelSensor) :
	pump(pump),
	tap(tap),
	waterLevelSensor(waterLevelSensor)
{}

void WaterLevelController::main(){
	RTOS::timer waterTimer(this, "waterTimer");
	while(true){
		waterLevelSensor->update();
		if(currentState < goalState){
			pump->off();
			tap->on();
		}
		else if(currentState > goalState){
			tap->off();
			pump->on();
		}
		else{
			tap->off();
			pump->off();
		}
		waterTimer.set(500);
		wait(waterTimer);
	}
}

void WaterLevelController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == waterLevelSensor){
		setCurrentState(value);
	}
}


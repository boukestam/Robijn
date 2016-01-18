#include "WaterLevelController.hpp"

WaterLevelController::WaterLevelController(Pump* pump, Tap* tap, HardwareSensor* waterLevelSensor) :
	pump(pump),
	tap(tap),
	waterLevelSensor(waterLevelSensor)
{}

void WaterLevelController::main(){
	RTOS::timer waterTimer(this, "waterTimer");
	while(true){
		if(currentState < goalState-5){
			pump->off();
			tap->on();
		}
		else if(currentState > goalState+5){
			tap->off();
			pump->on();
		}
		else{
			tap->off();
			pump->off();
		}
		waterLevelSensor->update();
		waterTimer.set(500 MS);
		wait(waterTimer);
	}
}

void WaterLevelController::valueChanged(HardwareSensor* sensor, unsigned char value){
	if(sensor == waterLevelSensor){
		setCurrentState(value);
	}
}


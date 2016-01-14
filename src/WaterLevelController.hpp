#pragma once

#include "HardwareController.hpp"

#include "Pump.hpp"
#include "Tap.hpp"
#include "WaterLevelSensor.hpp"

class WaterLevelController: public HardwareController{
public:
	WaterLevelController(Pump* pump, Tap* tap, WaterLevelSensor* waterLevelSensor);
	
	void main() override;
	
private:
	Pump* pump;
	Tap* tap;
	WaterLevelSensor* waterLevelSensor;
};
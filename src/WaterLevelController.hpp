#pragma once

#include "HardwareController.hpp"
#include "Pump.hpp"
#include "Tap.hpp"
#include "HardwareSensor.hpp"

class WaterLevelController: public HardwareController{
public:
	WaterLevelController(Pump* pump, Tap* tap, HardwareSensor* waterLevelSensor);
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	void main() override;
	
private:
	Pump* pump;
	Tap* tap;
	HardwareSensor* waterLevelSensor;
};
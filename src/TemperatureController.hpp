#pragma once

#include "HardwareController.hpp"

#include "Heating.hpp"
#include "TemperatureSensor.hpp"

class TemperatureController: public HardwareController{
public:
	TemperatureController(Heating* heating, TemperatureSensor* temperatureSensor);
	
	void main() override;
	
private:
	Heating* heating;
	TemperatureSensor* temperatureSensor;
};
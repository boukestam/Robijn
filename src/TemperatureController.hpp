#pragma once

#include "HardwareController.hpp"
#include "Heating.hpp"
#include "HardwareSensor.hpp"

class TemperatureController: public HardwareController{
public:
	TemperatureController(Heating* heating, HardwareSensor* temperatureSensor);
	int getTemperatureDifference(unsigned char currentTemp, unsigned char goalTemp);
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	void main() override;
	
private:
	Heating* heating;
	HardwareSensor* temperatureSensor;
};
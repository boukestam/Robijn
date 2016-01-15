#pragma once

#include "HardwareController.hpp"
#include "HardwareSensor.hpp"
#include "Motor.hpp"

class RotationController: public HardwareController{
public:
	RotationController(Motor* motor, HardwareSensor* rotationSensor);
	void valueChanged(HardwareSensor* sensor, unsigned char value) override;
	void main() override;
	
private:
	Motor* motor;
	HardwareSensor* rotationSensor;
};
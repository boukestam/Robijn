#pragma once

#include "HardwareController.hpp"

#include "Motor.hpp"

class RotationController: public HardwareController{
public:
	RotationController(Motor* motor);
	
	void main() override;
	
private:
	Motor* motor;
};
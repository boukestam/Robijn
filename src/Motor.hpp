#pragma once

#include "HardwareComponent.hpp"

class Motor: public HardwareComponent{
public:
	void setRotation(unsigned char rotation);
};
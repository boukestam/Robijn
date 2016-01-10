#pragma once

#include "HardwareComponent.hpp"

class Tap: public HardwareComponent{
public:
	void on();
	void off();
};
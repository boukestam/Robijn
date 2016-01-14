#pragma once

#include "HardwareComponent.hpp"

class SignalLed: public HardwareComponent{
public:
	void on();
	void off();
};
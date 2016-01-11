#pragma once

#include "HardwareComponent.hpp"

class SoapTray: public HardwareComponent{
public:
	void open();
	void close();
};
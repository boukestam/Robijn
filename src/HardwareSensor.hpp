#pragma once

#include <vector>

#include "HardwareComponent.hpp"
#include "HardwareListener.hpp"

class HardwareSensor: public HardwareComponent{
public:
	virtual void update();
	void addListener(HardwareListener* listener);
	
protected:
	void valueChanged(unsigned char newValue);
	
private:
	std::vector<HardwareListener*> listeners;
	unsigned char previousValue;
};

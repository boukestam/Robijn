#pragma once

//to prevent circular dependency
class HardwareSensor;

class HardwareListener{
public:
	virtual void valueChanged(HardwareSensor* sensor, unsigned char value);
private:
	
};

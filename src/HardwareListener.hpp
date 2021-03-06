#pragma once

//to prevent circular dependency
class HardwareSensor;

/**
 * @class HardwareListener
 * @author Bouke Stam
 * @date 20/01/16
 * @file HardwareListener.hpp
 * @brief Listener class for a listener pattern between the Hardware Sensors and the Hardware Controllers
 */

class HardwareListener{
public:
	//! Gets called if sensor detects a change in currentValue
	virtual void valueChanged(HardwareSensor* sensor, unsigned char value);
private:
	
};

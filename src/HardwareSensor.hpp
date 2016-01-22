#pragma once

#include <vector>

#include "HardwareComponent.hpp"
#include "HardwareListener.hpp"

/**
 * @class HardwareSensor
 * @author Thijs Hendrickx
 * @date 20/01/16
 * @file HardwareSensor.hpp
 * @brief Interface for all the sensors in the washing machine
 */

class HardwareSensor: public HardwareComponent{
public:
	//! Constructor for HardwareSensor
	HardwareSensor(UARTInterface* uartInterface);

	//! Calls an update on the currentValue for this sensor
	virtual void update();

	//! Adds a HardwareListener to the list of listeners that will be notified off new values
	void addListener(HardwareListener* listener);
	
protected:
	//! Gets called if a sensor detects a change in currentValue
	void valueChanged(unsigned char newValue);
	
private:
	//! All listeners that subscribed to changed
	std::vector<HardwareListener*> listeners;
	
	//! Previous value to compare with new value
	unsigned char previousValue = 0;
};

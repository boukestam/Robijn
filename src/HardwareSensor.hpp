#pragma once

#include <vector>

#include "HardwareComponent.hpp"
#include "HardwareListener.hpp"

/**
 * @class HardwareSensor
 * @author Thijs
 * @date 20/01/16
 * @file HardwareSensor.hpp
 * @brief Interface for all the sensors in the washing machine
 */

class HardwareSensor: public HardwareComponent{
public:
/**
 * @brief Constructor for HardwareSensor
 */
	HardwareSensor(UARTInterface* uartInterface);

/**
 * @brief Calls an update on the currentValue for this sensor
 */
	virtual void update();

/**
 * @brief Adds a HardwareListener to the list of listeners that will be subscribed to valueChanged calls
 * @param listener The HardwareListener to be added
 */
	void addListener(HardwareListener* listener);
	
protected:
/**
 * @brief Gets called if a sensor detects a change in currentValue
 * @param value The changed value
 */
	void valueChanged(unsigned char newValue);
	
private:
	std::vector<HardwareListener*> listeners;
	unsigned char previousValue = 0;
};

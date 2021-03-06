#include <iostream>
#include <iostream>
#include "HardwareSensor.hpp"

HardwareSensor::HardwareSensor(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void HardwareSensor::addListener(HardwareListener* listener){
	listeners.push_back(listener);
}
	
void HardwareSensor::valueChanged(unsigned char newValue){
	if(newValue != previousValue){
		for(HardwareListener* listener : listeners){
			listener->valueChanged(this, newValue);
		}
		
		previousValue = newValue;
	}
}

void HardwareSensor::update(){

}

#include <iostream>
#include <iostream>
#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(UARTInterface* uartInterface):
	HardwareSensor(uartInterface)
{}

void TemperatureSensor::update(){
	UARTMessage message(TEMPERATURE_REQ, EMPTY_CMD, this);

	uartInterface->send(message);
}

void TemperatureSensor::responseReceived(UARTMessage response){
	valueChanged(response.second);
}

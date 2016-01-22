#include <iostream>
#include <iostream>
#include "RotationSensor.hpp"

RotationSensor::RotationSensor(UARTInterface* uartInterface):
	HardwareSensor(uartInterface)
{}

void RotationSensor::update(){
	UARTMessage message(GET_RPM_REQ, EMPTY_CMD, this);

	uartInterface->send(message);
}

void RotationSensor::responseReceived(UARTMessage response){
	valueChanged(response.second);
}

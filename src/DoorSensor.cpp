#include <iostream>
#include <iostream>
#include "DoorSensor.hpp"

DoorSensor::DoorSensor(UARTInterface* uartInterface):
	HardwareSensor(uartInterface)
{}

void DoorSensor::update(){
	UARTMessage message(DOOR_LOCK_REQ, STATUS_CMD, this);

	uartInterface->send(message);
}

void DoorSensor::responseReceived(UARTMessage response){
	valueChanged(response.second);
}

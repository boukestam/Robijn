#include <iostream>
#include <iostream>
#include "WashingMachineStatusSensor.hpp"

WashingMachineStatusSensor::WashingMachineStatusSensor(UARTInterface* uartInterface):
	HardwareSensor(uartInterface)
{}

void WashingMachineStatusSensor::update(){
	UARTMessage message(MACHINE_REQ, STATUS_CMD, this);

	uartInterface->send(message);
}

void WashingMachineStatusSensor::responseReceived(UARTMessage response){
	valueChanged(response.second);
}

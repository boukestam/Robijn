#include "Heating.hpp"

#include <iostream>

Heating::Heating(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void Heating::on(){
	UARTMessage message(HEATING_UNIT_REQ, ON_CMD, this);
	
	uartInterface->send(message);
}

void Heating::off(){
	UARTMessage message(HEATING_UNIT_REQ, OFF_CMD, this);

	uartInterface->send(message);
}

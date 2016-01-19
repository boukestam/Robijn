#include "Heating.hpp"

#include <iostream>

Heating::Heating(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void Heating::on(){
	std::cout << "Heating: on" << std::endl;

	UARTMessage message(HEATING_UNIT_REQ, ON_CMD, this);
	
	uartInterface->send(message);
}

void Heating::off(){
	std::cout << "Heating: off" << std::endl;

	UARTMessage message(HEATING_UNIT_REQ, OFF_CMD, this);

	uartInterface->send(message);
}

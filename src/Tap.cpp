#include "Tap.hpp"

#include <iostream>

Tap::Tap(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void Tap::on(){
	std::cout << "Tap: on" << std::endl;

	UARTMessage message(WATER_VALVE_REQ, OPEN_CMD, this);

	uartInterface->send(message);
}

void Tap::off(){
	std::cout << "Tap: off" << std::endl;
	UARTMessage message(WATER_VALVE_REQ, CLOSE_CMD, this);

	uartInterface->send(message);
}


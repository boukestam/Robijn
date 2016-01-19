#include "Pump.hpp"

#include <iostream>

Pump::Pump(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void Pump::on(){
	std::cout << "Pump: on" << std::endl;

	UARTMessage message(PUMP_REQ, ON_CMD, this);

	uartInterface->send(message);
}

void Pump::off(){
	std::cout << "Pump: off" << std::endl;

	UARTMessage message(PUMP_REQ, OFF_CMD, this);

	uartInterface->send(message);
}


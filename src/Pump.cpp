#include <iostream>
#include <iostream>
#include "Pump.hpp"

#include <iostream>

Pump::Pump(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void Pump::on(){
	UARTMessage message(PUMP_REQ, ON_CMD, this);

	uartInterface->send(message);
}

void Pump::off(){
	UARTMessage message(PUMP_REQ, OFF_CMD, this);

	uartInterface->send(message);
}


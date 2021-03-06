#include <iostream>
#include <iostream>
#include "Tap.hpp"

#include <iostream>

Tap::Tap(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void Tap::on(){
	UARTMessage message(WATER_VALVE_REQ, OPEN_CMD, this);

	uartInterface->send(message);
}

void Tap::off(){
	UARTMessage message(WATER_VALVE_REQ, CLOSE_CMD, this);

	uartInterface->send(message);
}


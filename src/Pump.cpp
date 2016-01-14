#include "Pump.hpp"

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

#include <iostream>
#include <iostream>
#include "WashingMachine.hpp"

WashingMachine::WashingMachine(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void WashingMachine::start(){
	UARTMessage message(MACHINE_REQ, START_CMD, this);

	uartInterface->send(message);
}

void WashingMachine::stop(){
	UARTMessage message(MACHINE_REQ, STOP_CMD, this);

	uartInterface->send(message);
}

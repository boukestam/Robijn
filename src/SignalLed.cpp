#include <iostream>
#include <iostream>
#include "SignalLed.hpp"

SignalLed::SignalLed(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void SignalLed::on(){
	UARTMessage message(SIGNAL_LED_REQ, ON_CMD, this);

	uartInterface->send(message);
}

void SignalLed::off(){
	UARTMessage message(SIGNAL_LED_REQ, OFF_CMD, this);

	uartInterface->send(message);
}

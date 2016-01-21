#include "Motor.hpp"

#include <iostream>

Motor::Motor(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

#include <assert.h>

void Motor::setRotation(unsigned char rotation){
	UARTMessage message(SET_RPM_REQ, rotation, this);

	uartInterface->send(message);
}

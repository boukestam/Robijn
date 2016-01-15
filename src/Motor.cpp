#include "Motor.hpp"

Motor::Motor(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

#include <assert.h>

void Motor::setRotation(unsigned char rotation){
	//TODO(Bouke): Support rotation in both directions
	assert(rotation <= 0x40);
	
	UARTMessage message(SET_RPM_REQ, rotation, this);

	uartInterface->send(message);
}

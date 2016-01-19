#include "Door.hpp"

Door::Door(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void Door::lock(){
	UARTMessage message(DOOR_LOCK_REQ, LOCK_CMD, this);

	uartInterface->send(message);
}

void Door::unlock(){
	UARTMessage message(DOOR_LOCK_REQ, UNLOCK_CMD, this);

	uartInterface->send(message);
}

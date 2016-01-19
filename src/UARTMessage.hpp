#pragma once

//To avoid circular dependency
class UARTListener;

class UARTMessage{
public:
	UARTMessage();
	UARTMessage(unsigned char first, unsigned char second, UARTListener* sender);

	unsigned char first;
	unsigned char second;
	UARTListener* sender;
};

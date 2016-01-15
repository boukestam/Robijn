#pragma once

//To avoid circular dependency
class UARTListener;

class UARTMessage{
public:
	UARTMessage(unsigned char first, unsigned char second);
	
	unsigned char getFirstByte();
	unsigned char getSecondByte();
	UARTListener getSender();
	
private:
	unsigned char first;
	unsigned char second;
	UARTListener* sender;
};
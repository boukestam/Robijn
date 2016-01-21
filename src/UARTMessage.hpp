#pragma once

//To avoid circular dependency
class UARTListener;

//! UARTMessage class

//! This class constains the two bytes to send to or receive from the uart and the sender to send the response to
class UARTMessage{
public:
	//! Create an empty message
	UARTMessage();

	//! Create a message
	UARTMessage(unsigned char first, unsigned char second, UARTListener* sender);

	//! First byte (request in sent message, command in received)
	unsigned char first;

	//! Second byte (command in sent message, answer in received)
	unsigned char second;

	//! UARTListener that sent the message and needs to receive the answer
	UARTListener* sender;
};

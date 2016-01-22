#include <iostream>
#include <iostream>
#include "UARTMessage.hpp"

UARTMessage::UARTMessage(){

}

UARTMessage::UARTMessage(unsigned char first, unsigned char second, UARTListener* sender):
	first(first),
	second(second),
	sender(sender)
{}

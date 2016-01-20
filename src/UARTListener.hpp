#pragma once

#include "UARTMessage.hpp"

//! UARTListener class

//! Interface implemented by classes that send messages to the UART
class UARTListener{
public:
	//! Callback method to send response to when received
	virtual void responseReceived(UARTMessage response);
};

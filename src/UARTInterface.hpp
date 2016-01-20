#pragma once

#include "pRTOS.h"
#include "libserial.h"

#include "UARTInterface.hpp"
#include "UARTMessage.hpp"

//! UARTInterface class

//! UARTInterface, sends messages asynchronous through the uart and sends the response back to sender
class UARTInterface: public RTOS::task{
public:
	//! Constructor
	UARTInterface();

	//! Destructor
	~UARTInterface();

	//! Main thread
	void main() override;

	//! Send a message to UART
	void send(UARTMessage message);

private:
	//! Buffer to put message in before being send
	RTOS::channel<UARTMessage, 16> sendBuffer;

	//! Timer to wait for reply from UART
	RTOS::timer replyTimer;

	//! Serial object to interface with the emulator
	LibSerial serial;
};

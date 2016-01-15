#pragma once

#include "pRTOS.h"
#include "libserial.h"

#include "UARTInterface.hpp"
#include "UARTMessage.hpp"

class UARTInterface: public RTOS::task{
public:
	UARTInterface();
	~UARTInterface();
	
	void main() override;
	void send(UARTMessage message);
	
private:
	RTOS::channel<UARTMessage, 16> sendBuffer;
	RTOS::timer replyTimer;
	
	LibSerial serial;
};

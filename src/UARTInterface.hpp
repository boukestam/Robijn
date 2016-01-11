#pragma once

#include "pRTOS.h"

#include "UARTInterface.hpp"
#include "UARTMessage.hpp"

class UARTInterface: public RTOS::task{
public:
	void main() override;
	void send(UARTMessage message);
	
private:
	RTOS::channel<UARTMessage, 16> sendBuffer;
};

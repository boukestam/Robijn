#pragma once

#include "pRTOS.h"

#include "SocketMessage.hpp"

class SocketServer{
public:
	SocketServer(int port);

	void sendMessage(SocketMessage message);
	bool receiveMessage(SocketMessage* message);

private:
	RTOS::channel<SocketMessage, 16> receiveBuffer; // TODO: Change to vector
	RTOS::channel<SocketMessage, 16> sendBuffer;    // TODO: Change to vector
};

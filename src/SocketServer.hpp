#pragma once

#include "PracticalSocket.h"
#include "WebSocket.h"
#include "WebSocketMulticaster.h"
#include "SocketMessage.hpp"
#include <vector>

class MyListener : public WebSocketListener{
public:
    MyListener(Multicaster* multicaster) : multicaster{multicaster} {}

	void onTextMessage(const string& s, WebSocket* ws){ // TODO: Parse json string and put it in the receiveBuffer
		multicaster->broadcast(s);
		std::cout << "Received: " << s << std::endl;
	}

	void onClose(WebSocket* ws){
		multicaster->remove(ws);
		delete ws;
	}

private:
    Multicaster* multicaster;
};

class SocketServer{
public:
	SocketServer(int port);
	~SocketServer();

	void sendMessage(SocketMessage* message);
	bool receiveMessage(SocketMessage* message);

private:
    void run();

    Multicaster* multicaster;
    MyListener* myListener;

    int port;
    size_t bufferSize = 16;
    std::vector<SocketMessage*> receiveBuffer;
    std::vector<SocketMessage*> sendBuffer;
};

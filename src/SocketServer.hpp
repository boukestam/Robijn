#pragma once

#include "PracticalSocket.h"
#include "WebSocket.h"
#include "WebSocketMulticaster.h"
#include "SocketMessage.hpp"
#include <vector>

class SocketListener;

class SocketServer{
public:
	SocketServer(int port);
	~SocketServer();

	void sendMessage(SocketMessage* message);
	bool receiveMessage(SocketMessage* message);

private:
    void run();

    Multicaster* multicaster;
    SocketListener* socketListener;

    int port;
    size_t bufferSize = 16;
    std::vector<SocketMessage*> receiveBuffer;
    std::vector<SocketMessage*> sendBuffer;
};

class SocketListener : public WebSocketListener{
public:
    SocketListener(Multicaster* multicaster, SocketServer* socketServer) : multicaster{multicaster}, socketServer{socketServer} {}

	void onTextMessage(const std::string& s, WebSocket* ws){ // TODO: Parse json string and put it in the receiveBuffer
		SocketMessage* message = new SocketMessage();
		if (message->parseJSONString(s)) {
            socketServer->receiveMessage(message);
		} else {
            std::cout << "Parsing failed" << std::endl;
		}
		std::cout << "Received: " << s << std::endl;
	}

	void onClose(WebSocket* ws){
		multicaster->remove(ws);
		delete ws;
	}

private:
    Multicaster* multicaster;
    SocketServer* socketServer;
};

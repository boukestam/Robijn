#pragma once

#include "PracticalSocket.h"
#include "WebSocket.h"
#include "WebSocketMulticaster.h"
#include "SocketMessage.hpp"
#include <vector>

class MyListener;

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

class MyListener : public WebSocketListener{
public:
    MyListener(Multicaster* multicaster, SocketServer* socketServer) : multicaster{multicaster}, socketServer{socketServer} {}

	void onTextMessage(const std::string& s, WebSocket* ws){ // TODO: Parse json string and put it in the receiveBuffer
		multicaster->broadcast(s);
		SocketMessage* message = new SocketMessage();
		//std::cout << message->getJSONString() << message->getJSONString().empty() << std::endl;
		if (message->parseJSONString(s)) {
            socketServer->receiveMessage(message);
            std::string s("fuck");
            message->setValue(s, s);
            multicaster->broadcast(message->getJSONString());
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

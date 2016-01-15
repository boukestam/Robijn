#pragma once

#include "PracticalSocket.h"
#include "WebSocket.h"
#include "WebSocketMulticaster.h"
#include "SocketMessage.hpp"
#include <vector>
#include <mutex>

class SocketListener;

class SocketServer{
public:
	SocketServer(int port);
	~SocketServer();

	void sendMessage(SocketMessage* message);
	bool receiveMessage(SocketMessage*& message);

private:
    void run();
    void runSendMessageHandler();

    Multicaster* multicaster;
    SocketListener* socketListener;

    int port;
    size_t bufferSize = 16;
    std::vector<SocketMessage*> receiveBuffer;
    std::vector<SocketMessage*> sendBuffer;

    int sendMessageHandlerSleepTime = 200;
    SocketMessage* localSendMessage;

    std::mutex receiveMutex;
    std::mutex sendMutex;

    friend SocketListener;
};

class SocketListener : public WebSocketListener{
public:
    SocketListener(SocketServer* socketServer) : socketServer{socketServer} {}
    ~SocketListener() {}

	void onTextMessage(const std::string& s, WebSocket* ws){ // TODO: Parse json string and put it in the receiveBuffer
		SocketMessage* message = new SocketMessage();
		if (message->parseJSONString(s)) {
            socketServer->receiveMutex.lock();
            socketServer->receiveBuffer.push_back(message);
            socketServer->receiveMutex.unlock();
		} else {
            std::cout << "Parsing failed" << std::endl;
		}
		std::cout << "Received: " << s << std::endl;
	}

	void onClose(WebSocket* ws){
		socketServer->multicaster->remove(ws);

		delete ws;
	}

private:
    SocketServer* socketServer;
};

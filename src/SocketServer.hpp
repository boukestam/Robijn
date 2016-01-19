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
		std::cout << "Got new message" << std::endl;
		SocketMessage* message = new SocketMessage();
		if (message->parseJSONString(s)) {
            rapidjson::Document& document = message->getJSON();
            rapidjson::Value& val = document["event"];
			std::string event = val.GetString();

            if (event == "verify"){
                const std::string name = document["name"].GetString();
                const std::string password = document["password"].GetString();
                handleVerification(ws, name, password);
            } else {
                unsigned int hashValue = document["hash"].GetUint();
                for (std::vector<std::pair<std::string, unsigned int>>::iterator currentPair=userAddressHashPairs.begin(); currentPair!=userAddressHashPairs.end(); ++currentPair) {
                    if ((*currentPair).second == hashValue) {
                        socketServer->receiveMutex.lock();
                        socketServer->receiveBuffer.push_back(message);
                        socketServer->receiveMutex.unlock();
                    }
                }
            }
		} else {
            std::cout << "Parsing failed" << std::endl;
		}
		std::cout << "Received: " << s << std::endl;
	}

	void onClose(WebSocket* ws){
		socketServer->multicaster->remove(ws);

		for (std::vector<std::pair<std::string, unsigned int>>::iterator currentPair=userAddressHashPairs.begin(); currentPair!=userAddressHashPairs.end(); ++currentPair) {
            if ((*currentPair).first == ws->getForeignAddress()) {
                userAddressHashPairs.erase(currentPair);
            }
		}

		delete ws;
	}

private:
    SocketServer* socketServer;
    std::vector<std::pair<std::string, unsigned int>> userAddressHashPairs;

    void handleVerification(WebSocket* ws, std::string name, std::string password) {
        std::string defaultName("demo"); // TODO: From file
        std::string defaultPassword("demoHashed"); // TODO: From file

        if (!name.compare(defaultName) && !password.compare(defaultPassword)) {
            const char* s = "wakkawakka";

            unsigned int newHash = 34523;
            while (*s) {
                newHash = newHash * 101  +  *s++;
            }

            std::pair <std::string, unsigned int> newPair(ws->getForeignAddress(), newHash);
            userAddressHashPairs.push_back(newPair);

            std::string jsonString("{\"event\":\"verify\", \"ok\":true, \"hash\":");
            jsonString.append(std::to_string(newHash));
            jsonString.append("}");
            ws->sendTextMessage(jsonString);
        }
    }
};

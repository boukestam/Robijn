#pragma once

#include "PracticalSocket.h"
#include "WebSocket.h"
#include "WebSocketMulticaster.h"
#include "SocketMessage.hpp"
#include <vector>
#include <mutex>
#include <unordered_map>

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

            if (event == "verify") { // User wants to log in
                const std::string name = document["name"].GetString();
                const int password = document["password"].GetUint();
                handleVerification(ws, name, password);
            } else { // Handle message
                unsigned int hashValue = document["hash"].GetUint();

                std::unordered_map<WebSocket*, unsigned int>::const_iterator foundMap = webSocketHashValueMap.find(ws);

                if (foundMap != webSocketHashValueMap.end()) { // If websocket exists
                    if (foundMap->second == hashValue) { // If the hash is equal to the sent hash
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

		std::unordered_map<WebSocket*, unsigned int>::const_iterator foundMap = webSocketHashValueMap.find(ws);

        if (foundMap != webSocketHashValueMap.end()) {
            webSocketHashValueMap.erase(foundMap);
        }

		delete ws;
	}

private:
    SocketServer* socketServer;
    std::unordered_map<WebSocket*, unsigned int> webSocketHashValueMap; // WebSocket pointer, hash value

    void handleVerification(WebSocket* ws, std::string name, int password) {
        std::string defaultName("demo"); // TODO: From file
        int defaultPassword = 3079651; // TODO: From file

        if (!name.compare(defaultName) && password == defaultPassword) {
            const char* s = "wakkawakka";

            unsigned int newHash = 34523;
            while (*s) {
                newHash = newHash * 101  +  *s++;
            }

            std::pair <WebSocket*, unsigned int> newPair(ws, newHash);
            webSocketHashValueMap.insert(newPair);

            std::string jsonString("{\"event\":\"verify\", \"ok\":true, \"hash\":");
            jsonString.append(std::to_string(newHash));
            jsonString.append("}");
            ws->sendTextMessage(jsonString);
        }
    }
};

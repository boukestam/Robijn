#pragma once

#include "PracticalSocket.h"
#include "WebSocket.h"
#include "WebSocketMulticaster.h"
#include "SocketMessage.hpp"
#include <vector>
#include <mutex>
#include <unordered_map>
#include <ctime>
#include <fstream>

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
    virtual ~SocketListener() {}

	void onTextMessage(const std::string& s, WebSocket* ws){ // TODO: Parse json string and put it in the receiveBuffer
		std::cout << "Got new message" << std::endl;
		SocketMessage* message = new SocketMessage();
		if (message->parseJSONString(s)) {
            rapidjson::Document& document = message->getJSON();
            rapidjson::Value& val = document["event"];
			std::string event = val.GetString();

            if (event == "verify") { // User wants to log in
                const std::string name = document["name"].GetString();
                const int password = document["password"].GetInt();
                handleVerification(ws, name, password);
                delete message; // Delete message because we're not using it
            } else { // Handle messaged
                unsigned int hashValue = document["hash"].GetUint();

                std::unordered_map<WebSocket*, unsigned int>::const_iterator foundMap = webSocketHashValueMap.find(ws);

                if (foundMap != webSocketHashValueMap.end()) { // If websocket exists
                    if (foundMap->second == hashValue) { // If the hash is equal to the sent hash
                        socketServer->receiveMutex.lock();
                        socketServer->receiveBuffer.push_back(message);
                        socketServer->receiveMutex.unlock();
                    } else { // Hash not equal, so delete message
                        delete message;
                    }
                } else { // Map not found, delete message
                    delete message;
                }
            }
		} else { // Parsing failed, delete message
            std::cout << "Parsing failed" << std::endl;
            delete message;
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
		std::ifstream file("users.json");
		std::string str;
		std::string file_contents;
		while (std::getline(file, str))
		{
			file_contents += str;
		}  


		rapidjson::Document document;
		document.Parse(file_contents.c_str());

		const rapidjson::Value& a = document["users"];

		for (rapidjson::SizeType i = 0; i < a.Size(); i++){
		    std::string defaultName = a[i]["name"].GetString(); // TODO: From file
		    int defaultPassword = a[i]["pass"].GetInt(); //3079651; // TODO: From file means demo  

		    if (name == defaultName && password == defaultPassword) {
		        //const long double sysTime = time(0);
		        //const char* s = std::to_string(sysTime).c_str();
				const char* s = "wakkaUbuntu9NEIN";

		        unsigned int newHash = time(0);
		        while (*s) {
		            newHash = newHash * 101  +  *s++;
		        }

		        std::pair <WebSocket*, unsigned int> newPair(ws, newHash);
		        webSocketHashValueMap.insert(newPair);

		        std::string jsonString("{\"event\":\"verify\", \"ok\":true, \"hash\":");
		        jsonString.append(std::to_string(newHash));
		        jsonString.append("}");
		        ws->sendTextMessage(jsonString);
				return;
		    } 
		} 
		// Wrong name and/or password
        std::string jsonString("{\"event\":\"verify\", \"ok\":false}");
        ws->sendTextMessage(jsonString);
    }
};

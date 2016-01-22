#include <iostream>
#include "SocketServer.hpp"

SocketServer::SocketServer(int port) : port{port} {
    multicaster = new Multicaster();
    socketListener = new SocketListener(this);

    std::thread t(&SocketServer::run, this);
    t.detach();
    std::thread t2(&SocketServer::runSendMessageHandler, this);
    t2.detach();
}

SocketServer::~SocketServer() {
    delete multicaster;
    delete socketListener;
}

SocketMessage SocketServer::receiveMessage() {
    std::lock_guard<std::mutex> lock(receiveMutex);
    SocketMessage message;
	
    if (receiveBuffer.size() > 0) {
        message = receiveBuffer.front(); // Make message point to message from vector (will have to be deleted on receiving side when done)
        receiveBuffer.pop(); // Remove from vector
    }

    return message;
}

bool SocketServer::hasMessage(){
	std::lock_guard<std::mutex> lock(receiveMutex);
    return receiveBuffer.size() > 0;
}

void SocketServer::sendMessage(SocketMessage message) {
    std::lock_guard<std::mutex> lock(sendMutex);
    sendBuffer.push(message);
}

void SocketServer::run() {
    try { // Make a socket to listen for client connections.
        TCPServerSocket servSock(port);
        std::cout << "SocketServer running: " << servSock.getLocalAddress().getAddress() << std::endl;
        for (;;) {
            TCPSocket *sock = servSock.accept();
            WebSocket* ws = new WebSocket(sock);
            ws->setListener(socketListener);
            multicaster->add(ws);
        }
    } catch (SocketException &e) {
        std::cerr << e.what() << std::endl; // Report errors to the console
    }
}

void SocketServer::runSendMessageHandler() {
    for (;;) {
        sendMutex.lock();
        if (sendBuffer.size() > 0) {
			SocketMessage message = sendBuffer.front(); // Get Message
			
			multicaster->broadcast(message.getJSONString()); // Send Message
			
			sendBuffer.pop(); // Delete from vector
        }
        sendMutex.unlock();

        usleep(sendMessageHandlerSleepTime);
    }
}

////////////////////////
//// SocketListener ////
////////////////////////

SocketListener::SocketListener(SocketServer* socketServer) : socketServer{socketServer} {}

void SocketListener::onTextMessage(const std::string& s, WebSocket* ws){ // TODO: Parse json string and put it in the receiveBuffer
    SocketMessage message;
	
    if (message.parseJSONString(s)) {
        rapidjson::Document& document = message.getJSON();
        rapidjson::Value& val = document["event"];
        std::string event = val.GetString();

        if (event == "verify") { // User wants to log in
            const std::string name = document["name"].GetString();
            const int password = document["password"].GetInt();
            handleVerification(ws, name, password);
        } else { // Handle messaged
            unsigned int hashValue = document["hash"].GetUint();

            std::unordered_map<WebSocket*, unsigned int>::const_iterator foundMap = webSocketHashValueMap.find(ws);

            if (foundMap != webSocketHashValueMap.end()) { // If websocket exists
                if (foundMap->second == hashValue) { // If the hash is equal to the sent hash
                    socketServer->receiveMutex.lock();
                    socketServer->receiveBuffer.push(message);
                    socketServer->receiveMutex.unlock();
                }
            }
        }
    } else { // Parsing failed, delete message
        std::cout << "Parsing failed" << std::endl;
    }
}

void SocketListener::onClose(WebSocket* ws){
    socketServer->multicaster->remove(ws);

    std::unordered_map<WebSocket*, unsigned int>::const_iterator foundMap = webSocketHashValueMap.find(ws);

    if (foundMap != webSocketHashValueMap.end()) {
        webSocketHashValueMap.erase(foundMap);
    }

    delete ws;
}

void SocketListener::handleVerification(WebSocket* ws, std::string name, int password) {
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
        std::string currentName = a[i]["name"].GetString(); // TODO: From file
        int currentPassword = a[i]["pass"].GetInt(); //3079651; // TODO: From file means demo

        if (name == currentName && password == currentPassword) {
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

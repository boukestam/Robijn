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

class SocketListener; // Needed to compile, implementation is below

/**
 * @class SocketServer
 * @author Mathijs van Bremen
 * @date 20/01/16
 * @file SocketServer.hpp
 * @brief This class handles connections to the WebSocket
 */
class SocketServer{
public:
/**
 * @brief Constructor for SocketServer that calls method run() and method runSendMessageHandler() on new threads
 * @param port Integer that indicates on what port number the SocketServer should run
 */
	SocketServer(int port);

/**
 * @brief Destructor for SocketServer that deletes certain data
 */
	~SocketServer();

/**
 * @brief Adds a new SocketMessage that has te be sent to the client
 * @brief Buffer is locked by a mutex
 * @param message Pointer to SocketMessage which will be put in the SendBuffer
 */
	void sendMessage(SocketMessage* message);

/**
 * @brief Checks if there's a new message from the client
 * @brief Will return true if there's a new message and false if there's no new message
 * @brief If there's a new message then the message parameter will point to that new message
 * @brief Buffer is locked by a mutex
 * @param message Reference to a pointer to SocketMessage which will point to a new message from the buffer if available
 */
	bool receiveMessage(SocketMessage*& message);

private:
/**
 * @brief Function that accepts and handles new connections
 */
    void run();

/**
 * @brief Function that will check for new messages that have to be sent to the client
 * @brief Buffer is locked by a mutex
 */
    void runSendMessageHandler();

    Multicaster* multicaster;
    SocketListener* socketListener;

    int port;
    size_t bufferSize = 16;
    std::vector<SocketMessage*> receiveBuffer;
    std::vector<SocketMessage*> sendBuffer;

    int sendMessageHandlerSleepTime = 200;

    std::mutex receiveMutex;
    std::mutex sendMutex;

    friend SocketListener;
};

/**
 * @class SocketListener
 * @author Mathijs van Bremen
 * @date 20/01/16
 * @file SocketListener.hpp
 * @brief This class handles the callbacks from the WebSocket
 */
class SocketListener : public WebSocketListener{
public:
/**
 * @brief Constructor for SocketListener
 * @param socketServer Pointer to SocketServer so SocketListener can use mutex and multicaster from SocketServer (friend of SocketServer)
 */
    SocketListener(SocketServer* socketServer);
	virtual ~SocketListener() {};
/**
 * @brief Callback that gets called when WebSocket receives a text message
 * @param s Reference to string received by WebSocket
 * @param ws Pointer to WebSocket where the callback came from
 */
	void onTextMessage(const std::string& s, WebSocket* ws);

/**
 * @brief Callback that gets called when WebSocket gets closed
 * @param ws Pointer to WebSocket where the callback came from
 */
	void onClose(WebSocket* ws);

private:
/**
 * @brief Function that handles verification of a certain user
 * @param ws Pointer to WebSocket the verification request came from
 * @param name String of the username that has to be verified
 * @param password Integer of the hashed password that has to be verified
 */
    void handleVerification(WebSocket* ws, std::string name, int password);

    SocketServer* socketServer;
    std::unordered_map<WebSocket*, unsigned int> webSocketHashValueMap; // WebSocket pointer, hash value
};

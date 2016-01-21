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
 * @brief Will return that new message or a nullptr if there's no new message
 */
	SocketMessage* receiveMessage();

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

/**
 * @brief The multicaster used to send messages to clients
 */
    Multicaster* multicaster;

/**
 * @brief The SocketListener that receives messages from clients
 */
    SocketListener* socketListener;

/**
 * @brief Port number that the WebSocket will run on
 */
    int port;

/**
 * @brief Size of the buffers containing pointers to SocketMessages
 */
    size_t bufferSize = 16;

/**
 * @brief Vector containing all messages received from clients
 */
    std::vector<SocketMessage*> receiveBuffer;

/**
 * @brief Vector containing all messages that have to be sent to clients
 */
    std::vector<SocketMessage*> sendBuffer;

/**
 * @brief Amount of uSec that messageHandler thread will sleep
 */
    int sendMessageHandlerSleepTime = 200;

/**
 * @brief Mutex for the receiveBuffer
 */
    std::mutex receiveMutex;

/**
 * @brief Mutex for sendBuffer
 */
    std::mutex sendMutex;

/**
 * @brief SocketListener set as friend so SocketListener can access mutexes and multicaster
 */
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

/**
 * @brief The SocketServer object that uses this listener
 */
    SocketServer* socketServer;

/**
 * @brief Unordered map with WebSockets and Hash values used for verification
 */
    std::unordered_map<WebSocket*, unsigned int> webSocketHashValueMap; // WebSocket pointer, hash value
};

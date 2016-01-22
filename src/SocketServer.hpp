#pragma once

#include "PracticalSocket.h"
#include "WebSocket.h"
#include "WebSocketMulticaster.h"
#include "SocketMessage.hpp"
#include <queue>
#include <mutex>
#include <unordered_map>
#include <ctime>
#include <fstream>

class SocketListener; // Forward declaration, implementation is below

/**
 * @class SocketServer
 * @author Mathijs van Bremen
 * @date 20/01/16
 * @file SocketServer.hpp
 * @brief This class handles connections to the WebSocket
 */
 
class SocketServer{
public:
	//! Constructor for SocketServer that calls method run() and method runSendMessageHandler() on new threads
	SocketServer(int port);

	//! Destructor for SocketServer that deletes certain data
	~SocketServer();

	//! Adds a new SocketMessage that has te be sent to the client
	void sendMessage(SocketMessage message);

	//! Returns the first message in the receive queue, or an empty one if the queue is empty
	SocketMessage receiveMessage();
	
	//! Returns true if there is a message in the receive queue
	bool hasMessage();

private:
	//! Accepts and handles new connections
    void run();

	//! Will check for new messages that have to be sent to the client
    void runSendMessageHandler();

	//! The multicaster used to send messages to clients
    Multicaster* multicaster;

	//! The SocketListener that receives messages from clients
    SocketListener* socketListener;

	//! Port number that the WebSocket will run on
    int port;

	//! Queue with received messages
    std::queue<SocketMessage> receiveBuffer;
    
    //! Queue with messages to be sent
    std::queue<SocketMessage> sendBuffer;

	//! Amount of uSec that messageHandler thread will sleep
    int sendMessageHandlerSleepTime = 200;

	//! Mutex for the receiveBuffer
    std::mutex receiveMutex;

	//! Mutex for sendBuffer
    std::mutex sendMutex;

	//! SocketListener set as friend so SocketListener can access mutexes and multicaster
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
	//! Constructor for SocketListener
    SocketListener(SocketServer* socketServer);
    
    //! Destructor
	virtual ~SocketListener() {};
	
	//! Callback that gets called when WebSocket receives a text message
	void onTextMessage(const std::string& s, WebSocket* ws);

 	//! Callback that gets called when WebSocket gets closed
	void onClose(WebSocket* ws);

private:
	//! Function that handles verification of a certain user
    void handleVerification(WebSocket* ws, std::string name, int password);

	//! The SocketServer object that uses this listener
    SocketServer* socketServer;

	//! Unordered map with WebSockets and Hash values used for verification
    std::unordered_map<WebSocket*, unsigned int> webSocketHashValueMap; // WebSocket pointer, hash value
};

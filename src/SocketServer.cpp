#include "SocketServer.hpp"

SocketServer::SocketServer(int port) : port{port} {
    receiveBuffer.reserve(bufferSize);  // Vector with 'bufferSize' elements
    sendBuffer.reserve(bufferSize);     // Vector with 'bufferSize' elements

    multicaster = new Multicaster();
    socketListener = new SocketListener(multicaster, this);

    std::thread t(&SocketServer::run, this);
    t.detach();
}

SocketServer::~SocketServer() {
    delete multicaster;
    delete socketListener;
}

void SocketServer::sendMessage(SocketMessage* message) {
    std::lock_guard<std::mutex> lock(sendMutex);
    sendBuffer.push_back(message);
}

bool SocketServer::receiveMessage(SocketMessage* message) {
    std::lock_guard<std::mutex> lock(receiveMutex);
    receiveBuffer.push_back(message);


    std::cout << message->getJSONString() << std::endl;
    std::string eventKey("event");
    std::string event = message->getValue<std::string>(eventKey);
    if (event == "statusUpdate") {
        std::cout << "statusUpdate" << std::endl;
        message->generateStatusUpdateMessage(0);
    } else if (event == "getWashingPrograms") {
        message->generateWashingProgramsMessage();
    } else if (event == "startWashingProgram") {
        message->generateStatusUpdateMessage(1);
    }
    std::cout << message->getJSONString() << std::endl;
    multicaster->broadcast(message->getJSONString());
    sendMessage(message);
    getFirstSendMessage();
    return true;
}

SocketMessage* SocketServer::getFirstSendMessage() {
    std::lock_guard<std::mutex> lock(sendMutex);
    if (sendBuffer.size() > 0) {
        return sendBuffer.front();
    }
    std::cout << "empty vector" << std::endl;

    return nullptr;
}

void SocketServer::deleteFirstSendMessage() {
    std::lock_guard<std::mutex> lock(sendMutex);
    sendBuffer.erase(sendBuffer.begin());
}

SocketMessage* SocketServer::getFirstReceiveMessage() {
    std::lock_guard<std::mutex> lock(receiveMutex);
    if (receiveBuffer.size() > 0) {
        return receiveBuffer.front();
    }
    std::cout << "empty vector" << std::endl;

    return nullptr;
}

void SocketServer::deleteFirstReceiveMessage() {
    std::lock_guard<std::mutex> lock(receiveMutex);
    receiveBuffer.erase(receiveBuffer.begin());
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

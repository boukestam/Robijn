#include "SocketServer.hpp"

SocketServer::SocketServer(int port) : port{port} {
    receiveBuffer.reserve(bufferSize);  // Vector with 'bufferSize' elements
    sendBuffer.reserve(bufferSize);     // Vector with 'bufferSize' elements

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

bool SocketServer::receiveMessage(SocketMessage*& message) {
    std::lock_guard<std::mutex> lock(receiveMutex);
    if (receiveBuffer.size() > 0) {
        message = receiveBuffer.front(); // Make message point to message from vector (will have to be deleted on receiving side when done)
        receiveBuffer.erase(receiveBuffer.begin()); // Remove from vector
        return true;
    }

    return false;
}

void SocketServer::sendMessage(SocketMessage* message) {
    std::lock_guard<std::mutex> lock(sendMutex);
    sendBuffer.push_back(message);
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
            SocketMessage* message = sendBuffer.front(); // Get Message
            multicaster->broadcast(message->getJSONString()); // Send Message
            sendBuffer.erase(sendBuffer.begin()); // Delete from vector
            delete message; // Free space
        }
        sendMutex.unlock();

        usleep(sendMessageHandlerSleepTime);
    }
}

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
    sendBuffer.push_back(message);
}

bool SocketServer::receiveMessage(SocketMessage* message) {
    receiveBuffer.push_back(message);
    std::cout << message->getJSONString() << std::endl;
    std::string eventKey("event");
    std::string event = message->getValue<std::string>(eventKey);
    if (event == "statusUpdate") {
        std::cout << "statusUpdate" << std::endl;
        message->generateStatusUpdateMessage();
    } else if (event == "getWashingPrograms") {
        message->generateWashingProgramsMessage();
    }
    std::cout << message->getJSONString() << std::endl;
    multicaster->broadcast(message->getJSONString());
    return true;
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

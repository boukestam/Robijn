#include "SocketServer.hpp"

SocketServer::SocketServer(int port) : port{port} {
    receiveBuffer.reserve(bufferSize);  // Vector with 'bufferSize' elements
    sendBuffer.reserve(bufferSize);     // Vector with 'bufferSize' elements

    multicaster = new Multicaster();
    myListener = new MyListener(multicaster);

    std::thread t(&SocketServer::run, this);
    t.detach();
}

SocketServer::~SocketServer() {
    delete multicaster;
    delete myListener;
}

void SocketServer::sendMessage(SocketMessage* message) {
    sendBuffer.push_back(message);
}

bool SocketServer::receiveMessage(SocketMessage* message) {
    receiveBuffer.push_back(message);
    return true;
}

void SocketServer::run() {
    try { // Make a socket to listen for client connections.
        TCPServerSocket servSock(port);
        std::cout << "SocketServer running: " << servSock.getLocalAddress().getAddress() << std::endl;
        for (;;) {
            TCPSocket *sock = servSock.accept();
            WebSocket* ws = new WebSocket(sock);
            ws->setListener(myListener);
            multicaster->add(ws);
        }
    } catch (SocketException &e) {
        std::cerr << e.what() << std::endl; // Report errors to the console
    }
}

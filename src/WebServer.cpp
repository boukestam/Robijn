#include "WebServer.hpp"
#include "Logger.hpp"
#include "WebServerGetHandler.hpp"
#include "WebServerResponseHandler.hpp"
#include <thread>

// Creates a WebServer on a certain port and a certain rootDirectory that contains server files
WebServer::WebServer(int port, std::string rootDirectory) : port{port}, rootDirectory{rootDirectory} {
    std::thread t(&WebServer::run, this);
    t.detach();
}

WebServer::~WebServer() {
}

// Custom getLine function to handle requests from multiple OSes
// Sees LF, CR+LF and CR as end-of-line mark
std::istream& WebServer::getLine(std::istream& in, std::string& out) {
	char c;
	out.clear();

	while(in.get(c).good()) {
		if(c == '\r') {
			c = in.peek();
			if(in.good() && c == '\n' ) {
				in.ignore();
			}
			break;
		}
		if(c == '\n') break;
		out.append(1,c);
	}
	return in;
}

void WebServer::handleConnection(TCPSocket *sock) {
    Logger logger;
    logger.setFile(sock->getForeignAddress().getAddress());
    logger.logNotice("Handle Connection", "Started logging");
    WebServerResponseHandler responseHandler(rootDirectory, logger);
    while(true) {
        std::string line;
        std::iostream& stream = sock->getStream();
        WebServerGetHandler getHandler;
        bool readRequest = false;
        while(getLine(stream, line)){
            if (line.compare(0, getHandler.getGetPrefix().length(), getHandler.getGetPrefix()) == 0) {
                getHandler.parseGetLine(line);
                readRequest = true;
            }

            std::cout << line << std::endl; // What the client sent
            if (line.empty() && readRequest) {
                responseHandler.setInfo(getHandler.getFilename(), getHandler.getFileExtension());
                responseHandler.sendResponse(sock);
                stream.flush();
            }
        }
    }
    logger.logNotice("Handle Connection", "Stopped logging");
    sock->close();
    delete sock;                      // Close and delete TCPSocket
}

void WebServer::run() {
    try { // Make a socket to listen for client connections.
        TCPServerSocket servSock(port);
        std::cout << "WebServer running: " << servSock.getLocalAddress().getAddress() << std::endl;
        for (;;) {
            TCPSocket *sock = servSock.accept(); // Wait for a new connection and accept it
            std::thread t(&WebServer::handleConnection, this, sock); // Handle each connection on a new thread
            t.detach(); // Will not wait for thread to finish; will just kill the thread if WebServer dies
        }
    } catch (SocketException &e) {
        std::cerr << e.what() << std::endl; // Report errors to the console
    }
}

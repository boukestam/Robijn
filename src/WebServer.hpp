#pragma once

#include <string>
#include <iostream>

#include "PracticalSocket.h"

class WebServer {
public:
	WebServer(int port, std::string rootDirectory);
	~WebServer();

private:
    std::istream& getLine(std::istream& in, std::string& out);
    void handleConnection(TCPSocket *sock);
	void run();

	int port;
	std::string rootDirectory;
};

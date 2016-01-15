#pragma once

#include <string>

#include "PracticalSocket.h"

class WebServer{
public:
	WebServer(int port);
	
	void handleConnection(Socket s);
	
private:
	std::string rootDirectory;
};

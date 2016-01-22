#pragma once

#include <string>
#include <iostream>

#include "PracticalSocket.h"

/**
 * @class WebServer
 * @author Mathijs van Bremen
 * @date 20/01/16
 * @file WebServer.hpp
 * @brief This class handles connections to the WebServer
 */
 
class WebServer {
public:
	//! Constructor for WebServer that calls method run() on a new thread
	WebServer(int port, std::string rootDirectory);

private:
	//! Custom getLine function to handle requests from multiple OS's
    std::istream& getLine(std::istream& in, std::string& out);

	//! Handles a single connection for a certain TCP Socket
    void handleConnection(TCPSocket* sock);

	//! Function that accepts new connections and calls method handleConnection() for each one on a new thread
	void run();

	//! Port number that the WebServer will run on
	int port;

	//! The directory where the files are located
	std::string rootDirectory;
};

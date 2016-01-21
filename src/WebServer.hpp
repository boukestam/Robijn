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
/**
 * @brief Constructor for WebServer that calls method run() on a new thread
 * @param port Integer that indicates on what port number the WebServer should run
 * @param rootDirectory String that indicates where the WebServer files are located
 */
	WebServer(int port, std::string rootDirectory);

private:
/**
 * @brief Custom getLine function to handle requests from multiple OSes
 * @param in Reference to istream with the GET request
 * @param out Reference to string where line should be written to
 */
    std::istream& getLine(std::istream& in, std::string& out);

/**
 * @brief Handles a single connection for a certain TCP Socket
 * @param sock Pointer to the TCPSocket that should be listened to
 */
    void handleConnection(TCPSocket* sock);

/**
 * @brief Function that accepts new connections and calls method handleConnection() for each one on a new thread
 */
	void run();

/**
 * @brief Port number that the WebServer will run on
 */
	int port;

/**
 * @brief The directory where the files are located
 */
	std::string rootDirectory;
};

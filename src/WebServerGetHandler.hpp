#pragma once

#include <string>
#include <iostream>
#include <fstream>

/**
 * @class WebServerGetHandler
 * @author Mathijs van Bremen
 * @date 20/01/16
 * @file WebServerGetHandler.hpp
 * @brief This class handles the GET request that has been sent by the browser
 */
 
class WebServerGetHandler {
public:
	//! Constructor for WebServerGetHandler
    WebServerGetHandler();

	//! Function that parses the first line from a GET request (stores filename and file extension)
    void parseGetLine(std::string line);

	//! Returns a string of the GET prefix in a GET request
    std::string getGetPrefix();

	//! Returns a string indicating what filename was parsed
    std::string getFilename();

	//! Returns a string indicating what file extension was parsed
    std::string getFileExtension();

protected:
private:
	//! The filename of the requested file
    std::string filename;

	//! The file extension of the requested file
    std::string extension;

	//! Prefix of the first line of the GET request
    std::string getPrefix = "GET /";
};

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "PracticalSocket.h"
#include "Logger.hpp"
#include <iomanip>
#include <ctime>

/**
 * @class WebServerResponseHandler
 * @author Mathijs van Bremen
 * @date 20/01/16
 * @file WebServerResponseHandler.hpp
 * @brief This class handles the response that has to be sent back to the browser
 */
 
class WebServerResponseHandler {
public:
	//! Constructor for WebServerResponseHandler
    WebServerResponseHandler(std::string rootDirectory, Logger logger);

	//! Sends the response to the given TCP socket (should be called after a call to setInfo())
    void sendResponse(TCPSocket* sock);

	//! Sets the file path and file extension of the file that has to be sent as response
    void setInfo(std::string filePath, std::string fileExtension);
protected:
private:
	//! Returns whether or not the file (set with setInfo()) exists
    bool doesFileExist();

	//! Returns whether or not the file extension (set with setInfo()) is valid
     bool isValidExtension();

	//! Returns the filecontent of the given file
    std::string readFile(std::string path, bool binaryRead);

	//! Struct with valid extension types / supported extension types
    const struct { std::string ext; std::string contentType; bool binaryRead; } ValidExtensionType[16] =
    {
        { "bmp", "image/bmp", true },
        { "ico", "image/ico", true },
        { "png", "image/png", true },
        { "jpeg", "image/jpeg", true },
        { "jpg", "image/jpeg", true },
        { "html", "text/html", false },
        { "xhtml", "application/xhtml+xml", false },
        { "htm", "text/html", false },
        { "txt", "text/plain", false },
        { "json", "application/json", false },
        { "xml", "application/xml", false },
        { "log", "text/plain", false},
        { "js", "application/javascript", false },
        { "css", "text/css", false },
        { "wav", "audio/x-wav", true },
		{ "ogg", "audio/ogg", true}
    };

	//! Whether or not file to be read has te be read as binary file
    bool needBinaryRead;

	//! The path of the file that was set
    std::string path;

	//! The extension of the file that was set
    std::string extension;

	//! The content type that will be sent back to the client
    std::string contentType;

	//! Directory where files are located
    std::string rootDirectory;

	//! The Logger object where logs will be written to
    Logger log;
};

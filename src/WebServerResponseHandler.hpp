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
/**
 * @brief Constructor for WebServerResponseHandler
 * @param rootDirectory String that indicates where the WebServer files are located
 * @param logger Logger object used to log certain things
 */
    WebServerResponseHandler(std::string rootDirectory, Logger logger);

/**
 * @brief Sends the response to the given TCP socket (should be called after a call to setInfo())
 * @param sock Pointer to the socket that response should be sent to
 */
    void sendResponse(TCPSocket* sock);

/**
 * @brief Sets the file path and file extension of the file that has to be sent as response
 * @param filePath String that indicates what file should be sent as response
 * @param fileExtension String that indicates what extension the file has (used for Content-Type in response)
 */
    void setInfo(std::string filePath, std::string fileExtension);
protected:
private:
/**
 * @brief Returns whether or not the file (set with setInfo()) exists
 */
    bool doesFileExist();

/**
 * @brief Returns whether or not the file extension (set with setInfo()) is valid
*/
     bool isValidExtension();

/**
 * @brief Returns the filecontent of the given file
 * @param path String that indicates what file should be read from
 * @param binaryRead Boolean that indicates if the file should be read as binary file or as text file
 */
    std::string readFile(std::string path, bool binaryRead);

/**
 * @brief Struct with valid extension types / supported extension types
 * @param ext String that indicates what the extension is
 * @param contentType String that indicates what the contenType is
 * @param binaryRead String that indicates whether or not the file should read as binary file or as text file
 */
    const struct { std::string ext; std::string contentType; bool binaryRead; } ValidExtensionType[15] =
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
        { "wav", "audio/x-wav", true }
    };

    bool needBinaryRead;
    std::string path;
    std::string extension;
    std::string contentType;
    std::string rootDirectory;
    Logger log;
};

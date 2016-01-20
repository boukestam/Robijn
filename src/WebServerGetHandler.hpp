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
/**
 * @brief Constructor for WebServerGetHandler
 */
    WebServerGetHandler();

/**
 * @brief Function that parses the first line from a GET request (stores filename and file extension)
 * @param line String that indicates what line to parse
 */
    void parseGetLine(std::string line);

/**
 * @brief Returns a string of the GET prefix in a GET request
 */
    std::string getGetPrefix();

/**
 * @brief Returns a string indicating what filename was parsed
 */
    std::string getFilename();

/**
 * @brief Returns a string indicating what file extension was parsed
 */
    std::string getFileExtension();

protected:
private:
    std::string filename;
    std::string extension;
    std::string getPrefix = "GET /";
};

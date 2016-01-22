#pragma once

#include <string>
#include <iostream>
#include <fstream>

/**
 * @class Logger
 * @author Mathijs van Bremen
 * @date 20/01/16
 * @file Logger.hpp
 * @brief This class is used for logging and writes it to a class
 */
class Logger {
public:
	//! Constructor for Logger
    Logger();

	//! Function that logs the given data
    void logNotice(std::string funcName, std::string log);

	//! Function to set the filename to write to
	//! Will add the time and date on which the function is called to the filename
    void setFile(std::string file);

protected:
private:
	//! Function that will return a string with the current time and date
    std::string getTime();

	//! Name of the log file
    std::string logFile;
};

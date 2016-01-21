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
/**
 * @brief Constructor for Logger
 */
    Logger();

/**
 * @brief Function that logs the given data
 * @param funcName String indicating where the log comes from
 * @param log String indicating what the log is
 */
    void logNotice(std::string funcName, std::string log);

/**
 * @brief Function to set the filename to write to
 * @brief Will add the time and date on which the function is called to the filename
 */
    void setFile(std::string file);

protected:
private:
/**
 * @brief Function that will return a string with the current time and date
 */
    std::string getTime();

    std::string logFile;
};

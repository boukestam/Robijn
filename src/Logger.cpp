#include "Logger.hpp"

Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::setFile(std::string file) {
    std::string timeStr = getTime();

    logFile = timeStr; // LogFile is time on which setFile is called
}

void Logger::logNotice(std::string funcName, std::string log) {
    std::string timeStr = getTime();

    std::fstream fs;
    fs.open ("log/"+ logFile + ".log", std::fstream::out | std::fstream::app);
    fs << "[" << timeStr << "] [" << funcName << "] " << log << "\r\n";
    fs.close();

    std::cout << "[" << timeStr << "] ["<< logFile <<"][" << funcName << "] " << log << std::endl;
}

std::string Logger::getTime() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,80,"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string timeStr(buffer);

    return timeStr;
}

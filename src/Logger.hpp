#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Logger
{
    public:
        Logger();
        virtual ~Logger();
        void logNotice(std::string funcName, std::string log);
        void setFile(std::string file);

    protected:
    private:
        std::string getTime();

        std::string logFile;
};

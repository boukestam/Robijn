#pragma once

#include <string>
#include <iostream>
#include <fstream>

class WebServerGetHandler
{
    public:
        WebServerGetHandler();
        virtual ~WebServerGetHandler();
        void parseGetLine(std::string line);
        std::string getGetPrefix();
        std::string getFilename();
        std::string getFileExtension();

    protected:
    private:
        std::string filename;
        std::string extension;
        std::string getPrefix = "GET /";
};

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "PracticalSocket.h"
#include "Logger.hpp"
#include <iomanip>
#include <ctime>

class WebServerResponseHandler
{
    public:
        WebServerResponseHandler(std::string rootDirectory, Logger logger);
        virtual ~WebServerResponseHandler();
        void sendResponse(TCPSocket *sock);
        void setInfo(std::string filepath, std::string fileextension);
    protected:
    private:
        bool doesFileExist();
        bool isValidExtension();
        std::string readFile(std::string path, bool binaryRead);

   const struct { std::string ext; std::string content_type; bool binaryRead; } ValidExtensionType[14] =
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
		{ "css", "text/css", false }
    };

    bool needBinaryRead;
    std::string path;
    std::string extension;
    std::string content_type;
    std::string rootDirectory;
    Logger log;
};

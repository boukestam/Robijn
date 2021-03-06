#include <iostream>
#include <iostream>
#include "WebServerResponseHandler.hpp"

WebServerResponseHandler::WebServerResponseHandler(std::string rootDirectory, Logger logger) : rootDirectory{rootDirectory}, log{logger} {
    log.logNotice("ResponseHandler ctor", "New response handler for connection ");
}

void WebServerResponseHandler::setInfo(std::string filePath, std::string fileExtension) {
    path = filePath;
    extension = fileExtension;
    log.logNotice("SetInfo", "Response handler info changed for connection ");
}

bool WebServerResponseHandler::doesFileExist() {
    std::ifstream stream;
    bool isOpen = false;
    stream.open(rootDirectory + path + "." + extension);

    if (stream.is_open()) {
        isOpen = true;
        stream.close();
    }
    return isOpen;
}

bool WebServerResponseHandler::isValidExtension() {
    for (auto s : ValidExtensionType) {
        if (s.ext == extension) {
            needBinaryRead = s.binaryRead;
            contentType = "Content-Type: " + s.contentType;
            log.logNotice("IsValidExtension", "Valid extension");
            return true;
        }
    }
    log.logNotice("IsValidExtension", "Invalid extension");
    return false;
}

void WebServerResponseHandler::sendResponse(TCPSocket *sock) {
    std::string response;
    std::iostream& stream = sock->getStream();

    if (doesFileExist()) {
        log.logNotice("SendResponse", path + "." + extension + " exists");
        if (isValidExtension()) {
            response = readFile(path + "." + extension, needBinaryRead);
            stream << "HTTP/1.1 200 OK" << std::endl;
            log.logNotice("SendResponse", "Valid Extension and file read");
        } else {// Niet ondersteunde extensie 501 Not Implemented
            stream << "HTTP/1.1 501 Not Implemented" << std::endl;
            contentType = "text/html";
            response = readFile("statuspages/501.html", false);
            log.logNotice("SendResponse", "Invalid extension 501 not implemented");
        }
        //cout << "Response was " << response << endl;
    } else {
        stream << "HTTP/1.1 404 File not found" << std::endl;
        response = readFile("statuspages/404.html", false);
        contentType = "text/html";
        log.logNotice("SendResponse", "404 file not found");
    }

    stream << "Content-Length: " << response.length() << std::endl;
    stream << "Content-Type: " << contentType << std::endl;
    stream << std::endl;
    stream << response;
    stream.flush();
    log.logNotice("SendResponse", "Done sending response");
}

std::string WebServerResponseHandler::readFile(std::string location, bool readBinary) {
    log.logNotice("ReadFile", "Starting to read file " + rootDirectory + location);
    std::string fileContent;
    if (readBinary) {
        std::ifstream fin(rootDirectory + location, std::ios::in | std::ios::binary);
        std::ostringstream oss;
        oss << fin.rdbuf();
        fileContent = oss.str();
    } else {
        std::ifstream stream;
        std::string regel;
        stream.open(rootDirectory + location);

        while (getline(stream, regel)) {
            fileContent += regel;
        }
        stream.close();
    }
    log.logNotice("ReadFile", "Done reading file");
    return fileContent;
}

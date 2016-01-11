#include "WebServerResponseHandler.hpp"

WebServerResponseHandler::WebServerResponseHandler(Logger logger) {
    log = logger;
    log.logNotice("ResponseHandler ctor", "New response handler for connection ");
}

WebServerResponseHandler::~WebServerResponseHandler() {
    //dtor
}

void WebServerResponseHandler::setInfo(std::string filePath, std::string fileExtension) {
    path = filePath;
    extension = fileExtension;
    log.logNotice("SetInfo", "Response handler info changed for connection ");
}

bool WebServerResponseHandler::doesFileExist() {
    std::ifstream stream;
    bool isOpen = false;
    stream.open("www/" + path + "." + extension);

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
            content_type = "Content-Type: " + s.content_type;
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
            content_type = "text/html";
            response = readFile("statuspages/501.html", false);
            log.logNotice("SendResponse", "Invalid extension 501 not implemented");
        }
        //cout << "Response was " << response << endl;
    } else {
        stream << "HTTP/1.1 404 File not found" << std::endl;
        response = readFile("statuspages/404.html", false);
        content_type = "text/html";
        log.logNotice("SendResponse", "404 file not found");
    }

    stream << "Content-Length: " << response.length() << std::endl;
    stream << "Content-Type: " << content_type << std::endl;
    stream << std::endl;
    stream << response;
    stream.flush();
    log.logNotice("SendResponse", "Done sending response");
}

std::string WebServerResponseHandler::readFile(std::string location, bool readBinary) {
    log.logNotice("ReadFile", "Starting to read file www/" + location);
    std::string fileContent;
    if (readBinary) {
        std::ifstream fin("www/" + location, std::ios::in | std::ios::binary);
        std::ostringstream oss;
        oss << fin.rdbuf();
        fileContent = oss.str();
    } else {
        std::ifstream stream;
        std::string regel;
        stream.open("www/" + location);

        while (getline(stream, regel)) {
            fileContent += regel;
        }
        stream.close();
    }
    log.logNotice("ReadFile", "Done reading file");
    return fileContent;
}

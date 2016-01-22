#include <iostream>
#include <iostream>
#include "WebServerGetHandler.hpp"

WebServerGetHandler::WebServerGetHandler() {
}

std::string WebServerGetHandler::getGetPrefix() {
    return getPrefix;
}

void WebServerGetHandler::parseGetLine(std::string line) {
    std::string fName = line.substr(getPrefix.length());
    fName = fName.substr(0, fName.find(" "));

    if (fName.empty()) {
        filename = "index";
        extension = "html";
    } else {
        filename = fName.substr(0, fName.find("."));
        extension = fName.substr(fName.find(".") + 1);
    }

    std::cout << "[GET HANDLER line:36] filename: " << filename << " extension: " << extension << std::endl;
}

std::string WebServerGetHandler::getFilename() {
    return filename;
}

std::string WebServerGetHandler::getFileExtension() {
    return extension;
}

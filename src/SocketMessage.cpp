#include "SocketMessage.hpp"

SocketMessage::SocketMessage() {
}

SocketMessage::~SocketMessage() {
}

bool SocketMessage::parseJSONString(std::string jsonString) {
    const char* c = jsonString.c_str();
    rapidjson::ParseResult ok = json.Parse(c);
    bool success;
    if (ok) {
        success = true;
    } else {
        success = false;
    }
    return success;
}

std::string SocketMessage::getJSONString() {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    json.Accept(writer);

    const char* output = buffer.GetString();

    if (output != nullptr) {
        std::string str(output);
        return str;
    }
    std::string str;
    return str;
}

rapidjson::Document& SocketMessage::getJSON() {
    return json;
}


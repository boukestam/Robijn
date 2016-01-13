#include "SocketMessage.hpp"

SocketMessage::SocketMessage() {
}

//SocketMessage::SocketMessage(std::string jsonString) {
//    const char* c = jsonString.c_str();
//    json.Parse(c);
//}
//
//SocketMessage::SocketMessage(rapidjson::Document json) {
//
//}

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

void SocketMessage::setValue(std::string key, std::string value) {
    rapidjson::Value v;
    v.SetString(rapidjson::StringRef(value.c_str()));
    json.AddMember(rapidjson::StringRef(key.c_str()), v, json.GetAllocator());
}

void SocketMessage::generateMessage() {
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);

    writer.StartObject();
    writer.Key("event");
    writer.String("washingProgramList");
    writer.Key("washingPrograms");
    writer.StartArray();
    for (unsigned i = 0; i < 2; i++) {
        std::string key("Washing program ");
        key.append(std::to_string(i));
        writer.Key(key.c_str());
        writer.StartArray();
        for (unsigned j = 0; j < 2; j++) {
            std::string key = std::to_string(j);
            writer.Key(key.c_str());
            writer.StartArray();
            for (unsigned k = 0; k < 1; k++) {
                writer.Key("degrees");
                writer.Uint(60);
                writer.Key("rpm");
                writer.Uint(1800);
            }
            writer.EndArray();
        }
        writer.EndArray();
    }
    writer.EndArray();
    writer.EndObject();

    json.Parse(s.GetString());
}


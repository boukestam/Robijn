#pragma once

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

class SocketMessage{
public:
	SocketMessage();
	//SocketMessage(std::string jsonString);
	//SocketMessage(rapidjson::Document json);

	~SocketMessage();

	bool parseJSONString(std::string jsonString);

	std::string getJSONString();
	rapidjson::Document& getJSON();

	template <typename T>
	T getValue(std::string& key) { // Only works for strings for now
        const char* c = key.c_str();

        rapidjson::Value::ConstMemberIterator itr = json.FindMember(c);
        if (itr != json.MemberEnd()) {
            printf("%s\n", itr->value.GetString());
            return itr->value.GetString();
        }

	};

	void setValue(std::string key, std::string value);

	void generateMessage();

	void generateStatusUpdateMessage(int status);

	void generateWashingProgramsMessage();

private:
	rapidjson::Document json;
};

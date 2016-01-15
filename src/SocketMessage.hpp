#pragma once

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

class SocketMessage{
public:
	SocketMessage();
	~SocketMessage();

	bool parseJSONString(std::string jsonString);

	std::string getJSONString();
	rapidjson::Document& getJSON();

private:
	rapidjson::Document json;
};

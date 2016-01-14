#pragma once

#include <string>

#include "rapidjson/document.h"

class SocketMessage{
public:
	SocketMessage();
	SocketMessage(std::string jsonString);
	SocketMessage(rapidjson::Document json);
	
	std::string getJSONString();
	rapidjson::Document getJSON();
	
	template <typename T>
	T getValue(std::string key);
	
	void setValue(std::string key, std::string value);
	
private:
	rapidjson::Document json;
};
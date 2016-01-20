#pragma once

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

/**
 * @class SocketMessage
 * @author Mathijs van Bremen
 * @date 20/01/16
 * @file SocketMessage.hpp
 * @brief This class is used to send data over from client to server
 */
class SocketMessage{
public:
/**
 * @brief Constructor for SocketMessage
 */
	SocketMessage();

/**
 * @brief Parses given JSON string into a rapidjson::Document
 * @brief Returns boolean indicating whether or not parsing was successful
 * @param jsonString String that has to be parsed
 */
	bool parseJSONString(std::string jsonString);

/**
 * @brief Returns the JSON string
 */
	std::string getJSONString();

/**
 * @brief Returns a reference to the rapidjson::Document
 */
	rapidjson::Document& getJSON();

private:
	rapidjson::Document json;
};

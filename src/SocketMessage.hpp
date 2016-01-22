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
	//! Constructor for SocketMessage
	SocketMessage();
	
	//! Copy constructor
	SocketMessage(const SocketMessage& message);
	
	//! Assignment operator
	SocketMessage& operator=(const SocketMessage& message);

	//! Parses given JSON string into a rapidjson::Document
	//! Returns boolean indicating whether or not parsing was successful
	bool parseJSONString(std::string jsonString);

	//! Returns the JSON string
	std::string getJSONString();

	//! Returns a reference to the rapidjson::Document
	rapidjson::Document& getJSON();

private:
	//! The rapidjson::Document that holds the JSON data
	rapidjson::Document json;
};

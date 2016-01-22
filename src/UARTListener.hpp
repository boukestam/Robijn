#pragma once

#include "UARTMessage.hpp"

/**
 * @class UARTListener
 * @author Bouke Stam
 * @date 20/01/16
 * @file UARTListener.hpp
 * @brief Interface implemented by classes that send messages to the UART
 */
 
class UARTListener{
public:
	//! Callback method to send response to when received
	virtual void responseReceived(UARTMessage response);
};

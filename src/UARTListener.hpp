#pragma once

#include "UARTMessage.hpp"

class UARTListener{
public:
	virtual void responseReceived(UARTMessage response);
};
#pragma once

#include "UARTInterface.hpp"
#include "UARTListener.hpp"

class HardwareComponent: public UARTListener{
public:
	void responseReceived(UARTMessage response) override;

protected:
	UARTInterface uartInterface;
};
#include <iostream>
#include <iostream>
#include "SoapTray.hpp"

SoapTray::SoapTray(UARTInterface* uartInterface):
	HardwareComponent(uartInterface)
{}

void SoapTray::open(){
	UARTMessage message(SOAP_DISPENSER_REQ, OPEN_CMD, this);

	uartInterface->send(message);
}

void SoapTray::close(){
	UARTMessage message(SOAP_DISPENSER_REQ, CLOSE_CMD, this);

	uartInterface->send(message);
}

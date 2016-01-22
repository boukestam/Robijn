#pragma once

#include "HardwareComponent.hpp"

/**
 * @class SoapTray
 * @author Bouke Stam
 * @date 20/01/16
 * @file SoapTray.hpp
 * @brief Boundary class for the washing machine Soap Tray
 */
 
class SoapTray: public HardwareComponent{
public:
	//! Constructor for SoapTray
	SoapTray(UARTInterface* uartInterface);

	//! Opens the SoapTray, allowing water to flow through
	void open();

	//! Closes the SoapTray, stopping the water flow
	void close();
};

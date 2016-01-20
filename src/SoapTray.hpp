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
/**
 * @brief Constructor for SoapTray
 */
	SoapTray(UARTInterface* uartInterface);

/**
 * @brief Opens the SoapTray, allowing water to flow through
 */
	void open();

/**
 * @brief Closes the SoapTray, stopping the water flow
 */
	void close();
};

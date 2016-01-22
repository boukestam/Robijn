#pragma once

#include "UARTInterface.hpp"
#include "UARTMessage.hpp"
#include "UARTListener.hpp"

/* ----------UART codes------------*/

//Requests

#define MACHINE_REQ 			0x01
#define DOOR_LOCK_REQ 		0x02
#define WATER_VALVE_REQ		0x03
#define SOAP_DISPENSER_REQ	0x04
#define PUMP_REQ				0x05
#define WATER_LEVEL_REQ		0x06
#define HEATING_UNIT_REQ		0x07
#define TEMPERATURE_REQ		0x08
#define SET_RPM_REQ			0x0A
#define GET_RPM_REQ			0x09
#define SIGNAL_LED_REQ		0x0B

//Commands

#define STATUS_CMD			0x01

#define START_CMD				0x10
#define STOP_CMD				0x20

#define LOCK_CMD				0x40
#define UNLOCK_CMD				0x80

#define OPEN_CMD				0x10
#define CLOSE_CMD				0x20

#define ON_CMD					0x10
#define OFF_CMD				0x20

#define EMPTY_CMD				0x00

//Answers

#define HALTED					0x01
#define IDLE					0x02
#define RUNNING				0x04
#define STOPPED				0x08
#define FAILED					0xFF

#define OPENED					0x01
#define CLOSED					0x02
#define LOCKED					0x04

#define ON						0x08
#define OFF					0x10

/*---------------------------------*/

/**
 * @class HardwareComponent
 * @author Bouke Stam
 * @date 20/01/16
 * @file HardwareComponent.hpp
 * @brief Interface class for all hardware components of the washing machine
 */

class HardwareComponent: public UARTListener{
public:
/**
 * @brief Constructor for HardwareComponent
 */ 
	HardwareComponent(UARTInterface* uartInterface);

/**
 * @brief Gets called if UART recieves a response and sends it to the directed sensor
 * @param response The message recieved from UART
 */
	void responseReceived(UARTMessage response) override;

protected:
	UARTInterface* uartInterface;
};

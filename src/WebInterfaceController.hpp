#pragma once

#include "pRTOS.h"
#include <fstream>
#include "SocketServer.hpp"
#include "WebServer.hpp"

#include "WashingProgramController.hpp"

#include "HardwareSensor.hpp"

#include "WashingProgramStatus.hpp"

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include "HardwareListener.hpp"

/**
 * @class WebInterfaceController
 * @author Yorick Schellevis
 * @date 20/01/16
 * @file WebInterfaceController.hpp
 * @brief Controller that handles requests from wesockets
 */

class WebInterfaceController: public RTOS::task, public HardwareListener{
public:

	//! The constructor for the webinterface controller
    WebInterfaceController( WashingProgramController* washingProgramController,
                            HardwareSensor* temperatureSensor,
                            HardwareSensor* waterLevelSensor,
                            HardwareSensor* rotationSensor,
                            HardwareSensor* washingMachineStatusSensor);

	//! The function called by the RTOS library
    void main() override;
    
	//! A function used by the sensors that this class is listening to
	void valueChanged(HardwareSensor* sensor, unsigned char value);
    
	//! This function generates and send a status update to all connected clients
	void GenerateStatusUpdate();

private:

	//! Create an SocketMessage* from the list of loaded washing programs
    SocketMessage createSocketMessageFromWashingList();
    
	//! Loads all the washing programs from disk
	void loadWashingPrograms();

	//! Timer to let the main loop sleep and give resources to other tasks
	RTOS::timer sleepTimer;

	//! The webserver that handles outside http connections
    WebServer* webServer = new WebServer(80, "www/"); // Starts the WebServer on its own thread (.detach)
    
	//! The socket server that handles outside websocket messages
    SocketServer* socketServer = new SocketServer(8081); // Starts the SocketServer on its own thread (.detach)

	//! The controller that can start and stop the washing machine  
	WashingProgramController* washingProgramController;

	//! The temprature sensor it listens to
	HardwareSensor* temperatureSensor;
    
	//! The water level sensor it listens to
	HardwareSensor* waterLevelSensor;
    
	//! The rotation sensor it listens to
	HardwareSensor* rotationSensor;
    
	//! The washing machine status sensor it listens to
	HardwareSensor* washingMachineStatusSensor;
    
	//! The current status of the washing program
	WashingProgramStatus* currentWashingProgramStatus;
    
	//! A list with all the loaded washingprograms the server knows
    std::vector<WashingProgram*> washingPrograms;
};

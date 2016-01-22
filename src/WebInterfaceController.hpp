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

    /**
     * @brief The constructor for the webinterface controller
     * @param washingProgramController The washing program controller that can start and stop the washing machine
     * @param temperatureSensor The temprature sensor of the washing machine
     * @param waterLevelSensor The water sensor of the washing machine
     * @param rotationSensor The rotation sensor of the washing machine
     * @param washingMachineStatusSensor The status sensor of the washing machine
     */
    WebInterfaceController( WashingProgramController* washingProgramController,
                            HardwareSensor* temperatureSensor,
                            HardwareSensor* waterLevelSensor,
                            HardwareSensor* rotationSensor,
                            HardwareSensor* washingMachineStatusSensor);
	/**
	 * @brief The function called by the RTOS library
	 */
    void main() override;
    
    /**
     * @brief A function used by the sensors that this class is listening to
     * @param sensor The sensor wich value just changed
     * @param value The new value of the sensor
     */
	void valueChanged(HardwareSensor* sensor, unsigned char value);
    
    /**
     * @brief This function generates and send a status update to all connected clients 
     */
	void GenerateStatusUpdate();

private:

    /**
     * @brief Create an SocketMessage* from the list of loaded washing programs
     * @return Returns a SocketMessage* with all washing programs saved on the server
     */
    SocketMessage createSocketMessageFromWashingList();
    
    /**
     * @brief Loads all the washing programs from disk
     */
	void loadWashingPrograms();

    /**
     * @brief Timer to let the main loop sleep and give resources to other tasks  
     */
	RTOS::timer sleepTimer;

    /**
     * @brief The webserver that handles outside http connections  
     */
    WebServer* webServer = new WebServer(80, "www/"); // Starts the WebServer on its own thread (.detach)
    
    /**
     * @brief The socket server that handles outside websocket messages
     */
    SocketServer* socketServer = new SocketServer(8081); // Starts the SocketServer on its own thread (.detach)

    /**
     * @brief The controller that can start and stop the washing machine  
     */
	WashingProgramController* washingProgramController;

    /**
     * @brief The temprature sensor it listens to 
     */
	HardwareSensor* temperatureSensor;
    
    /**
     * @brief The water level sensor it listens to 
     */
	HardwareSensor* waterLevelSensor;
    
    /**
     * @brief The rotation sensor it listens to 
     */
	HardwareSensor* rotationSensor;
    
    /**
     * @brief The washing machine status sensor it listens to 
     */
	HardwareSensor* washingMachineStatusSensor;
    
    /**
     * @brief The current status of the washing program
     */
	WashingProgramStatus* currentWashingProgramStatus;
    
    /**
     * @brief A list with all the loaded washingprograms the server knows 
     */
    std::vector<WashingProgram*> washingPrograms;
};

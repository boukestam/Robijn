#include "WebInterfaceController.hpp"

void WebInterfaceController::WebInterfaceController()
{}

void WebInterfaceController::main()
{
    // Maar socketServer
    socketServer = socketServer(8080);
    // Maak webserver
    webServer = WebServer(80, "/www");
    // Maak washing program controller
    washingProgramController = washingProgramController();
    // Maak de sensoren
    temperatureSensor = TemperatureSensor();
    waterLevelSensor = WaterLevelSensor();
    rotationSensor = RotationSensor();
    washingMachineStatusSensor = WashingMachineStatusSensor();
    
    while(true){
        // Kijk of er een was gestart moet worden
        
        // Maak begin status
        
        // Lees de sensoren als er een nieuw bericht is
        
        // Update de waardes op de site
        
    }
}
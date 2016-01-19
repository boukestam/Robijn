#include "pRTOS.h"

#include <iostream>

#include "UARTInterface.hpp"
#include "Door.hpp"
#include "Heating.hpp"
#include "TemperatureSensor.hpp"
#include "Motor.hpp"
#include "RotationSensor.hpp"
#include "Pump.hpp"
#include "Tap.hpp"
#include "WaterLevelSensor.hpp"
#include "SignalLed.hpp"
#include "SoapTray.hpp"
#include "WashingMachine.hpp"
#include "WashingMachineStatusSensor.hpp"
#include "RotationController.hpp"
#include "TemperatureController.hpp"
#include "WebInterfaceController.hpp"
#include "WashingProgramController.hpp"
#include "WaterLevelController.hpp"

int main(){
	
	std::cout << "Came here";
	
	UARTInterface* uartInterface = new UARTInterface();
	

	Door* door = new Door(uartInterface);
	
	Heating* heating = new Heating(uartInterface);
	TemperatureSensor* temperatureSensor = new TemperatureSensor(uartInterface);
	
	Motor* motor = new Motor(uartInterface);
	RotationSensor* rotationSensor = new RotationSensor(uartInterface);
	
	Pump* pump = new Pump(uartInterface);
	Tap* tap = new Tap(uartInterface);
	WaterLevelSensor* waterLevelSensor = new WaterLevelSensor(uartInterface);
	
	SignalLed* led = new SignalLed(uartInterface);
	
	SoapTray* soapTray = new SoapTray(uartInterface);
	
	WashingMachine* washingMachine = new WashingMachine(uartInterface);
	WashingMachineStatusSensor* washingMachineStatusSensor = new WashingMachineStatusSensor(uartInterface);
	
	RotationController* rotationController = new RotationController(motor, rotationSensor);
	TemperatureController* temperatureController = new TemperatureController(heating, temperatureSensor);
	WaterLevelController* waterLevelController = new WaterLevelController(pump, tap, waterLevelSensor);
	
	
		WashingProgramController* washingProgramController = new WashingProgramController(waterLevelController, rotationController, temperatureController, door, led, washingMachine, washingMachineStatusSensor);

	WebInterfaceController* webInterfaceController = new WebInterfaceController(washingProgramController,
										    temperatureSensor,
										    waterLevelSensor,
										    rotationSensor,
										    washingMachineStatusSensor,
											soapTray);
	
	

	
	
	RTOS::run();
	return 0;
}

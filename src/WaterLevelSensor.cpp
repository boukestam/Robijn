#include "WaterLevelSensor.hpp"

WaterLevelSensor::WaterLevelSensor(UARTInterface* uartInterface):
	HardwareSensor(uartInterface)
{}

void WaterLevelSensor::update(){
	UARTMessage message(WATER_LEVEL_REQ, EMPTY_CMD, this);

	uartInterface->send(message);
}

void WaterLevelSensor::responseReceived(UARTMessage response){
	valueChanged(response.second);
}

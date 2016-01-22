#include <iostream>
#include <iostream>
#include "HardwareComponent.hpp"

HardwareComponent::HardwareComponent(UARTInterface* uartInterface):
	uartInterface(uartInterface)
{}

void HardwareComponent::responseReceived(UARTMessage response){

}

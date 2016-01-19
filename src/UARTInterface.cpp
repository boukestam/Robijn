#include "UARTInterface.hpp"

#include "UARTListener.hpp"

#include <iostream>

UARTInterface::UARTInterface(): 
	RTOS::task(0, "uartInterface"),
	sendBuffer(this, "sendBuffer"), 
	replyTimer(this, "replyTimer")
{
	int status = serial.open("/dev/ttyAMA0", 9600);
	std::cout << "Serial open status: " << status << std::endl;
}

UARTInterface::~UARTInterface(){
	serial.close();
}

void UARTInterface::main(){
	for(;;){
		wait(sendBuffer);
		
		UARTMessage message = sendBuffer.read();
		
		serial.write((void *)&message.first, 2);

		serial.flush();
				
		while(serial.peek() < 2){
			replyTimer.set(10 MS);
			wait(replyTimer);
		}
		
		UARTMessage response;
		serial.read((void *)&response.first, 2);

		serial.flush();

		response.sender = message.sender;
		
		response.sender->responseReceived(response);
	}
}

void UARTInterface::send(UARTMessage message){
	sendBuffer.write(message);
}

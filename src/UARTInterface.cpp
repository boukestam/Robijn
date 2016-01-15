#include "UARTInterface.hpp"

#include "UARTListener.hpp"

UARTInterface::UARTInterface(): 
	RTOS::task(0, "uartInterface"),
	sendBuffer(this, "sendBuffer"), 
	replyTimer(this, "replyTimer")
{
	serial.open("/dev/ttyUSB0", 9600);
}

UARTInterface::~UARTInterface(){
	serial.close();
}

void UARTInterface::main(){
	for(;;){
		wait(sendBuffer);
		
		UARTMessage message = sendBuffer.read();
		
		serial.write((void *)&message.first, 2);
		
		replyTimer.set(10 MS);
		wait(replyTimer);
		
		UARTMessage response;
		serial.read((void *)&response.first, 2);
		response.sender = message.sender;
		
		response.sender->responseReceived(response);
	}
}

void UARTInterface::send(UARTMessage message){
	sendBuffer.write(message);
}

// Jan Zuurbier september 2014
// De broadcaster is thread-safe gemaakt.
// Dit is nodig omdat verschillende threads hier
// mogelijk tegelijkertijd gebruik van maken.

#include "WebSocketMulticaster.h"

Multicaster::Multicaster()
{
}

Multicaster::~Multicaster()
{
}

void Multicaster::add(WebSocket* ws){
	std::lock_guard<std::mutex> lock(mutex);
	theList.push_back(ws);
}

void Multicaster::remove(WebSocket* ws){
	std::lock_guard<std::mutex> lock(mutex);
	theList.remove(ws);
}

void Multicaster::broadcast(const string& message){
	std::lock_guard<std::mutex> lock(mutex);
	for (std::list<WebSocket*>::iterator it=theList.begin(); it!=theList.end(); ++it)
		(*it)->sendTextMessage(message);
}



// Jan Zuurbier september 2014
// De broadcaster is thread-safe gemaakt.
// Dit is nodig omdat verschillende threads hier
// mogelijk tegelijkertijd gebruik van maken.


#ifndef BROADCASTER_H
#define BROADCASTER_H

#include "WebSocket.h"
#include <list>
#include <mutex>

class Multicaster
{
public:
	Multicaster();
	~Multicaster();
	void add(WebSocket* ws);
	void remove(WebSocket* ws);
	void broadcast(const string& message);

private:
	list<WebSocket*> theList;
	std::mutex   mutex;  // Mutex for list locking
};

#endif // BROADCASTER_H

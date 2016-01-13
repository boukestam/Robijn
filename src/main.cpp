#include "WebServer.hpp"
#include "SocketServer.hpp"
#include <thread>

int main(){
    WebServer* webServer = new WebServer(8080, "www/"); // Starts the WebServer on its own thread (.detach)
    SocketServer* socketServer = new SocketServer(8081); // Starts the SocketServer on its own thread (.detach)

    for(;;) {
    }

	return 0;
}

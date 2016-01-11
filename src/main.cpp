#include "WebServer.hpp"
#include <thread>

int main(){
    WebServer *webServer = new WebServer(8080, "C:/directory/bla"); // Starts the WebServer on its own thread (.detach)

    for(;;) {
    }

	return 0;
}

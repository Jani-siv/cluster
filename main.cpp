#include "server.h"
#include <thread>
int main()
{
    //class for server
    server newServer;
    //thread taking incoming traffic
    std::thread testThread(&server::acceptCall,newServer);
    //join thread
    testThread.join();

    return 0;
}

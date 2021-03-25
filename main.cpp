#include "server.h"
int main()
{
    server *firstServer = new server();
    firstServer->acceptCall();
    return 0;
}

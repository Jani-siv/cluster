#ifndef CLIENTCONTAINER_H
#define CLIENTCONTAINER_H
#include <vector>
#include <mutex>
#include "clientClass.h"
#include <time.h>
#include <iostream>

class clientContainer
{
private:
    /* data */
    const long timeout = 20;
protected:
    std::vector<clientClass> clients;
    std::mutex mylock;
public:
    
    clientContainer(/* args */);
    ~clientContainer();
    //add new class and vector
    int addClient(char *hostname, int clientSocket, int connections);
    //return amount of connections
    int removeClient(int position, int connections);
    //for menu iterate vector
    void showActiveClients();
    //time out return new connections number
    int checkClientTimeOut(int connectionsNumber);
    int getClientSocket(int position);
    void setTimeStamp(int position);
    void checkAliveClient();
    void createClientThread();
    void readClientMessages();
    
};



#endif
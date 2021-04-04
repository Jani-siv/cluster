#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H
#include <iostream>
#include <thread>
#include <time.h>
#include <thread>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
class clientClass
{
    private:
    //connection id
    int socketId;
    time_t onlineTimestamp;
    char* Hostname;
    int online;
    char request[10];
    int serverListening = 0;

    public:
    clientClass(char* hostName, int socketId);
    ~clientClass();
    void setTimestamp();
    void setSocketId(int socketId);
    void setHostName(char* hostname);
    time_t getTimestamp();
    int getSocketId();
    void setOffline();
    void listenClientMessages();
    void createThread();
    void setListening();
    int getListening();
    int getStatus();
    void setOnline();
    char* getHostname();
};


#endif
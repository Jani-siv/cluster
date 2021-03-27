#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H
#include <iostream>
#include <thread>
#include <time.h>
class clientClass
{
    private:
    //connection id
    int socketId;
    time_t onlineTimestamp;
    std::string Hostname;
    int online = 1;

    public:
    clientClass(std::string hostName, int socketId);
    ~clientClass();
    void setTimestamp();
    void setSocketId(int socketId);
    void setHostName(std::string hostname);
    time_t getTimestamp();
    int getSocketId();
    void setOffline();
};


#endif
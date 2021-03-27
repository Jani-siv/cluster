#include "clientClass.h"
clientClass::clientClass(std::string hostName, int socketId)
{
    clientClass::setTimestamp();
    std::cout<<"Client object created at:"<<this->onlineTimestamp<<std::endl;
    clientClass::setSocketId(socketId);
    clientClass::setHostName(hostName);

}

clientClass::~clientClass()
{

}
void clientClass::setTimestamp()
{
    time(&this->onlineTimestamp);
}
void clientClass::setSocketId(int socketId)
{
 this->socketId = socketId;
}
void clientClass::setHostName(std::string hostname)
{
 this->Hostname = hostname;
}
time_t clientClass::getTimestamp()
{
    return this->onlineTimestamp;
}
int clientClass::getSocketId()
{
    return this->socketId;
}
void clientClass::setOffline()
{
    this->online = 0;
}
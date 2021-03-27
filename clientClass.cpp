#include "clientClass.h"
clientClass::clientClass(std::string hostName, int socketId)
{
    clientClass::setTimestamp();
    std::cout<<"Client object created at:"<<this->onlineTimestamp<<std::endl;
    clientClass::setSocketId(socketId);
    clientClass::setHostName(hostName);
   // clientClass::createThread();
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
void clientClass::createThread()
{
 std::thread listen(&clientClass::listenClientMessages,this);
 listen.join();
}
void clientClass::listenClientMessages()
{
    this->setListening();
    char* p_buffer = this->request;

    while(this->online == 1)
    {
     read(this->socketId,p_buffer,sizeof(this->request));
     std::cout<<"i did read your message"<<std::endl;
        time(&this->onlineTimestamp);
    }
    std::cout<<this->request<<std::endl;
}

void clientClass::setListening()
{
    this->serverListening = 1;
}
int clientClass::getListening()
{
    return this->serverListening;
}
int clientClass::getStatus()
{
    return this->online;
}
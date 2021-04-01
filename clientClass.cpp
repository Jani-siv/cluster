#include "clientClass.h"
clientClass::clientClass(char* hostName, int socketId)
{
    this->setTimestamp();
    this->setOnline();
    std::cout<<"Client object created at:"<<this->onlineTimestamp<<std::endl;
    this->setSocketId(socketId);
    this->setHostName(hostName);
}

clientClass::~clientClass()
{

}

void clientClass::setOnline()
{
    this->online = 1;
}
void clientClass::setTimestamp()
{
    time(&this->onlineTimestamp);
    std::cout<<"new timestamp set: "<<this->onlineTimestamp<<std::endl;
}
void clientClass::setSocketId(int socketId)
{
 this->socketId = socketId;
}
void clientClass::setHostName(char* hostname)
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
    std::cout<<"my thread is set offline"<<std::endl;
}
void clientClass::createThread()
{
 std::thread listen(&clientClass::listenClientMessages,this);
 listen.join();
}
void clientClass::listenClientMessages()
{
    std::cout<<"this thread ID: "<<std::this_thread::get_id()<<std::endl;
    this->setListening();
    char* p_buffer = this->request;

    while(this->online == 1)
    {
     read(this->socketId,p_buffer,sizeof(this->request));
     std::cout<<"i did read your message and my online timeStamp is: "<<this->onlineTimestamp<<" client socketId: "<<this->getSocketId()<<std::endl;
        if (this->online == 1)
        {
        this->setTimestamp();
        }
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
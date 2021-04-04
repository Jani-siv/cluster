#include "clientContainer.h"

clientContainer::clientContainer(/* args */)
{
}

clientContainer::~clientContainer()
{
}

int clientContainer::addClient(char *hostname, int clientSocket, int connections)
{
    //new class for new client
clientClass newClient(hostname, clientSocket);
//lock before use vector
this->mylock.lock();
std::cout<<"lock for new client"<<std::endl;
this->clients.push_back(newClient);
//unlock
this->mylock.unlock();
std::cout<<"unlock for new client"<<std::endl;
return connections++;
}

int clientContainer::removeClient(int position, int connections)
{
    if (connections != 0)
    {
    std::cout<<"position to remove: "<<position<<" amount of vectors: "<<this->clients.size()<<std::endl;
    if (position == this->clients.size())
    {
        
        position --;
    }
    std::cout<<"lock for remove client"<<std::endl;
    this->mylock.lock();
    std::cout<<"continue"<<std::endl;
    int socket = this->clients.at(position).getSocketId();
    std::cout<<"get socket"<<std::endl;
    close(socket);
    std::cout<<"close socket"<<std::endl;
    this->clients.at(position).~clientClass();
    std::cout<<"remove client class"<<std::endl;
    this->clients.erase(this->clients.begin()+position);
    std::cout<<"lock for remove vector"<<std::endl;
    this->mylock.unlock();
    std::cout<<"unlock for remove client"<<std::endl;
    connections--;
    return connections;
    }
}

void clientContainer::showActiveClients()
{
    std::cout<<"lock for show active clients"<<std::endl;
    this->mylock.lock();
        for (auto active : clients)
    {
        time_t lastactivity = active.getTimestamp();
        time_t now;
        time(&now);
        now = now - lastactivity;
        std::cout<<"address: "<<active.getHostname()<<" Socket: "<<active.getSocketId()<<" Last activity: "
        <<" seconds ago"<<std::endl;
    }
    this->mylock.unlock();
    std::cout<<"unlock for show active clients"<<std::endl;
}

int clientContainer::checkClientTimeOut(int connectionsNumber)
{
    if (connectionsNumber != 0)
    {
    time_t timestamp;
    time(&timestamp);
    int position = 0;
    int remove = 0;
    std::cout<<"lock for check timeout"<<std::endl;
    this->mylock.lock();
    std::cout<<"lock for check timeout"<<std::endl;
    this->clients.rbegin();
   // for (auto client : this->clients)
      for (int i = 0; i < this->clients.size(); i++)
        {
            long clientTimestamp = this->clients.at(i).getTimestamp();
            std::cout<<"client timestamp: "<<this->clients.at(i).getTimestamp()<<" client socketID: "<<this->clients.at(i).getSocketId()<<std::endl;
            if (clientTimestamp <= timestamp-this->timeout )
            {
               // connectionsNumber = this->removeClient(position, connectionsNumber);
                int socketID = this->clients.at(i).getSocketId();
                connectionsNumber--;
                close(socketID);
                //this->clients.erase(this->clients.begin()+position);
                remove = position;
            }
            position++;
        }
        this->clients.rbegin();
    this->mylock.unlock();
    std::cout<<"unlock for check timeout"<<std::endl;
    return position;
    }
return -1;
}
int clientContainer::getClientSocket(int position)
{
    std::cout<<"lock for get socket"<<std::endl;
    mylock.lock();
    int socket = clients.at(position).getSocketId();
    mylock.unlock();
    std::cout<<"unlock for get socket"<<std::endl;
    return socket;
}

void clientContainer::setTimeStamp(int position)
{
    std::cout<<"lock for set timestamp"<<std::endl;
    mylock.lock();
    clients.at(position).setTimestamp();
    mylock.unlock();
    std::cout<<"unlock for set timestamp"<<std::endl;

}
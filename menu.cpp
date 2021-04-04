#include "menu.h"
menu::menu(/* args */)
{
}

menu::~menu()
{
}

int menu::showMenu()
{
    int command;
    std::cout<<"Menu"<<std::endl;
    std::cout<<"1 show active nodes"<<std::endl;
    std::cout<<"2 send commands to nodes"<<std::endl;
    std::cout<<"3 update nodes"<<std::endl;
    std::cout<<"4 shutdown server"<<std::endl;
    std::cout<<"$$: ";
    std::cin>>command;
    return command;
}

void menu::showActiveClients(std::vector<clientClass>clients, int connections)
{
    if (connections <= 0)
    {
        std::cout<<"No active clients"<<std::endl;
    }
    if (connections > 0)
    {
    std::cout<<"***Active clients***"<<std::endl;
    for (auto active : clients)
    {
        //time_t lastactivity = active.getTimestamp();
        //time_t now;
        //time(&now);
        //now = now - lastactivity;
        std::cout<<"address: "<<active.getHostname()<<" Socket: "<<active.getSocketId()<<" Last activity: "
        <<" seconds ago"<<std::endl;
    }
    }
}
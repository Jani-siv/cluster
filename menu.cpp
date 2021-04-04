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

int menu::showActiveClients(int connections)
{
    if (connections <= 0)
    {
        std::cout<<"No active clients"<<std::endl;
        return 0;
    }
    if (connections > 0)
    {
        return 1;
    }
    return 0;
}
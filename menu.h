#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "clientClass.h"
#include <vector>
#include <time.h>
class menu
{
private:
    /* data */
public:
    menu(/* args */);
    ~menu();
    int showMenu();
    void showActiveClients(std::vector<clientClass>clients, int connections);
};


#endif
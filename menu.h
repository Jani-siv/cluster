#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "clientClass.h"
#include <vector>
#include <time.h>
#include "neural.h"
class menu
{
private:
    /* data */
public:
    menu(/* args */);
    ~menu();
    int showMenu();
    int showActiveClients(int connections);
    void runNeural();
};


#endif
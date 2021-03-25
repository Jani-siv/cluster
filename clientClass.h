#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H
#include <iostream>
#include <thread>
class clientClass
{
    public:
    void setConnectionId(int id);
    clientClass();
    ~clientClass();
    private:
    int connectionId;
    int threadId;
};


#endif
#ifndef SERVER_H
#define SERVER_H
#define SERVER_PORT 2500
//error numbers
// -1 cannot create socket


#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <thread>
#include <iostream>
#include "clientClass.h"
#include <pthread.h>
#include "menu.h"
#include <vector>
#include "time.h"

class server
{
    public:
    sockaddr_in client;
    socklen_t clientsize = sizeof(client);

private:
//error handling
menu *serverMenu = new menu;

std::vector<clientClass> clientContainer; 
int errorNumber = 0;
bool runServer = true;
int clientId = 0;
//mitä serverin täytyy säilyttää
//socket address struct hint
sockaddr_in hint;
//client object
int connectionId[100];
int aliveConnection[100];
int connectionsNumber =0;
int command = 0;
//socket
int listening;
//ip address
std::string address = "0.0.0.0";
//client socket 
 int clientSocket;
 //client address
    /* data */
public:
    server(/* args */);
    ~server();
    //error handling
    int checkError();
    //create socket
    void createSocket();
    //bind the socket to a ip / port
    void bindTheSocket();
    //mark the socket for listening in
    void markSocketToListening();
    //accept a call
    void acceptCall();

    //while receive display message echo message
    //close socket
    void startServer();
    void startMenu();
    void setConnectionId(int clientSocket);
  //  void menu();
    void executeCommand();
    void killConnection();
    void checkAliveClient();
};


#endif
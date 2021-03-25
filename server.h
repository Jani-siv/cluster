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

class server
{
    public:
    sockaddr_in client;
    socklen_t clientsize = sizeof(client);

private:
//error handling
int errorNumber = 0;
bool runServer = true;
//mitä serverin täytyy säilyttää
//socket address struct hint
sockaddr_in hint;
//client object
int connectionId[100];
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
    //handle connection
    void handleConnection();
    //while receive display message echo message
    //close socket

    void setConnectionId(int clientSocket);
    void menu();
    void setCommand(int command);

};


#endif
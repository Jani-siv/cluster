#include "server.h"
#include <iostream>

server::server(/* args */)
{
    server::createSocket();
    server::bindTheSocket();
    server::markSocketToListening();
    //set all connections to 0
    memset(server::connectionId,0,sizeof(server::connectionId));
}

server::~server()
{
}
// return 0 if no errors
int server::checkError()
{
    if (server::errorNumber != 0)
    {
        return 1;
    }
    else 
        return 0;
}

void server::setConnectionId(int clientSocket)
{
    this->connectionId[this->connectionsNumber] = clientSocket;
    this->connectionsNumber++;
    std::cout<<"New connection added: "<<clientSocket<<std::endl;
}
void server::createSocket()
{
    if (this->checkError() == 0)
    {

    
    server::listening = socket(AF_INET, SOCK_STREAM,0);
    if (server::listening == -1)
    {
        std::cout<<"cannot create socket!"<<std::endl;
        server::errorNumber = -1;
        
    }
    std::cout<<"Socket created succesfully!"<<std::endl;
    }
    else
    std::cout<<"error before creating socket"<<std::endl;
}

void server::bindTheSocket()
{
       if (this->checkError() == 0)
    {
    this->hint.sin_family = AF_INET;
    //change endian using command htons()
    this->hint.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "0.0.0.0",&this->hint.sin_addr);
    if (bind(listening,(sockaddr*)&this->hint,sizeof(this->hint)))
    {
        std::cout<<"error bind ip to port"<<std::endl;
        server::errorNumber = -2;
    }
    std::cout<<"IP and port binded"<<std::endl;
    }
    else 
    std::cout<<"Error before bind ip to port"<<std::endl;
}

void server::markSocketToListening()
{
    if (listen(this->listening, SOMAXCONN) == -1)
    {
        std::cout<<"cant listening port"<<std::endl;
        server::errorNumber = -3;
    }
    else
    std::cout<<"server listening"<<std::endl;
}

void server::acceptCall()
{
    while(true)
    {
    std::cout<<"Waiting connections"<<std::endl;
    //client socket number is unique
    this->clientSocket = accept(this->listening,(sockaddr*)&this->client,&this->clientsize);

    if (clientSocket == -1)
    {
        std::cout<<"Error with client connection"<<std::endl;
        server::errorNumber = -4;
    }
    this->setConnectionId(clientSocket);
    }
}
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

    //left here only listening part and move all others in own thread
    //message to connecting client
    char data[1025] = "hello this is server";
    while(this->runServer == true)
    {
    //remove all messages to gui
    std::cout<<"Waiting connections"<<std::endl;
    //client socket number is unique
    //thread to get commands from server move this also
    this->clientSocket = accept(this->listening,(sockaddr*)&this->client,&this->clientsize);

    if (clientSocket == -1)
    {
        std::cout<<"Error with client connection"<<std::endl;
        server::errorNumber = -4;
    }

    //register client 
    this->setConnectionId(clientSocket);
    if (this->connectionsNumber >= 2)
    {
        for (int k=0; k<2; k++)
        {
            write(connectionId[k],data,strlen(data));
        }
    }
    }
    
}


void server::startServer()
{
    std::thread t_listener(&server::acceptCall, this);
    std::thread t_menu(&server::startMenu,this);
    t_listener.join();
    t_menu.join();
}

void server::startMenu()
{
while (this->runServer == true)
{
    this->command = this->serverMenu->showMenu();
    this->executeCommand();
}
}

void server::executeCommand()
{
    //show active nodes
    if (this->command == 1) {this->runServer = false;}
    //send command to nodes
    if (this->command == 2) {this->runServer = false;}
    //update nodes
    if (this->command == 3) {this->runServer = false;}
    //kill server
    if (this->command == 4) 
        { 
            this->runServer = false;
            //make connection in server to kill other thread;    
            this->killConnection();
        }
}
void server::killConnection()
{
int obj_socket = 0;
struct sockaddr_in serv_addr;
obj_socket = socket (AF_INET, SOCK_STREAM, 0 );
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(2500);
// Converting IPv4 and IPv6 addresses from text to binary form
inet_pton ( AF_INET, "127.0.0.1", &serv_addr.sin_addr);
connect( obj_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr ));
}
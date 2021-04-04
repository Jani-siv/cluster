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
    while(this->runServer == true)
    {
        int clientSocket = 0;
    //remove all messages to gui
    std::cout<<"Waiting connections"<<std::endl;
    //client socket number is unique
    //thread to get commands from server move this also
    clientSocket = accept(this->listening,(sockaddr*)&this->client,&this->clientsize);

        if (clientSocket == -1)
            {
            std::cout<<"Error with client connection"<<std::endl;
            server::errorNumber = -4;
             }
        else
            {
            // get client ip addr
            getpeername(clientSocket,(sockaddr*)&this->client,&this->clientsize);
            //shout out hostname
            char *hostname = inet_ntoa(this->client.sin_addr);
            std::cout<<"New connection from: "<<hostname<<std::endl;
            
            //class for connection hostname and socket
            clientClass newClientConnection(hostname, clientSocket);
            //set client socket in poll
            this->fds[this->connectionsNumber].fd = clientSocket;

            this->setConnectionId(clientSocket);
            //push connection class to client container
            this->clientContainer.push_back(newClientConnection);
           
            }
    }
    //close all sockets
    for (int i =0; i < this->connectionsNumber; i++)
    {
        close(this->connectionId[i]);
        std::cout<<"connection id: "<<this->connectionId[i]<<" is closed"<<std::endl;

    }
    
}


void server::startServer()
{
    if(this->errorNumber >= 0)
    {
    //incoming connections thread
    std::thread t_listener(&server::acceptCall, this);
    //menu thread
    std::thread t_menu(&server::startMenu,this);
    //init client container
    this->killConnection();
    //check alive clients thread
    std::thread t_alive(&server::checkAliveClient,this);
    //start listening incoming clients **this kind thread wont work***
    std::thread t_readMessages(&server::readClientMessages,this);
    t_readMessages.join();
    t_listener.join();
    t_menu.join();
    t_alive.join();
    std::cout<<"server is down"<<std::endl;
    }
    else
    std::cout<<"Error to start server code: "<<this->errorNumber<<std::endl;
}

void server::startMenu()
{
//waiting other threads
std::this_thread::sleep_for(std::chrono::seconds(1));

while (this->runServer == true)
{
    this->command = this->serverMenu->showMenu();
    this->executeCommand();
}
}

void server::executeCommand()
{
    //show active nodes
    if (this->command == 1) 
    {
        this->serverMenu->showActiveClients(this->clientContainer, this->connectionsNumber);
    }
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

void server::checkAliveClient()
{
    //waiting other threads
    std::this_thread::sleep_for(std::chrono::seconds(2));
        
    time_t clientTimestamp;
    while(this->runServer == true)
    {
    //check client timestamp
    time_t timestamp;
    char message[] = "time out";
    char* connectionTimeOut = message;
    time(&timestamp);
    int position = 0;
    timestamp -= 20;
    //connection timeout

        for (auto client : this->clientContainer)
        {
            clientTimestamp = client.getTimestamp();
            std::cout<<"client timestamp: "<<client.getTimestamp()<<" client socketID: "<<client.getSocketId()<<std::endl;
            if (clientTimestamp <= timestamp )
            {
                int socketID = client.getSocketId();
                //set offline to kill thread inside client
                client.setOffline();
                std::cout<<"client Status is: "<<client.getStatus()<<std::endl;
                //send message to kill thread
                send(socketID,connectionTimeOut,sizeof(connectionTimeOut),0);
                //close socket
                //wait until thread is killed in client
                //std::this_thread::sleep_for(std::chrono::seconds(2));
                this->connectionsNumber--;
                close(client.getSocketId());
                this->clientContainer.erase(this->clientContainer.begin()+position);
                

                //delete object and delete from vector this object
            }
            position++;
        }
    //break for 5 seconds before next check
    std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}
void server::readClientMessages()
{
    
    std::cout<<"thread what read client messages"<<std::endl;
    char message[100];
    char* pmessage = message;
    char answer[100] = "welcome";
    char* panswer = answer;
    char quit[100] = "Q";
    char* pquit = quit;
    while(this->runServer == true)
    {
        if (this->connectionsNumber >= 0)
        {
            for(int i =0; i < this->connectionsNumber+1; i++)
            {
                this->fds[i].events = POLLIN;
            }
            this->ret = poll(this->fds,this->connectionsNumber+1,this->timeout_msecs);
            if (this->ret > 0)
            {
                for (int i = 0; i < this->connectionsNumber+1; i++)
                {
                    if(this->fds[i].revents & POLLIN)
                    {
                        read(this->clientContainer.at(i).getSocketId(),pmessage,sizeof(message));
                        this->clientContainer.at(i).setTimestamp();
                        // do something with message
                        std::cout<<message[0]<<std::endl;
                        if (message[0] == 'C')
                        {
                            std::cout<<"Sending message!!!"<<std::endl;
                            send(this->clientContainer.at(i).getSocketId(),panswer,sizeof(answer),0);
                        }
                        if (message[0] == 'Q')
                        {
                            std::cout<<"Sending message!!!"<<std::endl;
                            send(this->clientContainer.at(i).getSocketId(),pquit,sizeof(quit),0);
                            //close client port
                            close(this->clientContainer.at(i).getSocketId());
                            // - client count
                            this->connectionsNumber--;
                            //remove object
                            this->clientContainer.at(i).~clientClass();
                            //remove client from container
                            this->clientContainer.erase(this->clientContainer.begin()+i);
                        }
                        memset(message,0,sizeof(message));
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
     }
       
}

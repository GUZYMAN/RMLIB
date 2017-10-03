#ifndef _server_h_
#define _server_h_

#include <iostream>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>

#include "mythread.h"
#include "client.h"
#include "list"

#define PORT 8888

using namespace std;

class Server {

private:
    static vector<Client> clients;

    //Socket stuff
    int serverSock, clientSock;
    struct sockaddr_in serverAddr, clientAddr;
    char buff[256];

public:
    Server();
    void AcceptAndDispatch();
    static void * HandleClient(void *args);
    static std::string bufferToString(char* buffer, int bufflen);
    static list<string> parser(std::string str);
    static void createNodo(list<string> lista);

private:
    static void ListClients();
    static void SendToAll(char *message);
    static int FindClientIndex(Client *c);
};

#endif
#ifndef RMLIB_LIBRARY_H
#define RMLIB_LIBRARY_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <vector>
#include "rmRef_h.h"
#include "list"

using namespace std;

class TCPClient
{
private:
    int sock;
    std::string address;
    int port;
    struct sockaddr_in server;

public:
    TCPClient(){
        sock = -1;
        port = 0;
        address = "";
    }
    void rm_init(string address, int port){
        if(sock == -1)
        {
            sock = socket(AF_INET , SOCK_STREAM , 0);
            if (sock == -1)
            {
                cout << "Could not create socket" << endl;
            }
        }
        if(inet_addr(address.c_str()) == -1)
        {
            struct hostent *he;
            struct in_addr **addr_list;
            if ( (he = gethostbyname( address.c_str() ) ) == NULL)
            {
                herror("gethostbyname");
                cout<<"Failed to resolve hostname\n";
            }
            addr_list = (struct in_addr **) he->h_addr_list;
            for(int i = 0; addr_list[i] != NULL; i++)
            {
                server.sin_addr = *addr_list[i];
                break;
            }
        }
        else
        {
            server.sin_addr.s_addr = inet_addr( address.c_str() );
        }
        server.sin_family = AF_INET;
        server.sin_port = htons( port );
        if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            perror("connect failed. Error");
        }
    }
    void rm_new(char* key, void* value, int value_size){
        string dataToSend;
        string delim = "&";
        string header = "1";

        dataToSend = header + delim + key + delim + std::to_string(*(int*) value) + delim + std::to_string(value_size) + delim;
        Send(dataToSend);

    }

    rmRef_h rm_get(char* key){
        list<string> lista;
        rmRef_h nodo;
        string dataToSend;
        string delim = "&";
        string header = "2";
        dataToSend = header + delim + key + delim;
        Send(dataToSend);
        string rec = receive();
        lista = parser(rec);
        nodo.setLlave(lista.front());
        lista.pop_front();
        nodo.setValue(lista.front());
        lista.pop_front();
        nodo.setValue_size(lista.front());
        lista.pop_front();
        return nodo;
    }
    void rm_delete(rmRef_h* handler){
        string dataToSend;
        string delim = "&";
        string header = "3";
        dataToSend = header + delim + handler->getLlave() + delim;
        Send(dataToSend);
        cout << "Nodo con la llave: " + handler->getLlave() + " eliminado" << endl;
    }

    bool Send(string data){
        if( send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0)
        {
            cout << "Send failed : " << data << endl;
            return false;
        }
        return true;
    }
    string receive(int size = 4096){
        list<string> lista;
        char buffer[size];
        string reply;
        if( recv(sock , buffer , size, 0) < 0)// sizeof(buffer)
        {
            cout << "receive failed!" << endl;
        }
        buffer[size]='\0';
        reply = buffer;
        return reply;
    }

    string read(){
        char buffer[1] = {};
        string reply;
        while (buffer[0] != '\n') {
            if( recv(sock , buffer , sizeof(buffer) , 0) < 0)
            {
                cout << "receive failed!" << endl;
                break;
            }
            reply += buffer[0];
        }
        return reply;
    }
    list<string> parser(std::string s){
        std::string delimiter = "&";
        list<string> lista;
        list<string> lista2;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            lista.push_back(token);
            //std::cout << token << std::endl;
            s.erase(0, pos + delimiter.length());
        }
        lista2 = lista;

        return lista2;
    }
};


#endif //PSERVER_LIBRARY.H
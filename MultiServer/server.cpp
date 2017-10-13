#include "server.h"
#include "NodeMem.cpp"
#include "list.h"
#include "garbageCollector.h"
#include <list>

using namespace std;

//Actually allocate clients
vector<Client> Server::clients;

Server::Server() {

    //Initialize static mutex from MyThread
    MyThread::InitMutex();

    //For setsock opt (REUSEADDR)
    int yes = 1;

    //Init serverSock and start listen()'ing
    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serverAddr, 0, sizeof(sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    //Avoid bind error if the socket was not close()'d last time;
    setsockopt(serverSock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));

    if(bind(serverSock, (struct sockaddr *) &serverAddr, sizeof(sockaddr_in)) < 0)
        cerr << "Failed to bind";

    listen(serverSock, 5);
}

/*
	AcceptAndDispatch();
	Main loop:
		Blocks at accept(), until a new connection arrives.
		When it happens, create a new thread to handle the new client.
*/
void Server::AcceptAndDispatch() {

    Client *c;
    MyThread *t;

    socklen_t cliSize = sizeof(sockaddr_in);

    while(1) {

        c = new Client();
        t = new MyThread();

        //Blocks here;
        c->sock = accept(serverSock, (struct sockaddr *) &clientAddr, &cliSize);

        if(c->sock < 0) {
            cerr << "Error on accept";
        }
        else {
            t->Create((void *) Server::HandleClient, c);
        }
    }
}

//Static
void *Server::HandleClient(void *args) {

    //Pointer to accept()'ed Client
    Client *c = (Client *) args;
    char buffer[256-25], message[256];
    int index;
    int n;

    //Add client in Static clients <vector> (Critical section!)
    MyThread::LockMutex((const char *) c->name);
    garbageCollector *gC;
    gC = new garbageCollector;
    gC->init();


    //Before adding the new client, calculate its id. (Now we have the lock)
    c->SetId(Server::clients.size());
    sprintf(buffer, "Client n.%d", c->id);
    c->SetName(buffer);
    cout << "Adding client with id: " << c->id << endl;
    Server::clients.push_back(*c);

    MyThread::UnlockMutex((const char *) c->name);

    while(1) {
        memset(buffer, 0, sizeof buffer);
        n = recv(c->sock, buffer, sizeof buffer, 0);

        //Client disconnected?
        if(n == 0) {
            cout << "Client " << c->name << " diconnected" << endl;
            close(c->sock);

            //Remove client in Static clients <vector> (Critical section!)
            MyThread::LockMutex((const char *) c->name);

            index = Server::FindClientIndex(c);
            cout << "Erasing user in position " << index << " whose name id is: "
                 << Server::clients[index].id << endl;
            Server::clients.erase(Server::clients.begin() + index);

            MyThread::UnlockMutex((const char *) c->name);

            break;
        }
        else if(n < 0) {
            cerr << "Error while receiving message from client: " << c->name << endl;
        }
        else {
            //Message received. Send to all clients.
            snprintf(message, sizeof message, "<%s>: %s", c->name, buffer);
            string x;
            x = bufferToString(buffer, sizeof(buffer));
            list<string> lista;

            lista = parser(x);
            if (lista.front() == "1"){
                createNodo(lista);

            }
            if(lista.front() == "2"){
                NodeMem rmRef;
                string delim = "&";
                lista.pop_front();
                rmRef = List<NodeMem>::Instance().search(lista.front());
                rmRef.setReferencesPlus();
                string dataToSend;
                dataToSend = rmRef.getKey() + delim + rmRef.getValue() + delim + rmRef.getValue_size() + delim;
                SendToAll(const_cast<char *>(dataToSend.c_str()));

            }
            if(lista.front() == "3"){

                lista.pop_front();
                List<NodeMem>::Instance().del_by_data(lista.front());

            }
            cout << "Lista" << endl;
            List<NodeMem>::Instance().print();
            cout << "Fin lista" << endl;

            cout << "Will send to all: " << message << endl;
            Server::SendToAll(message);
        }
    }

    //End thread
    return NULL;
}

void Server::SendToAll(char *message) {
    int n;

    //Acquire the lock
    MyThread::LockMutex("'SendToAll()'");

    for(size_t i=0; i<clients.size(); i++) {
        n = send(Server::clients[i].sock, message, strlen(message), 0);
        cout << n << " bytes sent." << endl;
    }

    //Release the lock
    MyThread::UnlockMutex("'SendToAll()'");
}

void Server::ListClients() {
    for(size_t i=0; i<clients.size(); i++) {
        cout << clients.at(i).name << endl;
    }
}

/*
  Should be called when vector<Client> clients is locked!
*/
int Server::FindClientIndex(Client *c) {
    for(size_t i=0; i<clients.size(); i++) {
        if((Server::clients[i].id) == c->id) return (int) i;
    }
    cerr << "Client id not found." << endl;
    return -1;
}
std::string Server::bufferToString(char* buffer, int bufflen)
{
    std::string ret(buffer, bufflen);

    return ret;
}

list<string> Server::parser(std::string s){
    std::string delimiter = "&";
    list<string> lista;
    list<string> lista2;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        lista.push_back(token);
        std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    lista2 = lista;
    return lista2;
}
void Server::createNodo(list<string> lista) {
    NodeMem mem;
    string delim = "&";
    lista.pop_front();
    mem.setKey(lista.front());
    lista.pop_front();
    mem.setValue(lista.front());
    lista.pop_front();
    mem.setValue_size(lista.front());
    lista.pop_front();
    List<NodeMem>::Instance().add_end(mem);

}


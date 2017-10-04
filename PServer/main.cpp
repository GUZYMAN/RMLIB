#include <iostream>
#include "library.h"
#include "rmRef_h.h"


int main(int argc, char *argv[]) {
    rmRef_h nodo;

    TCPClient tcp;
    tcp.rm_init("localhost", 8888);

    int x = 1; int x2 = 10; int x3 = 100; int x4 = 1000; int x5 = 10000;
    void* vptr = &x; void* vptr2 = &x2; void* vptr3 = &x3; void* vptr4 = &x4; void* vptr5 = &x5;

    tcp.rm_new("gerald", vptr, sizeof(x));
    tcp.receive();
    tcp.rm_new("steven", vptr2, sizeof(x2));
    tcp.receive();
    tcp.rm_new("guzman", vptr3, sizeof(x3));
    tcp.receive();
    tcp.rm_new("fernandez", vptr4, sizeof(x4));
    tcp.receive();
    tcp.rm_new("diego", vptr5, sizeof(x5));
    string rec = tcp.receive();
    cout << "Server Response:" << rec << endl;
    nodo = tcp.rm_get("guzman");
}
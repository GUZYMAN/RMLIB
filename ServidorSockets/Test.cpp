#include "main.cpp"
#include <iostream>


int main(int argc, char *argv[])
{
    Rmlib tcp;
    tcp.setup("localhost",8888);

    string msg = "hello";
    tcp.Send(msg);
    string rec = tcp.receive();
    if( rec != "" )
    {
        cout << "Server Response:" << rec << endl;
    }
}
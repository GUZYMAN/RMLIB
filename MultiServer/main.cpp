
#include <iostream>
#include "mythread.h"
#include "server.h"
#include "list.h"
#include "NodeMem.cpp"

using namespace std;

int main() {
    NodeMem mem, mem2, mem3, mem4;
    mem.setKey("Hello"); mem.setValue("18"); mem.setValue_size("4");
    mem2.setKey("Hello2"); mem2.setValue("182"); mem2.setValue_size("42");
    mem3.setKey("Hello3"); mem3.setValue("183"); mem.setValue_size("43");
    cout << "Running!" << endl;
    //List<NodeMem> *lista;
    //List<NodeMem>::Instance();
    //List<NodeMem>::Instance().add_head(mem);
    //List<NodeMem>::Instance().add_end(mem2);
    //List<NodeMem>::Instance().add_end(mem3);
    /*cout << List<NodeMem>::Instance().search("guzman").getKey() << endl;
    cout <<List<NodeMem>::Instance().getM_num_nodes()<<endl;
    List<NodeMem>::Instance().del_by_data("guzman");
    cout<<List<NodeMem>::Instance().getM_num_nodes()<<endl;*/



    Server *s;
    s = new Server();

    //Main loop
    s->AcceptAndDispatch();

    return 0;
}
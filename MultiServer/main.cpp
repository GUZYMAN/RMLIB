
#include <iostream>
#include "mythread.h"
#include "server.h"
#include "list.h"
#include "list.cpp"
#include "NodeMem.cpp"

using namespace std;

int main() {
    NodeMem mem, mem2, mem3, mem4;
    mem.setKey("Hello"); mem.setValue("18"); mem.setValue_size("4");
    mem2.setKey("Hello2"); mem2.setValue("182"); mem2.setValue_size("42");
    mem3.setKey("Hello3"); mem3.setValue("183"); mem.setValue_size("43");
    cout << "Running!" << endl;
    List<NodeMem> lista1;
    lista1.add_head(mem);
    lista1.add_end(mem2);
    lista1.add_end(mem3);
    cout << lista1.search("Hello2").getKey() << endl;
    cout <<lista1.getM_num_nodes()<<endl;
    lista1.del_by_data("Hello2");
    cout<<lista1.getM_num_nodes()<<endl;


    Server *s;
    s = new Server();

    //Main loop
    s->AcceptAndDispatch();

    return 0;
}
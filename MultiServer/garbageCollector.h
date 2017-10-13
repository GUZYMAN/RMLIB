//
// Created by gerald on 04/10/17.
#include <chrono>
#include <thread>
#include "list.h"
#include "NodeMem.h"

#ifndef MULTISERVER_GARBAGECOLLECTOR_H
#define MULTISERVER_GARBAGECOLLECTOR_H
class garbageCollector{
public:
    garbageCollector(){};
    void init(){
        NodeMem* c;
        cout<<"----------------------------Garbage Collector active-------------------------------" << endl;
    }
    void *collect(){
        while(1){
            List<NodeMem>::Instance().recorrer();
            std::this_thread::sleep_for (std::chrono::seconds(1));
        }
    }
};

#endif //MULTISERVER_GARBAGECOLLECTOR_H

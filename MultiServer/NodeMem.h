#ifndef MULTISERVER_NODEMEM_H
#define MULTISERVER_NODEMEM_H
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

class NodeMem{


private:
    string key;
    string value;
    string value_size;

public:
    NodeMem(){}
    const string &getValue_size() const {
        return value_size;
    }

    void setValue_size(const string &value_size) {
        NodeMem::value_size = value_size;
    }

    const string &getValue() const {
        return value;
    }

    void setValue(const string &value) {
        NodeMem::value = value;
    }

    const string &getKey() const {
        return key;
    }

    void setKey(const string &key) {
        NodeMem::key = key;
    }


};

#endif //MULTISERVER_NODEMEM_H

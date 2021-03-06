//
// Created by gerald on 02/10/17.
//
#ifndef RMLIB_RMREF_H_H
#define RMLIB_RMREF_H_H
#include <iostream>
#include <unistd.h>
#include <string.h>


using namespace std;
class rmRef_h{

private:
    string llave;
    string value;
    string value_size;


public:
    rmRef_h(){
    };
    const string &getLlave() const;
    void setLlave(const string &llave);

    const string &getValue() const;

    void setValue(const string &value);

    const string &getValue_size() const;

    void setValue_size(const string &value_size);


    void operator=(rmRef_h x){
        setLlave(x.getLlave());
        setValue(x.getValue());
        setValue_size(x.getValue_size());
    }

    bool operator==(rmRef_h x){
        if(x.getLlave() == this->llave){
            return true;
        }
        else{return false;
        }
    }
    bool operator!=(rmRef_h x){
        if(x.getLlave() != this->llave){
            return true;
        }
        else{return false;
        }
    }
};
#endif //RMLIB_RMREF_H_H

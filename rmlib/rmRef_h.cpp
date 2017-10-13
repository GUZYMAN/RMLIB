//
// Created by gerald on 02/10/17.
//


#include "rmRef_h.h"


void rmRef_h::setLlave(const string &llave) {
    rmRef_h::llave = llave;
}

const string &rmRef_h::getValue() const {
    return value;
}

void rmRef_h::setValue(const string &value) {
    rmRef_h::value = value;
}

const string &rmRef_h::getValue_size() const {
    return value_size;
}

void rmRef_h::setValue_size(const string &value_size) {
    rmRef_h::value_size = value_size;
}

const string &rmRef_h::getLlave() const {
    return llave;
}

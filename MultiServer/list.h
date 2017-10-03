#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "nodo.h"
#include "nodo.cpp"
#include "NodeMem.h"

using namespace std;

template <class T>

class List
{
public:
    List();
    ~List();

    void add_head(T);
    void add_end(T);
    void add_sort(T);
    void concat(List);
    void del_all();
    void del_by_data(string);
    void del_by_position(int);
    void fill_by_user(int);
    void fill_random(int);
    void intersection(List);
    void invert();
    void load_file(string);
    void print();
    void save_file(string);
    NodeMem search(string);
    void sort();

    int getM_num_nodes() const;

private:
    Node<T> *m_head;
    int m_num_nodes;
};

#endif // LIST_H
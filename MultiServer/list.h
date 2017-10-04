#ifndef MULTISERVER_LIST_H
#define MULTISERVER_LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>

#include "nodo.h"
#include "nodo.cpp"
#include "NodeMem.h"

using namespace std;

template <class T>

class List
{
public:
    //Singleton
    static List<T>& Instance();

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
    List();
    Node<T> *m_head;
    int m_num_nodes;
    static List<T>* _instance;
    static List<T>* CreateInstance();


protected:
    virtual ~List();

};


template<typename T>
List<T>* List<T>::_instance = 0;

template <typename T>
List<T>::List()
{
    assert(_instance == 0);
    _instance = static_cast<List<T>*>(this);
    m_num_nodes = 0;
    m_head = NULL;
}


template<typename T>
List<T>& List<T>::Instance()
{
    if (List<T>::_instance == 0)
    {
        List<T>::_instance = CreateInstance();
    }
    return *(List<T>::_instance);
}

template<typename T>
inline List<T>* List<T>::CreateInstance()
{    return new List();
}

template<typename T>
int List<T>::getM_num_nodes() const {
    return m_num_nodes;
}

// Insertar al inicio
template<typename T>
void List<T>::add_head(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}

// Insertar al final
template<typename T>
void List<T>::add_end(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}





// Eliminar todos los nodos
template<typename T>
void List<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}

// Eliminar por data del nodo
template<typename T>
void List<T>::del_by_data(string data_)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = m_head->next;

    int cont = 0;

    if (m_head->data.getKey() == data_) {
        m_head = temp->next;
    } else {
        while (temp1) {
            if (temp1->data.getKey() == data_) {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}



// Invertir la lista
template<typename T>
void List<T>::invert()
{
    Node<T> *prev = NULL;
    Node<T> *next = NULL;
    Node<T> *temp = m_head;

    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    m_head = prev;
}

// Cargar una lista desde un archivo
template<typename T>
void List<T>::load_file(string file)
{
    T line;
    ifstream in;
    in.open(file.c_str());

    if (!in.is_open()) {
        cout << "No se puede abrir el archivo: " << file << endl << endl;
    } else {
        while (in >> line) {
            add_end(line);
        }
    }
    in.close();
}

// Imprimir la Lista
template<typename T>
void List<T>::print()
{
    Node<T> *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

template<typename T>
NodeMem List<T>::search(string data_)
{
    NodeMem mem;

    Node<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->data.getKey() == data_) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
            mem = temp->data;
        }
        temp = temp->next;
        cont++;
    }return mem;

    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}
// Guardar una lista en un archivo
template<typename T>
void List<T>::save_file(string file)
{
    Node<T> *temp = m_head;
    ofstream out;
    out.open(file.c_str());

    if (!out.is_open()) {
        cout << "No se puede guardar el archivo " << endl;
    } else {
        while (temp) {
            out << temp->data;
            out << " ";
            temp = temp->next;
        }
    }
    out.close();
}

template<typename T>
List<T>::~List() {}



#endif // MULTISERVER _LIST_H
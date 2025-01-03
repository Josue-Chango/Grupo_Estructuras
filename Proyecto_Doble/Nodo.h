#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Nodo
{
private:
    T dato;
    Nodo *siguiente;
    Nodo *anterior;

public:
    Nodo(T _dato);

    T getDato();
    void setDato(T _dato);

    void setSiguiente(Nodo *_siguiente);
    Nodo *getSiguiente();

    void setAnterior(Nodo *_anterior);
    Nodo *getAnterior();
};

#include "Nodo.cpp"

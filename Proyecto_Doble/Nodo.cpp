#include "Nodo.h"

template <typename T>
Nodo<T>::Nodo(T _dato)
{
    dato = _dato;
    siguiente = NULL;
    anterior = NULL;
}

template <typename T>
T Nodo<T>::getDato()
{
    return dato;
}

template <typename T>
void Nodo<T>::setDato(T _dato)
{
    dato = _dato;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T> *_siguiente)
{
    siguiente = _siguiente;
}

template <typename T>
Nodo<T> *Nodo<T>::getSiguiente()
{
    return siguiente;
}

template <typename T>
void Nodo<T>::setAnterior(Nodo<T> *_anterior)
{
    anterior = _anterior;
}

template <typename T>
Nodo<T> *Nodo<T>::getAnterior()
{
    return anterior;
}

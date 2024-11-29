#include "Nodo_Circular_Doble.h"

template<typename T>
Nodo_Circular_Doble<T>::Nodo_Circular_Doble(T dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

template<typename T>
Nodo_Circular_Doble<T>::~Nodo_Circular_Doble()
{
}

template<typename T>
void Nodo_Circular_Doble<T>::setDato(T dato)
{
	this->dato = dato;
}


template<typename T>
T Nodo_Circular_Doble<T>::getDato()
{
	return this->dato;
}


template<typename T>
void Nodo_Circular_Doble<T>::setSiguiente(Nodo_Circular_Doble<T>* siguiente)
{
	this->siguiente = siguiente;
}

template<typename T>
Nodo_Circular_Doble<T>* Nodo_Circular_Doble<T>::getSiguiente()
{
	return this->siguiente;
}

template<typename T>
void Nodo_Circular_Doble<T>::setAnterior(Nodo_Circular_Doble<T>* anterior)
{
	this->anterior = anterior;
}

template<typename T>
Nodo_Circular_Doble<T>* Nodo_Circular_Doble<T>::getAnterior()
{
	return this->anterior;
}



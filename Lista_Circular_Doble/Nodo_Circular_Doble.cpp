#include "Nodo_Circular_Doble.h"

template<typename T>
Nodo_Circular_Doble<T>::Nodo_Circular_Doble(T dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

template<typename T>
Nodo_Circular_Doble<T>::Nodo_Circular_Doble(T _nombre1, T _nombre2, T _apellido, T _cedula, T _correo)
{
	this->nombre1 = _nombre1;
	this->nombre2 = _nombre2;
	this->apellido = _apellido;
	this->cedula = _cedula;
	this->correo = _correo;
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

///////////////////////////////////////////7


template <typename T>
void Nodo_Circular_Doble<T>::setNombre1(T _nombre1)
{
    this->nombre1 = _nombre1;
};

template <typename T>
T Nodo_Circular_Doble<T>::getNombre1()
{
    return this->nombre1;
}

template <typename T>
void Nodo_Circular_Doble<T>::setNombre2(T _nombre2)
{
    this->nombre2 = _nombre2;
};

template <typename T>
T Nodo_Circular_Doble<T>::getNombre2()
{
    return this->nombre2;
}

template <typename T>
void Nodo_Circular_Doble<T>::setApellido(T _apellido)
{
    this->apellido = _apellido;
}

template <typename T>
T Nodo_Circular_Doble<T>::getApellido()
{
    return this->apellido;
}

template <typename T>
void Nodo_Circular_Doble<T>::setCorreo(T _correo)
{
    this->correo = _correo;
}

template <typename T>
T Nodo_Circular_Doble<T>::getCorreo()
{
    return this->correo;
}

template <typename T>
void Nodo_Circular_Doble<T>::setCedula(T _cedula)
{
    this->cedula = _cedula;
}

template <typename T>
T Nodo_Circular_Doble<T>::getCedula()
{
    return this->cedula;
}
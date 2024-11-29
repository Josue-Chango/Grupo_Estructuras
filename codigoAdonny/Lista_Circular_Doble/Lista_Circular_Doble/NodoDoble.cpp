#include "NodoDoble.h"
template<typename T>
NodoDoble<T>::NodoDoble(T dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}
template<typename T>
NodoDoble<T>::~NodoDoble()
{
}

template <typename T>
NodoDoble<T>::NodoDoble(T _nombre1, T _nombre2, T _apellido, T _cedula, T _correo)
{
    nombre1 = _nombre1;
    nombre2 = _nombre2;
    apellido = _apellido;
    cedula = _cedula;
    correo = _correo;
}

template<typename T>
void NodoDoble<T>::setDato(T dato)
{
	this->dato = dato;
}

template<typename T>
T NodoDoble<T>::getDato()
{
	return this->dato;
}

template<typename T>
void NodoDoble<T>::setSiguiente(NodoDoble* siguiente)
{
	this->siguiente = siguiente;
}

template<typename T>
NodoDoble<T>* NodoDoble<T>::getSiguiente()
{
	return this->siguiente;
}

template<typename T>
void NodoDoble<T>::setAnterior(NodoDoble* anterior)
{
	this->anterior = anterior;
}

template <typename T>
void NodoDoble<T>::setNombre1(T _nombre1)
{
    nombre1 = _nombre1;
};

template <typename T>
T NodoDoble<T>::getNombre1()
{
    return nombre1;
}

template <typename T>
void NodoDoble<T>::setNombre2(T _nombre2)
{
    nombre2 = _nombre2;
};

template <typename T>
T NodoDoble<T>::getNombre2()
{
    return nombre2;
}

template <typename T>
void NodoDoble<T>::setApellido(T _apellido)
{
    apellido = _apellido;
}

template <typename T>
T NodoDoble<T>::getApellido()
{
    return apellido;
}

template <typename T>
void NodoDoble<T>::setCorrero(T _correo)
{
    correo = _correo;
}

template <typename T>
T NodoDoble<T>::getCorreo()
{
    return correo;
}

template <typename T>
void NodoDoble<T>::setCedula(T _cedula)
{
    cedula = _cedula;
}

template <typename T>
T NodoDoble<T>::getCedula()
{
    return cedula;
}

template<typename T>
NodoDoble<T>* NodoDoble<T>::getAnterior()
{
	return this->anterior;
}



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

template <typename T>
Nodo_Circular_Doble<T>::Nodo_Circular_Doble(T _nombre1, T _nombre2, T _apellido, T _cedula, T _correo)
{
    nombre1 = _nombre1;
    nombre2 = _nombre2;
    apellido = _apellido;
    cedula = _cedula;
    correo = _correo;
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
void Nodo_Circular_Doble<T>::setSiguiente(Nodo_Circular_Doble* siguiente)
{
	this->siguiente = siguiente;
}

template<typename T>
Nodo_Circular_Doble<T>* Nodo_Circular_Doble<T>::getSiguiente()
{
	return this->siguiente;
}

template<typename T>
void Nodo_Circular_Doble<T>::setAnterior(Nodo_Circular_Doble* anterior)
{
	this->anterior = anterior;
}

template <typename T>
void Nodo_Circular_Doble<T>::setNombre1(T _nombre1)
{
    nombre1 = _nombre1;
};

template <typename T>
T Nodo_Circular_Doble<T>::getNombre1()
{
    return nombre1;
}

template <typename T>
void Nodo_Circular_Doble<T>::setNombre2(T _nombre2)
{
    nombre2 = _nombre2;
};

template <typename T>
T Nodo_Circular_Doble<T>::getNombre2()
{
    return nombre2;
}

template <typename T>
void Nodo_Circular_Doble<T>::setApellido(T _apellido)
{
    apellido = _apellido;
}

template <typename T>
T Nodo_Circular_Doble<T>::getApellido()
{
    return apellido;
}

template <typename T>
void Nodo_Circular_Doble<T>::setCorrero(T _correo)
{
    correo = _correo;
}

template <typename T>
T Nodo_Circular_Doble<T>::getCorreo()
{
    return correo;
}

template <typename T>
void Nodo_Circular_Doble<T>::setCedula(T _cedula)
{
    cedula = _cedula;
}

template <typename T>
T Nodo_Circular_Doble<T>::getCedula()
{
    return cedula;
}

template<typename T>
Nodo_Circular_Doble<T>* Nodo_Circular_Doble<T>::getAnterior()
{
	return this->anterior;
}



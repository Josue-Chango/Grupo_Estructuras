/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "Nodo_Circular.h"

using namespace std;

template<typename T>
Nodo_Circular<T>::Nodo_Circular(T dato) {
    this->dato = dato;
    this->siguiente = NULL;
}

template<typename T>
void Nodo_Circular<T>::setDato(T dato) {
    this->dato = dato;
}

template <typename T>
T Nodo_Circular<T>::getDato()
{
    return this->dato;
}

template<typename T>
void Nodo_Circular<T>::setSiguiente(Nodo_Circular* siguiente) {
    this->siguiente = siguiente;
}

template <typename T>
Nodo_Circular<T> *Nodo_Circular<T>::getSiguiente()
{
    return this->siguiente;
}

template <typename T>
Nodo_Circular<T>::Nodo_Circular(T _nombre1, T _nombre2, T _apellido, T _correo)
{
    nombre1 = _nombre1;
    nombre2 = _nombre2;
    apellido = _apellido;
    correo = _correo;
}

template <typename T>
T Nodo_Circular<T>::getNombre1()
{
    return nombre1;
}

template <typename T>
void Nodo_Circular<T>::setNombre1(T _nombre1)
{
    nombre1 = _nombre1;
}

template <typename T>
T Nodo_Circular<T>::getNombre2()
{
    return nombre2;
}

template <typename T>
void Nodo_Circular<T>::setNombre2(T _nombre2)
{
    nombre2 = _nombre2;
}

template <typename T>
T Nodo_Circular<T>::getApellido()
{
    return apellido;
}

template <typename T>
void Nodo_Circular<T>::setApellido(T _apellido)
{
    apellido = _apellido;
}

template <typename T>
T Nodo_Circular<T>::getCorreo()
{
    return correo;
}

template <typename T>
void Nodo_Circular<T>::setCorreo(T _correo)
{
    correo = _correo;
}

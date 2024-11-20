/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          18/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Nodo.h"

using namespace std;

template<typename T>
 Nodo<T>::Nodo(T _dato) {
    dato = _dato;
    siguiente = NULL;
}

template <typename T>
Nodo<T>::Nodo(T _nombre, T _apellido, T _correo)
{
    nombre = _nombre;
    apellido = _apellido;
    correo = _correo;
}

template<typename T>
inline void Nodo<T>::setDato(T _dato) {
    dato = _dato;
}

template<typename T>
 T Nodo<T>::getDato() {
    return dato;
}

template<typename T>
 void Nodo<T>::setSiguiente(Nodo* _siguiente) {
    siguiente = _siguiente;
}

template<typename T>
 Nodo<T>* Nodo<T>::getSiguiente() {
    return siguiente;
}

template <typename T>
void Nodo<T>::setNombre(T _nombre)
{
    nombre = _nombre;
};

template <typename T>
T Nodo<T>::getNombre()
{
    return nombre;
}

template <typename T>
void Nodo<T>::setApellido(T _apellido)
{
    apellido = _apellido;
}

template <typename T>
T Nodo<T>::getApellido()
{
    return apellido;
}

template <typename T>
void Nodo<T>::setCorrero(T _correo)
{
    correo = _correo;
}

template <typename T>
string Nodo<T>::getCorreo()
{
    return correo;
}

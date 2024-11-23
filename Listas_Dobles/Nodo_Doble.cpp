/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "Nodo_Doble.h"

template <typename T>
Nodo_Doble<T>::Nodo_Doble(T _dato) {
    dato = _dato;
    siguiente = NULL;
    anterior = NULL;
}

template <typename T>
void Nodo_Doble<T>::setDato(T _dato) {
    dato = _dato;
}

template <typename T>
void Nodo_Doble<T>::setSiguiente(Nodo_Doble* _siguiente) {
    siguiente = _siguiente;
}

template <typename T>
void Nodo_Doble<T>::setAnterior(Nodo_Doble* _anterior) {
    anterior = _anterior;
}

template <typename T>
T Nodo_Doble<T>::getDato() {
    return dato;
}

template <typename T>
Nodo_Doble<T>* Nodo_Doble<T>::getSiguiente() {
    return siguiente;
}

template <typename T>
Nodo_Doble<T>* Nodo_Doble<T>::getAnterior() {
    return anterior;
}

template <typename T>
Nodo_Doble<T>::Nodo_Doble(T _nombre1, T _nombre2, T _apellido, T _correo)
{
    nombre1 = _nombre1;
    nombre2 = _nombre2;
    apellido = _apellido;
    correo = _correo;
}

template <typename T>
T Nodo_Doble<T>::getNombre1()
{
    return nombre1;
}

template <typename T>
void Nodo_Doble<T>::setNombre1(T _nombre1)
{
    nombre1 = _nombre1;
}

template <typename T>
T Nodo_Doble<T>::getNombre2()
{
    return nombre2;
}

template <typename T>
void Nodo_Doble<T>::setNombre2(T _nombre2)
{
    nombre2 = _nombre2;
}

template <typename T>
T Nodo_Doble<T>::getApellido()
{
    return apellido;
}

template <typename T>
void Nodo_Doble<T>::setApellido(T _apellido)
{
    apellido = _apellido;
}

template <typename T>
T Nodo_Doble<T>::getCorreo()
{
    return correo;
}

template <typename T>
void Nodo_Doble<T>::setCorreo(T _correo)
{
    correo = _correo;
}

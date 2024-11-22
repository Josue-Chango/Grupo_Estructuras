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

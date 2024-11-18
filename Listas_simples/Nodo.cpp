/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programa sobre lista simple         *
 * Autor:                          Josue Chango                        *
 * Fecha de creacion:              18/11/2024                          *
 * Fecha de modificacion:          18/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/
#include "Nodo.h"

using namespace std;

 Nodo::Nodo(int _dato) {
    dato = _dato;
    siguiente = NULL;
}

inline void Nodo::setDato(int _dato) {
    dato = _dato;
}

 int Nodo::getDato() {
    return dato;
}

 void Nodo::setSiguiente(Nodo* _siguiente) {
    siguiente = _siguiente;
}

 Nodo* Nodo::getSiguiente() {
    return siguiente;
}


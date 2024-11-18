/************************************************************************
 * ESPE                                                                 *
 * ALUMNOS:  Eduardo Altamirano,Adonny Calero, Josue Chango             *
 * FECHA CREACION: Lunes, 18 de noviembre de 2024                       *
 * FECHA MODIFICACION: Lunes, 18 de noviembre de 2024                   *
 * Enunciado del problema: Crear los m�todos Insertar, Buscar           *
 y Eliminar elementos de una lista Simple, Doble y Circular             *
 * Nivel: TERCERO     NRC: 1978                                        *
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


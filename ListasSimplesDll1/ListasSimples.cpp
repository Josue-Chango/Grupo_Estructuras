/************************************************************************
 * ESPE                                                                 *
 * ALUMNOS:  Eduardo Altamirano,Adonny Calero, Josue Chango             *
 * FECHA CREACION: Lunes, 18 de noviembre de 2024                       *
 * FECHA MODIFICACION: Lunes, 18 de noviembre de 2024                   *
 * Enunciado del problema: Crear los m�todos Insertar, Buscar           *
 y Eliminar elementos de una lista Simple, Doble y Circular             *
 * Nivel: TERCERO     NRC: 1978                                       *
 ***********************************************************************/
#include "ListasSimples.h"

using namespace std;

inline ListaSimples::ListaSimples() {
    cabeza = NULL;
}

inline void ListaSimples::Insertar(int _dato) {
    Nodo* nuevo = new Nodo(_dato);
    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {
        Nodo* aux = cabeza;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

inline void ListaSimples::Buscar(int _dato) {
    Nodo* aux = cabeza;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            cout << "El dato " << _dato << " si se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

inline void ListaSimples::Eliminar(int _dato) {
    Nodo* aux = cabeza;
    Nodo* anterior = NULL;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            if (anterior == NULL) {
                cabeza = aux->getSiguiente();
            }
            else {
                anterior->setSiguiente(aux->getSiguiente());
            }
            delete aux;
            cout << "El dato " << _dato << " se ha eliminado de la lista" << endl;
            return;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

inline void ListaSimples::Mostrar() {
    Nodo* aux = cabeza;
    while (aux != NULL) {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

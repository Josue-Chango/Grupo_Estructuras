/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "Lista_Circular.h"

using namespace std;

template<typename T>
Lista_Circular<T>::Lista_Circular() {
    primero = NULL;
    ultimo = NULL;
}

template<typename T>
void Lista_Circular<T>::Insertar(T dato) {
    Nodo_Circular<T>* nuevo = new Nodo_Circular<T>(dato);
    if (primero == NULL) {
        primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = primero;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
    }
}

template<typename T>
void Lista_Circular<T>::Buscar(T dato) {
    Nodo_Circular<T>* actual = new Nodo_Circular<T>(dato);
    actual = primero;
    bool encontrado = false;
    if (primero != NULL) {
        do {
            if (actual->getDato() == dato) {
                cout << "El elemento " << dato << " ha sido encontrado en la lista" << endl;
                encontrado = true;
            }
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            cout << "El elemento " << dato << " no ha sido encontrado en la lista" << endl;
        }
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

template<typename T>
void Lista_Circular<T>::Eliminar(T dato) {
    Nodo_Circular<T>* actual = new Nodo_Circular<T>(dato);
    actual = primero;
    Nodo_Circular<T>* anterior = new Nodo_Circular<T>(dato);
    anterior = NULL;
    bool encontrado = false;
    if (primero != NULL) {
        do {
            if (actual->getDato() == dato) {
                if (actual == primero) {
                    primero = primero->getSiguiente();
                }
                else if (actual == ultimo) {
                    anterior->setSiguiente(primero);
                }
                else {
                    anterior->setSiguiente(actual->getSiguiente());
                }
                cout << "El elemento " << dato << " ha sido eliminado de la lista" << endl;
                encontrado = true;
            }
            anterior = actual;
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            cout << "El elemento " << dato << " no ha sido encontrado en la lista" << endl;
        }
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

template<typename T>
void Lista_Circular<T>::Mostrar() {
    Nodo_Circular<T>* actual = new Nodo_Circular<T>(0);
    actual = primero;
    if (primero != NULL) {
        do {
            cout << actual->getDato() << " -> ";
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

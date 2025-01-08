#ifndef ARBOLAA_H
#define ARBOLAA_H

#include "Nodo.h"

class ArbolAA {
public:
    ArbolAA() : raiz(nullptr) {}

    void insertar(int clave);
    bool buscar(int clave);
    void eliminar(int clave);
    void mostrar();

private:
    Nodo* raiz;

    Nodo* inclinar(Nodo* nodo);
    Nodo* dividir(Nodo* nodo);
    Nodo* insertar(Nodo* nodo, int clave);
    Nodo* eliminar(Nodo* nodo, int clave);
    void recorridoInorden(Nodo* nodo);
};

#endif // ARBOLAA_H

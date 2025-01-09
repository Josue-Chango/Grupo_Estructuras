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
    int altura(Nodo* nodo);
    int profundidad(int clave);
    int niveles();
    Nodo* raiz;

private:
    

    Nodo* inclinar(Nodo* nodo);
    Nodo* dividir(Nodo* nodo);
    Nodo* insertar(Nodo* nodo, int clave);
    Nodo* eliminar(Nodo* nodo, int clave);
    void recorridoInorden(Nodo* nodo);
    void recorridoPreorden(Nodo* nodo);
    void recorridoPostorden(Nodo* nodo);
    

};

#endif // ARBOLAA_H

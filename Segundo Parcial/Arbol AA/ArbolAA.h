#ifndef ARBOLAA_H
#define ARBOLAA_H

#include "Nodo.h"
#include <graphics.h>

template <typename T>
class ArbolAA {
public:
    ArbolAA() : raiz(nullptr) {}

    void insertar(int clave);
    void buscar(int clave);
    void eliminar(int clave);
    void mostrar();
    int altura(Nodo<T>* nodo);
    int profundidad(int clave);
    int niveles();
    Nodo<T>* raiz;
    void verArbol();

private:
    

    Nodo<T>* inclinar(Nodo<T>* nodo);
    Nodo<T>* dividir(Nodo<T>* nodo);
    Nodo<T>* insertar(Nodo<T>* nodo, int clave);
    Nodo<T>* eliminar(Nodo<T>* nodo, int clave);
    void recorridoInorden(Nodo<T>* nodo);
    void recorridoPreorden(Nodo<T>* nodo);
    void recorridoPostorden(Nodo<T>* nodo);
    void dibujarArbol(Nodo<T>* nodo, int x, int y, int offset);
    

};

#endif // ARBOLAA_H

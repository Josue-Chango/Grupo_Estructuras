#ifndef NODO_H
#define NODO_H

struct Nodo {
    int clave;
    int nivel;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int k) : clave(k), nivel(1), izquierda(nullptr), derecha(nullptr) {}
};

#endif // NODO_H

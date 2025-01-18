#ifndef NODO_H
#define NODO_H
#include <graphics.h>

template <typename T>
class Nodo
{
private:
    
    
public:
    int clave;
    int nivel;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(/* args */);
    ~Nodo();
    Nodo(int k) : clave(k), nivel(1), izquierda(nullptr), derecha(nullptr) {}
};

template <typename T>
Nodo<T>::Nodo(/* args */)
{
}

template <typename T>
Nodo<T>::~Nodo()
{
}




/*Nodo {
    int clave;
    int nivel;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int k) : clave(k), nivel(1), izquierda(nullptr), derecha(nullptr) {}
};*/

#endif // NODO_H

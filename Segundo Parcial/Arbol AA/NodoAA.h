#ifndef NodoAA_H
#define NodoAA_H
#include <graphics.h>

template <typename T>
class NodoAA
{
private:
    
    
public:
    int clave;
    int nivel;
    NodoAA* izquierda;
    NodoAA* derecha;
    NodoAA(/* args */);
    ~NodoAA();
    NodoAA(int k) : clave(k), nivel(1), izquierda(nullptr), derecha(nullptr) {}
};

template <typename T>
NodoAA<T>::NodoAA(/* args */)
{
}

template <typename T>
NodoAA<T>::~NodoAA()
{
}




/*NodoAA {
    int clave;
    int nivel;
    NodoAA* izquierda;
    NodoAA* derecha;

    NodoAA(int k) : clave(k), nivel(1), izquierda(nullptr), derecha(nullptr) {}
};*/

#endif // NodoAA_H

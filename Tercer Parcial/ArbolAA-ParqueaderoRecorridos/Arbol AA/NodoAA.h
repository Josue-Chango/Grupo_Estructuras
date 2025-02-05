#ifndef NodoAA_H
#define NodoAA_H
//#include <graphics.h>
#include <SFML/Graphics.hpp>


template <typename T>
class NodoAA
{
private:
    
    
public:
    T nombre, apellido, cedula, placa;
    T getNombre();
    void setNombre(T);
    T getApellido();
    void setApellido(T);
    T getCedula();
    void setCedula(T);
    T getPlaca();
    void setPlaca(T);

    int clave;
    int nivel;
    NodoAA* izquierda;
    NodoAA* derecha;

    NodoAA(/* args */);
    ~NodoAA();
    NodoAA(int k) : clave(k), nivel(1), izquierda(nullptr), derecha(nullptr) {}
    NodoAA(T/*nombre*/, T/*appellido*/, T/*cedula*/, T/*placa*/);
};

template <typename T>
NodoAA<T>::NodoAA(/* args */)
{
}

template <typename T>
NodoAA<T>::~NodoAA()
{
}

template <typename T>
NodoAA<T>::NodoAA(T _nombre, T _apellido, T _cedula, T _placa)
{
    nombre = _nombre;
    apellido = _apellido;
    cedula = _cedula;
    placa = _placa;
    clave = stoi(_cedula);
    nivel = 1;
    izquierda = nullptr;
    derecha = nullptr;
}

/*NodoAA {
    int clave;
    int nivel;
    NodoAA* izquierda;
    NodoAA* derecha;

    NodoAA(int k) : clave(k), nivel(1), izquierda(nullptr), derecha(nullptr) {}
};*/

#endif // NodoAA_H

template <typename T>
inline T NodoAA<T>::getNombre()
{
    return nombre;
}

template <typename T>
inline void NodoAA<T>::setNombre(T _nombre)
{
    nombre = _nombre;
}

template <typename T>
inline T NodoAA<T>::getApellido()
{
    return apellido;
}

template <typename T>
inline void NodoAA<T>::setApellido(T _apellido)
{
    apellido = _apellido;
}

template <typename T>
inline T NodoAA<T>::getCedula()
{
    return cedula;
}

template <typename T>
inline void NodoAA<T>::setCedula(T _cedula)
{
    cedula = _cedula;
}

template <typename T>
inline T NodoAA<T>::getPlaca()
{
    return placa;
}

template <typename T>
inline void NodoAA<T>::setPlaca(T _placa)
{
    placa = _placa;
}

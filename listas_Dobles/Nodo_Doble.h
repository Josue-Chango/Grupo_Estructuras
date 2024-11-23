/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

template <typename T>
class Nodo_Doble {
private:
    T dato;
    T nombre1, nombre2, apellido, correo;
    Nodo_Doble* siguiente;
    Nodo_Doble* anterior;
public:
    Nodo_Doble(T);
    void setDato(T);
    void setSiguiente(Nodo_Doble*);
    void setAnterior(Nodo_Doble*);
    T getDato();
    Nodo_Doble<T>* getSiguiente();
    Nodo_Doble<T>* getAnterior();


    Nodo_Doble(T,T,T,T);
    T getNombre1();
    void setNombre1(T);
    T getNombre2();
    void setNombre2(T);
    T getApellido();
    void setApellido(T);
    T getCorreo();
    void setCorreo(T);

};


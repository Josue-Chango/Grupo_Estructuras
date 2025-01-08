/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          18/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

template<typename T>
class Nodo {
private:
    T dato;
    T nombre1;
    T nombre2;
    T apellido;
    T cedula;
    Nodo* siguiente;
    string correo;
public:
    Nodo(T);
    Nodo(T, T, T, T, T);
    void setDato(T);
    T getDato();
    void setSiguiente(Nodo*);
    Nodo* getSiguiente();
    void setNombre1(T);
    T getNombre1();
    void setNombre2(T);
    T getNombre2();
    void setApellido(T);
    T getApellido();
    void setCorrero(T);
    string getCorreo();
    void setCedula(T);
    string getCedula();


    friend class ListaSimples;

};


/************************************************************************
 * ESPE                                                                 *
 * ALUMNOS:  Eduardo Altamirano,Adonny Calero, Josue Chango             *
 * FECHA CREACION: Lunes, 18 de noviembre de 2024                       *
 * FECHA MODIFICACION: Lunes, 18 de noviembre de 2024                   *
 * Enunciado del problema: Crear los m�todos Insertar, Buscar           *
 y Eliminar elementos de una lista Simple, Doble y Circular             *
 * Nivel: TERCERO     NRC: 1978                                       *
 ***********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Nodo {
private:
    int dato;
    Nodo* siguiente;
public:
    Nodo(int);
    void setDato(int);
    int getDato();
    void setSiguiente(Nodo*);
    Nodo* getSiguiente();
    friend class ListaSimples;
};


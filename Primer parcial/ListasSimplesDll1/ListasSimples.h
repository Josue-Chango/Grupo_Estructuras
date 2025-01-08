/************************************************************************
 * ESPE                                                                 *
 * ALUMNOS:  Eduardo Altamirano,Adonny Calero, Josue Chango             *
 * FECHA CREACION: Lunes, 18 de noviembre de 2024                       *
 * FECHA MODIFICACION: Lunes, 18 de noviembre de 2024                   *
 * Enunciado del problema: Crear los m�todos Insertar, Buscar           *
 y Eliminar elementos de una lista Simple, Doble y Circular             *
 * Nivel: TERCERO     NRC: 1978                                        *
 ***********************************************************************/
#pragma once
#include "Nodo.h"

using namespace std;

class ListaSimples {

private:
    Nodo* cabeza;
public:
    ListaSimples();
    void Insertar(int);
    void Buscar(int);
    void Eliminar(int);
    void Mostrar();
};


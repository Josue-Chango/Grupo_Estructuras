/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programa sobre lista simple         *
 * Autor:                          Josue Chango                        *
 * Fecha de creacion:              18/11/2024                          *
 * Fecha de modificacion:          18/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
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


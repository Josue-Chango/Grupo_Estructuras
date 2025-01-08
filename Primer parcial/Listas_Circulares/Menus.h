/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              23/11/2024                                          *
 * Fecha de modificacion:          23/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>

using namespace std;

template<typename T>
class Menus {
private:
    
public:
    Menus();
    void setConsoleColor(WORD);
    void Menu_Principal(int);
};



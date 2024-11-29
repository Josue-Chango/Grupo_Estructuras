/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              23/11/2024                                          *
 * Fecha de modificacion:          23/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menus.cpp"

using namespace std;



void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
};



int main() {
    Menus<int> entrada;
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        entrada.Menu_Principal(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + (Salir + 1)) % (Salir+1);
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % (Salir +1);
            break;
        case 13: // Enter
            cout << "si vale" << endl;            
        }
    }

    return 0;
}
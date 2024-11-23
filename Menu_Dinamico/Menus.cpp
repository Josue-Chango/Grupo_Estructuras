/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              23/11/2024                                          *
 * Fecha de modificacion:          23/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Menus.h"
#include <windows.h>

template <typename T>
Menus<T>::Menus()
{
}

template <typename T>
void Menus<T>::setConsoleColor(WORD color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

enum Opciones_Menu_Principal {
    Lista_Enteros,
    Lista_Flotantes,
    Lista_Dobles,
    Lista_String,
    Lista_Caracteres,
    Salir
};

template<typename T>
void Menus<T>::Menu_Principal(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Lista_Enteros",
        "Lista_Flotantes",
        "Lista_Dobles",
        "Lista_String",
        "Lista_Caracteres",
        "Salir"
    };

    cout << "******************************" << endl;
    cout << "Seleccione el tipo de ordenamiento:" << endl;
    cout << "******************************" << endl;
    for (int i = 0; i < Salir; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else {
            cout << "     " << opciones[i] << "\n";
        }
    }
    cout << "******************************" << endl;
}
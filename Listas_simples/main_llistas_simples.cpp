/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programa sobre lista simple         *
 * Autor:                          Josue Chango                        *
 * Fecha de creacion:              18/11/2024                          *
 * Fecha de modificacion:          18/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/
#include "ListasSimples.cpp"
#include "Nodo.cpp"
#include <iostream>
#include <stdlib.h>
#include "Validaciones.cpp"
#include <windows.h>
using namespace std;


bool esEntero(string);

int main() {
    ListaSimples* lista = new ListaSimples();
    int opcion, dato;
    Validaciones<int> ingresar_entero;
    Validaciones<float> ingresar_flotante;
    Validaciones<double> ingresar_doble;
    Validaciones<std::string> ingresar_string;
    Validaciones<char> ingresar_letra;

    /*HINSTANCE hDLL = LoadLibrary("ValidDll.dll");
    if (!hDLL) {
        std::cerr << "No se pudo cargar la DLL.\n";
        return 1;
    }*/



    do {
        system("cls");
        cout << "***********Listas Simples***********" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Salir" << endl;
        opcion = ingresar_entero.ingresar("Opcion: ","entero");
        cout << endl;
        switch (opcion) {
        case 1:
            dato = ingresar_entero.ingresar("ingrese el dato a insertar: ", "entero");
            cout << endl;
            lista->Insertar(dato);
            break;
        case 2:
            dato = ingresar_entero.ingresar("ingrese el dato a buscar: ", "entero");
            cout << endl;
            lista->Buscar(dato);
            break;
        case 3:
            dato = ingresar_entero.ingresar("ingrese el dato a eliminar: ", "entero");
            cout << endl;
            lista->Eliminar(dato);
            break;
        case 4:
            lista->Mostrar();
            break;
        default:
            cout << "numero no valido intente de nuevo" << endl;
            break;
        }
        system("pause");
    } while (opcion != 5);
    return 0;
}
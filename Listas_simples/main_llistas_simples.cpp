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
//#include <windows.h>
using namespace std;


bool esEntero(string);

int main() {
    ListaSimples<int>* lista_entero = new ListaSimples<int>();
    ListaSimples<float>* lista_flotante = new ListaSimples<float>();
    ListaSimples<double>* lista_doble = new ListaSimples<double>();
    ListaSimples<std::string>* lista_string = new ListaSimples<std::string>();
    ListaSimples<char>* lista_letras = new ListaSimples<char>();

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
        cout << "1. Lista de enteros" << endl;
        cout << "2. lista de flotantes" << endl;
        cout << "3. lista de dobles" << endl;
        cout << "4. lista de strings" << endl;
        cout << "5. lista de letras" << endl;
        cout << "6. salir";
        opcion = ingresar_entero.ingresar("Opcion: ","entero");
        cout << endl;
        switch (opcion) {
        case 1:
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
                    lista_entero->Insertar_cabeza(dato);
                    break;
                case 2:
                    dato = ingresar_entero.ingresar("ingrese el dato a buscar: ", "entero");
                    cout << endl;
                    lista_entero->Buscar(dato);
                    break;
                case 3:
                    dato = ingresar_entero.ingresar("ingrese el dato a eliminar: ", "entero");
                    cout << endl;
                    lista_entero->Eliminar(dato);
                    break;
                case 4:
                    lista_entero->Mostrar();
                    cout << endl;
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    break;
                }
                system("pause");
            } while (opcion != 5);
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
        case 5:

            break;
        default:
            cout << "Opcion no valida, intente de nuevo" << endl;
            break;
        }
        system("pause");
    } while (opcion != 6);

    
    return 0;
}

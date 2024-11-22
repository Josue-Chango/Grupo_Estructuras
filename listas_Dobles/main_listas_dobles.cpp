/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "Lista_Doble.cpp"
#include "Nodo_Doble.cpp"
#include "Validaciones.cpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

bool esEntero(string);

int main() {
    Lista_Doble<std::string>* lista_personas = new Lista_Doble<std::string>();
    int opcion, dato;
    char dato_char;
    string linea,  nombre1, nombre2, apellido, correo;

    Validaciones<int> ingresar_entero;
    Validaciones<std::string> ingresar_string;
    Validaciones<char> ingresar_letra;


    do {
        system("cls");
        cout << "***********Listas Dobles***********" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Salir" << endl;
        opcion = ingresar_entero.ingresar("Opcion: ","entero");
        switch (opcion) {
        case 1:
            nombre1 = ingresar_string.ingresar("Ingrese su primer nombre: ", "string");
                    cout << endl;
                    nombre2 = ingresar_string.ingresar("Ingrese su segundo nombre: ", "string");
                    cout <<endl;
                    apellido = ingresar_string.ingresar("Ingrese su apellido: ", "string");
                    cout << endl;
                    correo = lista_personas->generar_correo(nombre1, nombre2, apellido);
                    lista_personas->insertar_persona(nombre1, nombre2, apellido, correo);
                    cout << endl << "Persona ingresado correctamente" << endl;
                    system("pause");
            break;
        case 2:
            cout << "aun no listo" << endl;
            system("pause");
            break;
        case 3:
            dato_char = ingresar_letra.ingresar("Ingrese la letra: ", "char");
                    cout << endl;
                    lista_personas->eliminarLetra(dato_char);
                    system("pause");
            break;
        case 4:
            lista_personas->mostrar_persona();
                    cout << endl;
                    system("pause");
            break;
        case 5:
                    lista_personas->guardarEnArchivo("Principal.txt");
                    system("pause");
                    break;
        case 6:
                    lista_personas->cargarDesdeArchivo("Principal.txt");
                    system("pause");
                    break;
        case 7:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 7);

    return 0;
}

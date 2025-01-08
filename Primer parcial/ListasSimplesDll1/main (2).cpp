/************************************************************************
 * ESPE                                                                 *
 * ALUMNOS:  Eduardo Altamirano,Adonny Calero,Josue Chango             *
 * FECHA CREACION: Lunes, 18 de noviembre de 2024                       *
 * FECHA MODIFICACION: Lunes, 18 de noviembre de 2024                   *
 * Enunciado del problema: Crear los metodos Insertar, Buscar           *
 y Eliminar elementos de una lista Simple, Doble y Circular             *
 * Nivel: TERCERO     NRC: 1978                                        *
 ***********************************************************************/
#include "ListasSimples.cpp"
#include "Nodo.cpp"

#include <windows.h>
#include <iostream>
#include <string>

typedef int (*IngresarInt)(char*);

int main() {
    // Cargar la DLL
    HINSTANCE hDLL = LoadLibrary("ValidacionesDLL.dll");
    if (!hDLL) {
        std::cerr << "No se pudo cargar la DLL.\n";
        return 1;
    }

    // Cargar las funciones
    IngresarInt ingresar = (IngresarInt)GetProcAddress(hDLL, "ingresar");
    if (!ingresar) {
        std::cerr << "No se pudo cargar la función 'ingresar'.\n";
        FreeLibrary(hDLL);
        return 1;
    }

    ListaSimples* lista = new ListaSimples();
    int opcion, dato;

    do {
        system("cls");
        std::cout << "***********Listas Simples***********" << std::endl;
        std::cout << "1. Insertar" << std::endl;
        std::cout << "2. Buscar" << std::endl;
        std::cout << "3. Eliminar" << std::endl;
        std::cout << "4. Mostrar" << std::endl;
        std::cout << "5. Salir" << std::endl;

        do {
            opcion = ingresar("Opcion: ");
            if (opcion < 1 || opcion > 5) {
                std::cout << "Opción no válida. Inténtalo nuevamente.\n";
            }
        } while (opcion < 1 || opcion > 5);

        switch (opcion) {
        case 1: { // Insertar
            dato = ingresar("\nIngrese el dato a insertar: ");
            lista->Insertar(dato);
            break;
        }
        case 2: { // Buscar
            dato = ingresar("\nIngrese el dato a buscar: ");
            lista->Buscar(dato);
            break;
        }
        case 3: { // Eliminar
            dato = ingresar("\nIngrese el dato a eliminar: ");
            lista->Eliminar(dato);
            break;
        }
        case 4: // Mostrar
            lista->Mostrar();
            break;
        }
        system("pause");
    } while (opcion != 5);

    // Liberar la DLL
    FreeLibrary(hDLL);

    return 0;
}


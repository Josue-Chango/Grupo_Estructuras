#include <iostream>
#include "Cola.cpp"
#include <limits>
#include "Validaciones.cpp"

using namespace std;

bool esEntero(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    // Crear instancias de Cola con tipos específicos
    Cola<string, int> colaEnteros;  // Cola para elementos con nombre tipo string y edad tipo int
    Cola<string, float> colaFlotantes;  // Cola para elementos con nombre tipo string y edad tipo float
    Cola<string, double> colaDobles;  // Cola para elementos con nombre tipo string y edad tipo double
    Cola<string, string> colaStrings;  // Cola para elementos con nombre tipo string y edad tipo string
    Cola<string, char> colaLetras;  // Cola para elementos con nombre tipo string y edad tipo char

    int opcion;
    bool salir = false;
    string linea;
    bool repite = true;

    do {
        system("cls");

        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar elemento" << endl;
        cout << "2. Eliminar elemento" << endl;
        cout << "3. Buscar elemento" << endl;
        cout << "4. Editar elemento" << endl;
        cout << "5. Mostrar elementos" << endl;
        cout << "6. Salir" << endl;

        do {
            cout << "Opcion: ";
            getline(cin, linea); 

            if (esEntero(linea)) {
                repite = false;
                opcion = stoi(linea);
                if (opcion > 6 || opcion < 1) {
                    repite = true;
                    cout << "Opción fuera de rango. Intenta de nuevo." << endl;
                }
            } else {
                cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
            }
        } while (repite);

        switch (opcion) {
        case 1: { // Agregar elemento
            string nombre;
            cout << "Ingrese el nombre: ";
            getline(cin, nombre);

            string entradaEdad;
            bool entradaValida = false;
            do {
                cout << "Ingrese la edad: ";
                getline(cin, entradaEdad);

                if (esEntero(entradaEdad)) {
                    int edad = stoi(entradaEdad);  // Usamos entero para este ejemplo.

                    // Crear un nuevo elemento con nombre y edad
                    Elemento<string, int> nuevo(nombre, edad);
                    colaEnteros.agregarElemento(nuevo);  // Usamos colaEnteros en este caso

                    entradaValida = true;
                } else {
                    cout << "La edad ingresada no es válida. Inténtalo nuevamente." << endl;
                }
            } while (!entradaValida);
            break;
        }
        case 2: { // Eliminar elemento
            colaEnteros.eliminarElemento();  // Eliminar de la cola de enteros
            break;
        }
        case 3: { // Buscar elemento
            string nombre;
            cout << "Ingrese el nombre a buscar: ";
            getline(cin, nombre);
            colaEnteros.buscarElemento(nombre);  // Buscar en la cola de enteros
            break;
        }
        case 4: { // Editar elemento
            string nombre;
            cout << "Ingrese el nombre a editar: ";
            getline(cin, nombre);
            colaEnteros.editarElemento(nombre);  // Editar en la cola de enteros
            break;
        }
        case 5: { // Mostrar elementos
            colaEnteros.mostrarElementos();  // Mostrar en la cola de enteros
            break;
        }
        case 6: { // Salir
            salir = true;
            break;
        }
        default: {
            cout << "Opción inválida. Intente de nuevo." << endl;
            break;
        }
        }
        system("pause");
    } while (!salir);

    return 0;
}




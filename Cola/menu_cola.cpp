#include <iostream>
#include "Cola.cpp"
#include <limits>

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
    Cola cola;
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
            getline(cin, linea);  // Usamos getline para leer la opción

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
            Elemento nuevo;

            // Usamos los métodos setter para establecer los valores
            string nombre;
            cout << "Ingrese el nombre: ";
            getline(cin, nombre);  // Leemos el nombre del usuario
            nuevo.setNombre(nombre);  // Usamos el setter para asignar el nombre

            string entradaEdad;
            bool entradaValida = false;
            do {
                cout << "Ingrese la edad: ";
                getline(cin, entradaEdad);

                if (esEntero(entradaEdad)) {
                    nuevo.setEdad(stoi(entradaEdad));  // Usamos el setter para asignar la edad
                    entradaValida = true;
                } else {
                    cout << "La edad ingresada no es válida. Inténtalo nuevamente." << endl;
                }
            } while (!entradaValida);

            cola.agregarElemento(nuevo);
            break;
        }
        case 2: { // Eliminar elemento
            cola.eliminarElemento();
            break;
        }
        case 3: { // Buscar elemento
            string nombre;
            cout << "Ingrese el nombre a buscar: ";
            getline(cin, nombre);
            cola.buscarElemento(nombre);
            break;
        }
        case 4: { // Editar elemento
            string nombre;
            cout << "Ingrese el nombre a editar: ";
            getline(cin, nombre);
            cola.editarElemento(nombre);
            break;
        }
        case 5: { // Mostrar elementos
            cola.mostrarElementos();
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




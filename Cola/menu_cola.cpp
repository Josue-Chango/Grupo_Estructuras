#include <iostream>
#include "Elemento.cpp"
#include <limits>

using namespace std;

int main() {
    queue<Elemento> cola;
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
                }
            } else {
                cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
            }
        } while (repite);

        switch (opcion) {
        case 1: { // Agregar elemento
            Elemento nuevo;
            cout << "Ingrese el nombre: ";
            cin >> nuevo.nombre;
            cin.ignore(); // Limpiar el búfer después de leer con cin

            string entradaEdad;
            bool entradaValida = false;
            do {
                cout << "Ingrese la edad: ";
                cin >> entradaEdad;

                if (esEntero(entradaEdad)) {
                    nuevo.edad = stoi(entradaEdad);
                    entradaValida = true;
                } else {
                    cout << "La edad ingresada no es válida. Inténtalo nuevamente." << endl;
                }
            } while (!entradaValida);

            cola.push(nuevo);
            cout << "Elemento agregado a la cola." << endl;
            break;
        }
            case 2: { // Eliminar elemento
                if (cola.empty()) {
                    cout << "La cola está vacía." << endl;
                } else {
                    cout << "Elemento eliminado: " << cola.front().nombre << ", " << cola.front().edad << endl;
                    cola.pop();
                }
                break;
            }
            case 3: { // Buscar elemento
                if (cola.empty()) {
                    cout << "La cola está vacía." << endl;
                } else {
                    string nombre;
                    cout << "Ingrese el nombre a buscar: ";
                    cin >> nombre;
                    bool encontrado = false;
                    queue<Elemento> temp;
                    while (!cola.empty()) {
                        Elemento actual = cola.front();
                        cola.pop();
                        if (actual.nombre == nombre) {
                            cout << "Elemento encontrado: " << actual.nombre << ", " << actual.edad << endl;
                            encontrado = true;
                        }
                        temp.push(actual);
                    }
                    if (!encontrado) {
                        cout << "Elemento no encontrado." << endl;
                    }
                    while (!temp.empty()) {
                        cola.push(temp.front());
                        temp.pop();
                    }
                }
                break;
            }
            case 4: { // Editar elemento
                if (cola.empty()) {
                    cout << "La cola está vacía." << endl;
                } else {
                    string nombre;
                    cout << "Ingrese el nombre a editar: ";
                    cin >> nombre;
                    bool encontrado = false;
                    queue<Elemento> temp;
                    while (!cola.empty()) {
                        Elemento actual = cola.front();
                        cola.pop();
                        if (actual.nombre == nombre) {
                            cout << "Ingrese el nuevo nombre: ";
                            cin >> actual.nombre;
                            cout << "Ingrese la nueva edad: ";
                            cin >> actual.edad;
                            temp.push(actual);
                            cout << "Elemento editado." << endl;
                            encontrado = true;
                        } else {
                            temp.push(actual);
                        }
                    }
                    if (!encontrado) {
                        cout << "Elemento no encontrado." << endl;
                    }
                    while (!temp.empty()) {
                        cola.push(temp.front());
                        temp.pop();
                    }
                }
                break;
            }
            case 5: { // Mostrar elementos
                if (cola.empty()) {
                    cout << "La cola está vacía." << endl;
                } else {
                    queue<Elemento> temp;
                    while (!cola.empty()) {
                        Elemento actual = cola.front();
                        cola.pop();
                        cout << "Nombre: " << actual.nombre << ", Edad: " << actual.edad << endl;
                        temp.push(actual);
                    }
                    while (!temp.empty()) {
                        cola.push(temp.front());
                        temp.pop();
                    }
                }
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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el búfer
    } while (!salir);

    return 0;
}


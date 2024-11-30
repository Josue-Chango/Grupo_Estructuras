#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Definimos la estructura del elemento de la cola
struct Elemento {
    string nombre;
    int edad;
};

bool esEntero(string linea) {
	int i = 0;
    if (linea[0] == '-') {
		i = 1;
	}
    for (; i < linea.length(); i++) {
        if (linea[i] < '0' || linea[i] > '9') {
			return false;
		}
	}
	return true;
}



int main() {
    queue<Elemento> cola;
    int opcion;
    bool salir = false;
    string linea;
    bool rep = true;
    bool repite = true;
    bool repetir = true;
    

    do{
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
                opcion = atoi(linea.c_str());
                if (opcion > 5 || opcion < 1) {
                    repetir = true;
                }
            }
            else {
                cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
            }
        } while (repite);
        //cin >> opcion;
        opcion = atoi(linea.c_str());

        switch (opcion) {
            case 1: { // Agregar elemento
                Elemento nuevo;
                cout << "Ingrese el nombre: ";
                cin >> nuevo.nombre;
                cout << "Ingrese la edad: ";
                cin >> nuevo.edad;
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
    }while(opcion !=6 );
    return 0;
}

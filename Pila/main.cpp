#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Definimos la estructura del elemento de la pila
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
    stack<Elemento> pila;
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
                pila.push(nuevo);
                cout << "Elemento agregado a la pila." << endl;
                break;
            }
            case 2: { // Eliminar elemento
                if (pila.empty()) {
                    cout << "La pila está vacía." << endl;
                } else {
                    cout << "Elemento eliminado: " << pila.top().nombre << ", " << pila.top().edad << endl;
                    pila.pop();
                }
                break;
            }
            case 3: { // Buscar elemento
                if (pila.empty()) {
                    cout << "La pila está vacía." << endl;
                } else {
                    string nombre;
                    cout << "Ingrese el nombre a buscar: ";
                    cin >> nombre;
                    bool encontrado = false;
                    stack<Elemento> temp;
                    while (!pila.empty()) {
                        Elemento actual = pila.top();
                        pila.pop();
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
                        pila.push(temp.top());
                        temp.pop();
                    }
                }
                break;
            }
            case 4: { // Editar elemento
                if (pila.empty()) {
                    cout << "La pila está vacía." << endl;
                } else {
                    string nombre;
                    cout << "Ingrese el nombre a editar: ";
                    cin >> nombre;
                    bool encontrado = false;
                    stack<Elemento> temp;
                    while (!pila.empty()) {
                        Elemento actual = pila.top();
                        pila.pop();
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
                        pila.push(temp.top());
                        temp.pop();
                    }
                }
                break;
            }
            case 5: { // Mostrar elementos
                if (pila.empty()) {
                    cout << "La pila está vacía." << endl;
                } else {
                    stack<Elemento> temp;
                    while (!pila.empty()) {
                        Elemento actual = pila.top();
                        pila.pop();
                        cout << "Nombre: " << actual.nombre << ", Edad: " << actual.edad << endl;
                        temp.push(actual);
                    }
                    while (!temp.empty()) {
                        pila.push(temp.top());
                        temp.pop();
                    }
                }
            }
            /*default: {
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
            }*/
        }
        system("pause");
    }while(opcion != 6);
    return 0;
}



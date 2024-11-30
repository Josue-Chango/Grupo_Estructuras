#include "Cola.h"
#include <queue>

using namespace std;

void Cola::agregarElemento(const Elemento& elemento) {
    cola.push(elemento);
    cout << "Elemento agregado a la cola." << endl;
}

void Cola::eliminarElemento() {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
    } else {
        cout << "Elemento eliminado: ";
        cola.front().mostrar();
        cola.pop();
    }
}

void Cola::buscarElemento(const string& nombre) {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
    } else {
        bool encontrado = false;
        queue<Elemento> temp;
        while (!cola.empty()) {
            Elemento actual = cola.front();
            cola.pop();
            if (actual.getNombre() == nombre) {
                cout << "Elemento encontrado: ";
                actual.mostrar();
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
}

void Cola::editarElemento(const string& nombre) {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
    } else {
        bool encontrado = false;
        queue<Elemento> temp;
        while (!cola.empty()) {
            Elemento actual = cola.front();
            cola.pop();
            if (actual.getNombre() == nombre) {
                cout << "Ingrese el nuevo nombre: ";
                string nuevoNombre;
                getline(cin, nuevoNombre);
                actual.setNombre(nuevoNombre);

                cout << "Ingrese la nueva edad: ";
                int nuevaEdad;
                cin >> nuevaEdad;
                actual.setEdad(nuevaEdad);

                cout << "Elemento editado." << endl;
                temp.push(actual);
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
}

void Cola::mostrarElementos() {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
    } else {
        queue<Elemento> temp;
        while (!cola.empty()) {
            Elemento actual = cola.front();
            cola.pop();
            actual.mostrar();
            temp.push(actual);
        }
        while (!temp.empty()) {
            cola.push(temp.front());
            temp.pop();
        }
    }
}



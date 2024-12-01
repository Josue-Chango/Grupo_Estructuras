#include "Cola.h"
#include <queue>

using namespace std;

template<typename T, typename U>
void Cola<T, U>::agregarElemento(const Elemento<T, U>& elemento) {
    cola.push(elemento);
    cout << "Elemento agregado a la cola." << endl;
}

template<typename T, typename U>
void Cola<T, U>::eliminarElemento() {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
    } else {
        cout << "Elemento eliminado: ";
        cola.front().mostrar();
        cola.pop();
    }
}

template<typename T, typename U>
void Cola<T, U>::buscarElemento(const string& nombre) {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
    } else {
        bool encontrado = false;
        queue<Elemento<T, U>> temp;
        while (!cola.empty()) {
            Elemento<T, U> actual = cola.front();
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

template<typename T, typename U>
void Cola<T, U>::editarElemento(const string& nombre) {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
    } else {
        bool encontrado = false;
        queue<Elemento<T, U>> temp;
        while (!cola.empty()) {
            Elemento<T, U> actual = cola.front();
            cola.pop();
            if (actual.getNombre() == nombre) {
                cout << "Ingrese el nuevo nombre: ";
                string nuevoNombre;
                getline(cin, nuevoNombre);
                actual.setNombre(nuevoNombre);

                cout << "Ingrese la nueva edad: ";
                U nuevaEdad;
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

template<typename T, typename U>
void Cola<T, U>::mostrarElementos() {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
    } else {
        queue<Elemento<T, U>> temp;
        while (!cola.empty()) {
            Elemento<T, U> actual = cola.front();
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





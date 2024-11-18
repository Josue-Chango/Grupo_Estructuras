#include "Matriz.h"

using namespace std;

// Constructor
Matriz::Matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    datos = (float**)malloc(filas * sizeof(float*));
    for (int i = 0; i < filas; i++) {
        datos[i] = (float*)malloc(columnas * sizeof(float));
        if (datos[i] == nullptr) {
            cerr << "Error al asignar memoria para la matriz.\n";
            exit(1);
        }
    }
}

// Destructor
Matriz::~Matriz() {
    for (int i = 0; i < filas; i++) {
        free(datos[i]);
    }
    free(datos);
}

// Método para rellenar la matriz con datos ingresados por el usuario
void Matriz::rellenar(const string& nombre) {
    cout << "Ingresa los elementos de la matriz " << nombre << " (" << filas << "x" << columnas << "):\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> datos[i][j];
        }
    }
}

// Método para imprimir la matriz
void Matriz::imprimir() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << datos[i][j] << "\t";
        }
        cout << endl;
    }
}

// Método para obtener los datos de la matriz
float** Matriz::obtenerDatos() const {
    return datos;
}

// Métodos para obtener dimensiones
int Matriz::obtenerFilas() const {
    return filas;
}

int Matriz::obtenerColumnas() const {
    return columnas;
}

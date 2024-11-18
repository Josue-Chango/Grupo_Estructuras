#include "Matriz.h"

using namespace std;

// Constructor
Matriz::Matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    datos = (double**)malloc(filas * sizeof(double*));
    for (int i = 0; i < filas; i++) {
        datos[i] = (double*)malloc(columnas * sizeof(double));
        if (datos[i] == nullptr) {
            throw runtime_error("Error al asignar memoria para la matriz.");
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

// Métodos
void Matriz::rellenar() {
    cout << "Ingresa los elementos de la matriz (" << filas << "x" << columnas << "):\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> datos[i][j];
        }
    }
}

void Matriz::imprimir() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << datos[i][j] << "\t";
        }
        cout << endl;
    }
}

double** Matriz::obtenerDatos() const {
    return datos;
}

int Matriz::obtenerFilas() const {
    return filas;
}

int Matriz::obtenerColumnas() const {
    return columnas;
}

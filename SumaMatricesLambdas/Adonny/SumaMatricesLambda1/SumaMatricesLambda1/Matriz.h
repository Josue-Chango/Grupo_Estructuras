#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Matriz {
private:
    int filas;
    int columnas;
    double** datos;

public:
    // Constructor
    Matriz(int filas, int columnas);

    // Destructor
    ~Matriz();

    // Métodos
    void rellenar();
    void imprimir() const;
    double** obtenerDatos() const;
    int obtenerFilas() const;
    int obtenerColumnas() const;
};

#endif // MATRIZ_H

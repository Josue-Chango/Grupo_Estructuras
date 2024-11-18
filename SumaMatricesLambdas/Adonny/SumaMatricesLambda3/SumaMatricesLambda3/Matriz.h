#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <cstdlib>
#include <string>

class Matriz {
private:
    int filas;
    int columnas;
    float** datos;

public:
    // Constructor
    Matriz(int filas, int columnas);

    // Destructor
    ~Matriz();

    // Métodos
    void rellenar(const std::string& nombre);
    void imprimir() const;
    float** obtenerDatos() const;
    int obtenerFilas() const;
    int obtenerColumnas() const;
};

#endif // MATRIZ_H

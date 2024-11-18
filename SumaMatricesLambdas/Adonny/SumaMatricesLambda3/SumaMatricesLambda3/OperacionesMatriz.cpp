#include "OperacionesMatriz.h"

using namespace std;

// Método para sumar dos matrices y guardar el resultado en una tercera
void OperacionesMatriz::sumar(const Matriz& mat1, const Matriz& mat2, Matriz& matSuma) {
    if (mat1.obtenerFilas() != mat2.obtenerFilas() ||
        mat1.obtenerColumnas() != mat2.obtenerColumnas()) {
        cerr << "Error: Las matrices deben tener las mismas dimensiones para sumarlas.\n";
        exit(1);
    }

    int filas = mat1.obtenerFilas();
    int columnas = mat1.obtenerColumnas();
    float** datos1 = mat1.obtenerDatos();
    float** datos2 = mat2.obtenerDatos();
    float** datosSuma = matSuma.obtenerDatos();

    auto lambdaSuma = [&, filas, columnas](float** mat1, float** mat2, float** matSuma) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                [&, i, j](float a, float b) mutable {
                    matSuma[i][j] = a + b;
                }(mat1[i][j], mat2[i][j]);
            }
        }
    };

    lambdaSuma(datos1, datos2, datosSuma);
}

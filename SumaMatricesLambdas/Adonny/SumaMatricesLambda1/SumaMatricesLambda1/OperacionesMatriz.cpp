#include "OperacionesMatriz.h"

using namespace std;

// Metodo para sumar dos matrices
double OperacionesMatriz::sumarMatrices(const Matriz& mat1, const Matriz& mat2) {
    if (mat1.obtenerFilas() != mat2.obtenerFilas() || mat1.obtenerColumnas() != mat2.obtenerColumnas()) {
        throw invalid_argument("Las matrices deben tener las mismas dimensiones para sumarlas.");
    }

    int filas = mat1.obtenerFilas();
    int columnas = mat1.obtenerColumnas();
    double** datos1 = mat1.obtenerDatos();
    double** datos2 = mat2.obtenerDatos();

    auto sumaTotalLambda = [](double** m1, double** m2, int filas, int columnas) -> double {
        double sumaTotal = 0;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                sumaTotal += m1[i][j] + m2[i][j];
            }
        }
        return sumaTotal;
    };

    return sumaTotalLambda(datos1, datos2, filas, columnas);
}

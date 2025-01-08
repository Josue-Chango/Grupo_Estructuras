#include <iostream>
#include "Matriz.h"
#include "OperacionesMatriz.h"

using namespace std;

int main() {
    const int MAX = 3;

    // Crear las matrices
    Matriz matriz1(MAX, MAX);
    Matriz matriz2(MAX, MAX);
    Matriz matrizSuma(MAX, MAX);

    // Rellenar las matrices con datos ingresados por el usuario
    matriz1.rellenar("1");
    matriz2.rellenar("2");

    // Imprimir las matrices originales
    cout << "\nMatriz 1:\n";
    matriz1.imprimir();
    cout << "\nMatriz 2:\n";
    matriz2.imprimir();

    // Realizar la suma de las matrices
    OperacionesMatriz::sumar(matriz1, matriz2, matrizSuma);

    // Imprimir la matriz resultante
    cout << "\nLa matriz suma es:\n";
    matrizSuma.imprimir();

    return 0;
}

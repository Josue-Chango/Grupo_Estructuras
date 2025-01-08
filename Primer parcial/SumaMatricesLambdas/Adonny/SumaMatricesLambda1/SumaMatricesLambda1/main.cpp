#include <iostream>
#include "Matriz.cpp"
#include "OperacionesMatriz.cpp"

using namespace std;

int main() {
    const int MAX = 3;

    // Crear las matrices
    Matriz matriz1(MAX, MAX);
    Matriz matriz2(MAX, MAX);

    // Rellenar las matrices
    cout << "Primera matriz:\n";
    matriz1.rellenar();

    cout << "\nSegunda matriz:\n";
    matriz2.rellenar();

    // Imprimir las matrices
    cout << "\nMatriz 1:\n";
    matriz1.imprimir();

    cout << "\nMatriz 2:\n";
    matriz2.imprimir();

    // Calcular la suma de las matrices
    try {
        double sumaTotal = OperacionesMatriz::sumarMatrices(matriz1, matriz2);
        cout << "\nLa suma de las matrices es: " << sumaTotal << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

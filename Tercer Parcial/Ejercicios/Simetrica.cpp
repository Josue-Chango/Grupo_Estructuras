#include <iostream>
#include <vector>
using namespace std;

// Función para imprimir la matriz
void imprimirMatriz(vector<vector<int>> &matriz, int N) {
    cout << "Matriz:" << endl;
    for (const auto &fila : matriz) {
        for (int num : fila) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Función para verificar si una matriz es simétrica
bool esSimetrica(vector<vector<int>> &matriz, int N) {
    bool es_transpuesta = true;
    
    for (int columna = 0; columna < N && es_transpuesta; columna++) {
        int fila = N - 1;
        while (fila > columna && es_transpuesta) {
            if (matriz[fila][columna] != matriz[columna][fila]) {
                es_transpuesta = false;
            }
            fila--;
        }
    }
    
    return es_transpuesta;
}

int main() {
    int N = 4; // Tamaño de la matriz cuadrada
    vector<vector<int>> matriz = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 8, 9},
        {4, 7, 9, 10}
    };
    
    imprimirMatriz(matriz, N);
    cout << "La matriz es " << (esSimetrica(matriz, N) ? "simetrica" : "no simetrica") << endl;
    system("pause");
    return 0;
}

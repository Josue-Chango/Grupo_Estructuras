#include <iostream>
#include <vector>
using namespace std;

// Función para verificar si una fila está ordenada
bool estaOrdenadaFila(const vector<int>& fila) {
    for (int i = 1; i < fila.size(); i++) {
        if (fila[i] < fila[i-1]) return false;
    }
    return true;
}

// Función para verificar si una columna está ordenada
bool estaOrdenadaColumna(const vector<vector<int>>& matriz, int columna) {
    for (int i = 1; i < matriz.size(); i++) {
        if (matriz[i][columna] < matriz[i-1][columna]) return false;
    }
    return true;
}

// Función recursiva para verificar si la matriz está ordenada
bool estaOrdenadaMatriz(const vector<vector<int>>& matriz, int fila_inicio, int fila_fin, int columna_inicio, int columna_fin) {
    if (fila_inicio > fila_fin || columna_inicio > columna_fin) return true;
    
    // Verificar la fila actual
    for (int i = fila_inicio; i <= fila_fin; i++) {
        if (!estaOrdenadaFila(matriz[i])) return false;
    }
    
    // Verificar la columna actual
    for (int j = columna_inicio; j <= columna_fin; j++) {
        if (!estaOrdenadaColumna(matriz, j)) return false;
    }
    
    // Recursión en submatrices
    return estaOrdenadaMatriz(matriz, fila_inicio + 1, fila_fin, columna_inicio + 1, columna_fin);
}

int main() {
    vector<vector<int>> matriz = {
        {1, 3, 6, 8, 10},
        {2, 4, 7, 9, 10},
        {4, 8, 11, 14, 14},
        {5, 10, 12, 15, 16}
    };

    if (estaOrdenadaMatriz(matriz, 0, matriz.size() - 1, 0, matriz[0].size() - 1)) {
        cout << "La matriz esta ordenada." << endl;
    } else {
        cout << "La matriz NO esta ordenada." << endl;
    }
    system("pause");
    return 0;
}

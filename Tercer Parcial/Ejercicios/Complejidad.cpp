#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Función para imprimir la matriz
void imprimirMatriz(vector<vector<int>> &matriz) {
    for (const auto &fila : matriz) {
        for (int num : fila) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Función para convertir matriz a vector
vector<int> matrizAVector(vector<vector<int>> &matriz) {
    vector<int> vectorAux;
    for (const auto &fila : matriz) {
        for (int num : fila) {
            vectorAux.push_back(num);
        }
    }
    return vectorAux;
}

// Función para convertir vector a matriz
vector<vector<int>> vectorAMatriz(vector<int> &vectorAux, int n) {
    vector<vector<int>> matriz(n, vector<int>(n));
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = vectorAux[index++];
        }
    }
    return matriz;
}

int main() {
    int n = 4; // Tamaño de la matriz cuadrada (4x4)
    vector<vector<int>> matriz = {
        {5, 8, 3, 7},
        {2, 6, 4, 9},
        {1, 10, 12, 11},
        {15, 14, 13, 16}
    };
    
    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);
    
    // Convertir matriz a vector
    vector<int> vectorAux = matrizAVector(matriz);
    
    // Ordenar el vector (Bubble Sort con O(n^2))
    for (int i = 0; i < vectorAux.size() - 1; i++) {
        for (int j = 0; j < vectorAux.size() - i - 1; j++) {
            if (vectorAux[j] > vectorAux[j + 1]) {
                swap(vectorAux[j], vectorAux[j + 1]);
            }
        }
    }
    
    // Convertir vector ordenado a matriz
    matriz = vectorAMatriz(vectorAux, n);
    
    cout << "\nMatriz ordenada:" << endl;
    imprimirMatriz(matriz);
    system("pause");
    return 0;
}

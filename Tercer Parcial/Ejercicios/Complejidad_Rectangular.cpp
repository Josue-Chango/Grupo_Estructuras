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
vector<vector<int>> vectorAMatriz(vector<int> &vectorAux, int n, int m) {
    vector<vector<int>> matriz(n, vector<int>(m));
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = vectorAux[index++];
        }
    }
    return matriz;
}

int main() {
    int n = 4, m = 5; // Tamaño de la matriz rectangular (4 filas x 5 columnas)
    vector<vector<int>> matriz = {
        {14, 5, 8, 6, 3},
        {7, 12, 10, 2, 1},
        {4, 15, 9, 13, 11},
        {16, 14, 6, 7, 9}
    };
    
    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);
    
    // Convertir matriz a vector
    vector<int> vectorAux = matrizAVector(matriz);
    
    // Ordenar el vector (Bubble Sort con O((nm)^2))
    for (int i = 0; i < vectorAux.size() - 1; i++) {
        for (int j = 0; j < vectorAux.size() - i - 1; j++) {
            if (vectorAux[j] > vectorAux[j + 1]) {
                swap(vectorAux[j], vectorAux[j + 1]);
            }
        }
    }
    
    // Convertir vector ordenado a matriz
    matriz = vectorAMatriz(vectorAux, n, m);
    
    cout << "\nMatriz ordenada:" << endl;
    imprimirMatriz(matriz);
    system("pause");
    return 0;
}

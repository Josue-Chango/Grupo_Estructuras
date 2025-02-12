#include <iostream>
#include <vector>
using namespace std;

// Función auxiliar para verificar si dos vértices adyacentes tienen el mismo color
bool esValido(const vector<vector<int>>& grafo, const vector<int>& colores, int vertice, int color) {
    for (int i = 0; i < grafo.size(); i++) {
        if (grafo[vertice][i] == 1 && colores[i] == color) {
            return false; // No se puede asignar el mismo color a dos vértices adyacentes
        }
    }
    return true;
}

// Función recursiva de backtracking para intentar colorear el grafo
bool colorearGrafoRecursivo(const vector<vector<int>>& grafo, vector<int>& colores, int m, int vertice) {
    if (vertice == grafo.size()) {
        return true; // Todos los vértices han sido coloreados
    }

    for (int color = 1; color <= m; color++) {
        if (esValido(grafo, colores, vertice, color)) {
            colores[vertice] = color;
            if (colorearGrafoRecursivo(grafo, colores, m, vertice + 1)) {
                return true;
            }
            colores[vertice] = 0; // Deshacer la asignación si no es válida más adelante
        }
    }
    return false; // No es posible colorear el grafo con m colores
}

// Función principal para verificar si es posible colorear el grafo con m colores
bool colorearGrafo(const vector<vector<int>>& grafo, int m) {
    vector<int> colores(grafo.size(), 0); // 0 significa que el vértice no ha sido coloreado
    return colorearGrafoRecursivo(grafo, colores, m, 0);
}

int main() {
    // Matriz de adyacencia del grafo
    vector<vector<int>> grafo = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    int m;
    cout << "Ingrese el numero de colores (m): ";
    cin >> m;

    if (colorearGrafo(grafo, m)) {
        cout << "Es posible colorear el grafo con " << m << " colores." << endl;
    } else {
        cout << "No es posible colorear el grafo con " << m << " colores." << endl;
    }
    system("pause");
    return 0;
}

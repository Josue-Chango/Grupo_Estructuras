#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::find

using namespace std;

void hamiltoniano(vector<vector<int>> &G, vector<int> &x, int k, int N) {
    if (k == N) { // Si se completa un ciclo Hamiltoniano
        for (int i : x) cout << i + 1 << " ";
        cout << x[0] + 1 << endl; // Se vuelve al inicio para cerrar el ciclo
        return;
    }
    
    for (int i = 1; i < N; i++) { // Explorar los vértices
        if (G[x[k - 1]][i] && find(x.begin(), x.begin() + k, i) == (x.begin() + k)) { 
            // Si el vértice `i` es adyacente y no ha sido visitado aún
            x[k] = i;
            hamiltoniano(G, x, k + 1, N); // Llamada recursiva
        }
    }
}

int main() {
    vector<vector<int>> G = {
        {0, 1, 1, 1}, 
        {1, 0, 1, 1}, 
        {1, 1, 0, 1}, 
        {1, 1, 1, 0}
    };

    int N = G.size();
    vector<int> x(N, -1);
    x[0] = 0; // Se comienza desde el primer nodo

    cout << "Ciclos Hamiltonianos encontrados:" << endl;
    hamiltoniano(G, x, 1, N);

    return 0;
}

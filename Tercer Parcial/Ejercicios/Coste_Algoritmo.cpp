#include <iostream>
#include <vector>
using namespace std;

// Función para imprimir el vector
void imprimirVector(const vector<int> &v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

// Algoritmo de ordenación por selección directa
void seleccionSort(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int posMenor = i;
        int valMenor = v[i];
        for (int j = i + 1; j < n; j++) {
            if (v[j] < valMenor) {
                valMenor = v[j];
                posMenor = j;
            }
        }
        if (posMenor != i) {
            v[posMenor] = v[i];
            v[i] = valMenor;
        }
    }
}

int main() {
    vector<int> v = {29, 10, 14, 37, 13};
    cout << "Vector original:" << endl;
    imprimirVector(v);
    
    seleccionSort(v);
    
    cout << "Vector ordenado:" << endl;
    imprimirVector(v);
    system("pause");
    return 0;
}

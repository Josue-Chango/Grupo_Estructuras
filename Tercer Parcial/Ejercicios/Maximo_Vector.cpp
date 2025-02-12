#include <iostream>
#include <vector>
using namespace std;

// Función recursiva para encontrar el máximo en un vector con Divide y Vencerás
int maximo(vector<int> &v, int inicio, int fin) {
    if (inicio == fin) {
        return v[inicio];
    }
    int medio = (inicio + fin) / 2;
    int maxIzq = maximo(v, inicio, medio);
    int maxDer = maximo(v, medio + 1, fin);
    return max(maxIzq, maxDer);
}

// Función para imprimir el vector
void imprimirVector(const vector<int> &v) {
    cout << "Vector: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {12, 3, 5, 7, 19, 26, 14, 8};
    imprimirVector(v);
    int maxValor = maximo(v, 0, v.size() - 1);
    cout << "El valor maximo en el vector es: " << maxValor << endl;
    system("pause");
    return 0;
}

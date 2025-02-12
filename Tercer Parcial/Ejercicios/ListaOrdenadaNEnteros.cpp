#include <iostream>
#include <vector>
using namespace std;

int encontrarIndice(vector<int>& a, int izquierda, int derecha) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (a[medio] == medio) {
            return medio;
        } else if (a[medio] < medio) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la lista: ";
    cin >> n;
    vector<int> a(n);
    cout << "Ingrese los elementos ordenados de la lista: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int resultado = encontrarIndice(a, 0, n - 1);
    if (resultado != -1) {
        cout << "El indice encontrado es: " << resultado << endl;
    } else {
        cout << "No se encontro un indice i tal que a[i] = i." << endl;
    }
    
    system("pause");
    return 0;
}

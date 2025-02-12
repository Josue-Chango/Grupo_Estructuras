#include <iostream>
#include <vector>
using namespace std;

vector<int> mejorSolucion;

void encontrarSubconjuntoMinimo(vector<int>& L, int s, vector<int>& actual, int suma, int indice) {
    if (suma == s) {
        if (mejorSolucion.empty() || actual.size() < mejorSolucion.size()) {
            mejorSolucion = actual;
        }
        return;
    }
    if (suma > s || indice >= L.size()) {
        return;
    }
    
    actual.push_back(L[indice]);
    encontrarSubconjuntoMinimo(L, s, actual, suma + L[indice], indice + 1);
    actual.pop_back();
    encontrarSubconjuntoMinimo(L, s, actual, suma, indice + 1);
}

int main() {
    int n, s;
    cout << "Ingrese el tamaño de la lista: ";
    cin >> n;
    vector<int> L(n);
    cout << "Ingrese los elementos de la lista: ";
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    cout << "Ingrese el valor de la suma objetivo: ";
    cin >> s;
    
    vector<int> actual;
    encontrarSubconjuntoMinimo(L, s, actual, 0, 0);
    
    if (!mejorSolucion.empty()) {
        cout << "Subconjunto minimo que suma " << s << ": ";
        for (int num : mejorSolucion) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No se encontro un subconjunto valido." << endl;
    }
    
    system("pause");
    return 0;
}

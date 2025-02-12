#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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

void evaluarComplejidades(int n) {
    cout << "Evaluacion de complejidades para n = " << n << ":" << endl;
    cout << "5 log(n): " << 5 * log(n) << endl;
    cout << "log(n^2): " << log(n * n) << endl;
    cout << "n log_10(n): " << n * log10(n) << endl;
    cout << "n^2 log(n): " << (n * n) * log(n) << endl;
    cout << "10n: " << 10 * n << endl;
    cout << "n^2: " << n * n << endl;
    double alpha = 0.5; // Tomamos un valor entre 0 y 1
    cout << "n^(1+alpha) (alpha=0.5): " << pow(n, 1 + alpha) << endl;
}

void contarOperaciones(int n) {
    long long operaciones = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            operaciones++; // Operación por la condición if
            for (int k = 0; k < j; k++) {
                operaciones += 2; // Dos operaciones dentro del bucle anidado
            }
        }
    }
    cout << "Numero de operaciones para n = " << n << " es: " << operaciones << endl;
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
    
    int valor_n;
    cout << "Ingrese un valor de n para evaluar complejidades: ";
    cin >> valor_n;
    evaluarComplejidades(valor_n);
    contarOperaciones(valor_n);
    
    system("pause");
    return 0;
}

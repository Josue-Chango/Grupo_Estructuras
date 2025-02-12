#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Función recursiva para calcular T(n)
long long T(int n) {
    if (n == 0) return 0; // Caso base
    return T(n - 1) + 3 * n - 3 + n * n * pow(3, n);
}

// Función iterativa basada en la expansión de la recurrencia
long long T_iterativo(int n) {
    vector<long long> T_vals(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        T_vals[i] = T_vals[i - 1] + 3 * i - 3 + i * i * pow(3, i);
    }
    return T_vals[n];
}

int main() {
    int n;
    cout << "Ingrese un valor de n: ";
    cin >> n;
    
    cout << "\nT(" << n << ") usando recursion: " << T(n) << endl;
    cout << "T(" << n << ") usando iteracion: " << T_iterativo(n) << endl;
    system("pause");
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

// Memoización para evitar cálculos repetitivos
unordered_map<int, long long> memo;

long long T(int n) {
    if (n <= 0) return 1; // Caso base
    if (memo.find(n) != memo.end()) return memo[n];
    
    // Recurrencia dada en el problema
    memo[n] = 4 * T(n - 1) - 5 * T(n - 2) + 2 * T(n - 3) + 1 + n * n + n * (1 << n);
    return memo[n];
}

void contarOperaciones(int n) {
    long long operaciones = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j <= n; j++) {
            int k = 0;
            while (k < j) {
                operaciones++;
                k++;
            }
        }
    }
    cout << "Numero de operaciones para n = " << n << " es: " << operaciones << endl;
}

long long T_iterativo(int n) {
    return n + n * log2(n);
}

long long T_general(int n) {
    return n + n * log2(n); // Expresión resuelta para el problema 5
}

long long T_expresion(int n) {
    return pow(2, n); // Expresión resuelta para el problema 6
}

bool verificarBigO(int n) {
    double f_n = 5 * n;
    double g_n = n * log2(n);
    double c = 5;
    return (f_n <= c * g_n);
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    
    cout << "T(" << n << ") = " << T(n) << endl;
    contarOperaciones(n);
    cout << "T_iterativo(" << n << ") = " << T_iterativo(n) << endl;
    cout << "T_general(" << n << ") = " << T_general(n) << endl;
    cout << "T_expresion(" << n << ") = " << T_expresion(n) << endl;
    
    if (verificarBigO(n)) {
        cout << "5n pertenece a O(n log n)" << endl;
    } else {
        cout << "5n NO pertenece a O(n log n)" << endl;
    }
    
    system("pause");
    return 0;
}

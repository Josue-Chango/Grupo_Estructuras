#include <iostream>
#include <unordered_map>
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

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    
    cout << "T(" << n << ") = " << T(n) << endl;
    contarOperaciones(n);
    system("pause");
    return 0;
}

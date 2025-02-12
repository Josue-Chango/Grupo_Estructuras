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

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    
    cout << "T(" << n << ") = " << T(n) << endl;
    system("pause");
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

// Función para resolver la recurrencia T(n) = T(n/10) + log10(n^2)
long long resolverRecurrencia(int n) {
    if (n == 1) return 1;
    return resolverRecurrencia(n / 10) + log10(n * n);
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Resultado de la recurrencia para n = " << n << " es: " << resolverRecurrencia(n) << endl;
    system("pause");
    return 0;
}

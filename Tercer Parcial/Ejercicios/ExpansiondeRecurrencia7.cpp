#include <iostream>
#include <cmath>
using namespace std;

// Función recursiva para resolver la recurrencia T(n) = 2T(n/4) + sqrt(n)
long long resolverRecurrencia(int n) {
    if (n == 1) return 1;
    return 2 * resolverRecurrencia(n / 4) + sqrt(n);
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Resultado de la recurrencia para n = " << n << " es: " << resolverRecurrencia(n) << endl;
    system("pause");
    return 0;
}


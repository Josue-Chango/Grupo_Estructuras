#include <iostream>
using namespace std;

void contarOperaciones(int n) {
    long long operaciones = 0;
    int i = 0;
    while (i <= n) {
        int j = i;
        while (j <= n) {
            operaciones += 2; // Dos operaciones dentro del bucle
            j++;
        }
        i++;
    }
    cout << "Numero de operaciones para n = " << n << " es: " << operaciones << endl;
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    contarOperaciones(n);
    system("pause");
    return 0;
}

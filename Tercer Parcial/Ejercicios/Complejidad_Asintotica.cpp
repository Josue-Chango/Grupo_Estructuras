#include <iostream>
#include <cmath>
using namespace std;

// Función f(n) = n^2 - 3n + 1
double f(int n) {
    return pow(n, 2) - 3 * n + 1;
}

// Función g(n) = n^2
double g(int n) {
    return pow(n, 2);
}

int main() {
    double c = 0.5;  // Valor de la constante c
    int n0 = 3 + sqrt(7); // Aproximación de n0

    cout << "Verificacion de complejidad Omega(Ω)" << endl;
    cout << "Para c = " << c << " y n0 = " << n0 << "\n" << endl;

    cout << " n  | f(n)   | c * g(n)     | Comparacion" << endl;
    cout << "----------------------------------------------" << endl;

    for (int n = n0; n <= n0 + 10; n++) {
        double fn = f(n);
        double cg = c * g(n);
        cout << " " << n << "  | " << fn << "  | " << cg << "  | "
             << (fn >= cg ? " Se cumple" : " No se cumple") << endl;
    }
    system("pause");
    return 0;
}

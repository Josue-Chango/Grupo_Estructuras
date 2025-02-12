#include <iostream>
#include <cmath>
using namespace std;

// Función que calcula la expresión
double funcion(int n) {
    return (pow(n, 2) / 4) + 3 * n - 1;
}

// Función que calcula n^2 para comparación
double n_cuadrado(int n) {
    return pow(n, 2);
}

int main() {
    int n1 = 1, n2 = 1000; // Intervalo de n
    double c1 = 1.0 / 4.0, c2 = 1.0;
    
    // Verificar para diferentes valores de n
    cout << "Verificación para diferentes valores de n:" << endl;
    for (int n = n1; n <= n2; n++) {
        double f_n = funcion(n);
        double n2_val = n_cuadrado(n);
        
        cout << "n = " << n << ": Funcion = " << f_n << ", n^2 = " << n2_val << endl;
        
        // Comparación con c1 * n^2
        if (f_n >= c1 * n2_val) {
            cout << "Cumple Omega: " << f_n << " >= " << c1 * n2_val << endl;
        }
        
        // Comparación con c2 * n^2
        if (f_n <= c2 * n2_val) {
            cout << "Cumple O: " << f_n << " <= " << c2 * n2_val << endl;
        }
    }

    system("pause");

    return 0;
}

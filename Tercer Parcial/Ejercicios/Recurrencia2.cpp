#include <iostream>
#include <cmath>
#include <chrono> // Para medir el tiempo de ejecución
using namespace std;
using namespace std::chrono;

// Función recursiva para calcular T(n)
long long T(int n) {
    if (n == 0) return 1; // Suponemos un caso base T(0) = 1
    return T(n - 1) + 3 * n - 3 + pow(n, 3) * pow(3, n);
}

// Función para calcular y medir el tiempo de ejecución de T(n)
void calcularT(int limite) {
    for (int i = 0; i <= limite; i++) {
        auto start = high_resolution_clock::now(); // Inicia el cronómetro
        long long resultado = T(i);
        auto stop = high_resolution_clock::now(); // Finaliza el cronómetro
        auto duration = duration_cast<microseconds>(stop - start); // Calcula el tiempo transcurrido

        cout << "T(" << i << ") = " << resultado << " | Tiempo: " << duration.count() << " microsegundos" << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    calcularT(n);
    cout << "La complejidad de T(n) es O(n^3 * 3^n)" << endl;
    system("pause");
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

// Aproximación de Stirling para n!
double stirlingApproximation(int n) {
    return sqrt(2 * M_PI * n) * pow(n / M_E, n);
}

// Función para calcular log(n!) usando la aproximación de Stirling
double logFactorialStirling(int n) {
    return log(stirlingApproximation(n));
}

// Cálculo de log(n!) directamente
long double logFactorial(int n) {
    long double result = 0;
    for (int i = 2; i <= n; i++) {
        result += log(i);
    }
    return result;
}

// Evaluación de la cota inferior con n log(n)
bool verificarCotaInferior(int n) {
    double logFact = logFactorial(n);
    double bound = n * log(n);
    return logFact >= bound / 2; // Verificación con c = 1/2
}

int main() {
    int n;
    cout << "Ingrese un valor de n: ";
    cin >> n;
    
    cout << "\nlog(n!) usando la suma directa: " << logFactorial(n) << endl;
    cout << "log(n!) usando la aproximacion de Stirling: " << logFactorialStirling(n) << endl;
    cout << "Se cumple que log(n!) perteneciente (n log n) " << (verificarCotaInferior(n) ? "Si" : "No") << endl;
    system("pause");
    return 0;
}

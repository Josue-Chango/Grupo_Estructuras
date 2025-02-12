#include <iostream>
#include <cmath>
using namespace std;

// Función para calcular el sumatorio de e^j de j=0 a n-1
double calcularSumatorio(int n) {
    double suma = 0;
    for (int j = 0; j < n; j++) {
        suma += pow(M_E, j);  // M_E es la constante de Euler
    }
    return suma;
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    double sumatorio = calcularSumatorio(n);
    cout << "El valor del sumatorio es: " << sumatorio << endl;

    // Cota inferior: siempre es mayor o igual a 0
    cout << "Cota inferior: 0" << endl;

    // Cota superior usando la fórmula de la suma de la progresión geométrica
    double cotaSuperior = (1 - pow(M_E, n)) / (1 - M_E);
    cout << "Cota superior: " << cotaSuperior << endl;
    system("pause");
    return 0;
}

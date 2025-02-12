#include <iostream>
#include <vector>
#include <cmath>

// Función recursiva para dividir los coeficientes en índices pares e impares
void extraeIndicesParesImpares(const std::vector<int>& coef, std::vector<int>& coef_pares, std::vector<int>& coef_impares) {
    for (size_t i = 0; i < coef.size(); i++) {
        if (i % 2 == 0) {
            coef_pares.push_back(coef[i]);
        } else {
            coef_impares.push_back(coef[i]);
        }
    }
}

// Función recursiva para evaluar el polinomio usando Divide y Vencerás
double evaluaPolinomio(const std::vector<int>& coef, double x) {
    if (coef.size() == 1) {
        return coef[0];
    }

    std::vector<int> coef_pares, coef_impares;
    extraeIndicesParesImpares(coef, coef_pares, coef_impares);

    double x2 = x * x;
    return evaluaPolinomio(coef_pares, x2) + x * evaluaPolinomio(coef_impares, x2);
}

int main() {
    int n;
    std::cout << "Ingrese el grado del polinomio: ";
    std::cin >> n;

    std::vector<int> coef(n + 1);
    std::cout << "Ingrese los coeficientes del polinomio (de mayor a menor grado):\n";
    for (int i = 0; i <= n; i++) {
        std::cout << "Coeficiente de x^" << (n - i) << ": ";
        std::cin >> coef[i];
    }

    double x;
    std::cout << "Ingrese el valor de x para evaluar el polinomio: ";
    std::cin >> x;

    double resultado = evaluaPolinomio(coef, x);
    std::cout << "El resultado del polinomio evaluado en x = " << x << " es: " << resultado << std::endl;

    system("pause");

    return 0;
}

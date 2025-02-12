#include <iostream>
#include <cmath>

int sumaNaturales(int n) {
    return (n * (n + 1)) / 2;
}

int sumaCuadrados(int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

int sumaPotencia4(int n) {
    return (n * (n + 1) * (2 * n + 1) * (3 * n * n + 3 * n - 1)) / 30;
}

int main() {
    int n, j;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;
    std::cout << "Ingrese el valor de j: ";
    std::cin >> j;
    
    int resultado = j - j * j - 2 * sumaNaturales(n) + 6 * sumaCuadrados(n) + n * j * j + 8 * n * j + 3 * sumaPotencia4(n);
    
    std::cout << "El resultado de la expresion simplificada es: " << resultado << std::endl;
    system("pause");
    return 0;
}
#include <iostream>
#include <cmath>

// Función para verificar si log4(n) está en Theta(log2(n))
bool verificarTheta(int n) {
    if (n <= 0) return false; // No se puede calcular logaritmo de valores <= 0
    
    double log4_n = log2(n) / log2(4); // log4(n) = log2(n) / log2(4)
    double log2_n = log2(n);
    
    // Definimos las constantes C1, C2 y n0
    double C1 = 0.25, C2 = 1, n0 = 1;
    
    // Verificamos las desigualdades para todo n >= n0
    bool cumpleOmega = (C1 * log2_n <= log4_n);
    bool cumpleO = (log4_n <= C2 * log2_n);
    
    return cumpleOmega && cumpleO;
}

int main() {
    int n;
    std::cout << "Ingrese un valor de n: ";
    std::cin >> n;
    
    if (verificarTheta(n)) {
        std::cout << "log4(n) pertenece a Theta(log2(n)) para n = " << n << "\n";
    } else {
        std::cout << "log4(n) NO pertenece a Theta(log2(n)) para n = " << n << "\n";
    }
    
    system("pause");
    return 0;
}
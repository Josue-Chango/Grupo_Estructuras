#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

// Función recursiva para calcular A_n (movimientos en AntiClock)
ll calcularA(int n) {
    if (n == 0) return 0;
    return 2 * calcularA(n - 1) + 1;
}

// Función recursiva para calcular C_n (movimientos en Clock)
ll calcularC(int n) {
    if (n == 0) return 0;
    return 2 * calcularA(n - 1) + 1;
}

// Función para calcular el número de movimientos usando la fórmula cerrada de A_n
ll formulaA(int n) {
    return (pow(1 + sqrt(3), n + 2) - pow(1 - sqrt(3), n + 2)) / (4 * sqrt(3)) - 1;
}

// Función para calcular el número de movimientos usando la fórmula cerrada de C_n
ll formulaC(int n) {
    return (pow(1 + sqrt(3), n + 1) - pow(1 - sqrt(3), n + 1)) / (2 * sqrt(3)) - 1;
}

int main() {
    int n;
    cout << "Ingrese el numero de discos: ";
    cin >> n;
    
    cout << "\nCalculo recursivo:" << endl;
    cout << "Movimientos A_n (AntiClock): " << calcularA(n) << endl;
    cout << "Movimientos C_n (Clock): " << calcularC(n) << endl;
    
    cout << "\nCalculo con formula cerrada:" << endl;
    cout << "Movimientos A_n (AntiClock): " << formulaA(n) << endl;
    cout << "Movimientos C_n (Clock): " << formulaC(n) << endl;
    system("pause");
    return 0;
}

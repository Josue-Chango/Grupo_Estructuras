#include <iostream>
#include <cmath>
using namespace std;

// Función recursiva para contar las operaciones según la definición del problema
int contarOperaciones(int n) {
    if (n == 0) return 0;
    return 2 * contarOperaciones(n - 1) + n;
}

// Función para calcular el número de operaciones usando la fórmula cerrada
int formulaOperaciones(int n) {
    return pow(2, n + 1) - 2 - n;
}

// Función para imprimir la representación binaria de un número con n bits
void imprimirBits(int num, int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << ((num >> i) & 1) << " ";
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de bits: ";
    cin >> n;
    
    cout << "\nProcesamiento de bits para numeros de 1 a " << pow(2, n) - 1 << ":\n";
    for (int i = 1; i < pow(2, n); i++) {
        imprimirBits(i, n);
        cout << endl;
    }
    
    cout << "\nNumero total de operaciones (recursivo): " << contarOperaciones(n) << endl;
    cout << "Numero total de operaciones (formula cerrada): " << formulaOperaciones(n) << endl;
    system("pause");
    return 0;
}

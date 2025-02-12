#include <iostream>
#include <cmath>
using namespace std;

// Función recursiva para resolver el problema de las Torres de Hanoi
typedef long long ll;
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n > 0) {
        hanoi(n - 1, origen, auxiliar, destino);
        cout << "Mover disco " << n << " desde " << origen << " a " << destino << endl;
        hanoi(n - 1, auxiliar, destino, origen);
    }
}

// Función para calcular el número de movimientos con la fórmula T(n) = 2^n - 1
ll movimientosHanoi(int n) {
    return pow(2, n) - 1;
}

int main() {
    int n;
    cout << "Ingrese el numero de discos: ";
    cin >> n;
    
    cout << "\nSecuencia de movimientos:" << endl;
    hanoi(n, 'A', 'C', 'B');
    
    cout << "\nNumero total de movimientos: " << movimientosHanoi(n) << endl;
    system("pause");
    return 0;
}

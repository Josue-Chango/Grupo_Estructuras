#include <iostream>
#include <cmath>
using namespace std;


double calcularExpresion(int m, int n) {
    return (pow(m, 3) + pow(m, 2) + pow(n, 2) + 10 * m);  
}


void compararOrden(int m, int n) {
    double valor = calcularExpresion(m, n);
    
    cout << "Valor de la expresion para m = " << m << " y n = " << n << ": " << valor << endl;
    cout << "Expresion simplificada: O(m^3 + n^2)" << endl;
}

int main() {
    int m = 100;  
    int n = 50;   
    
    
    compararOrden(m, n);

    system("pause");
    
    return 0;
}

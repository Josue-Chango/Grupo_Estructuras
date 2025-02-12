#include <iostream>
#include <cmath>
using namespace std;


double calcularExpresion(int m, int n) {
    return (pow(m, 2) * log(n) + m * log(m) + n * log(pow(m, 2)) + m * n);  
}


void compararOrden(int m, int n) {
    double valor = calcularExpresion(m, n);
    
    cout << "Valor de la expresión para m = " << m << " y n = " << n << ": " << valor << endl;
    cout << "Expresión simplificada: O(m^2 + mn)" << endl;
}

int main() {
    int m = 100;  
    int n = 50;   
    
    
    compararOrden(m, n);

    system("pause");
    
    return 0;
}

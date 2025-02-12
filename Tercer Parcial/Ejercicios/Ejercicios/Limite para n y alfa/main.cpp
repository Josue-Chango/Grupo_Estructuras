#include <iostream>
#include <cmath>
using namespace std;


double calcularLimite(int n, double alpha) {
    return (n * log(n)) / pow(n, 1 + alpha);
}

int main() {
    double alpha = 0.5;  
    int max_n = 1000000; 
    double limite;

    
    cout << "Calculando el limite para n y alpha = " << alpha << endl;
    for (int n = 10; n <= max_n; n *= 10) {  
        limite = calcularLimite(n, alpha);
        cout << "n = " << n << ", Limite = " << limite << endl;
    }

    system("pause");

    return 0;
}

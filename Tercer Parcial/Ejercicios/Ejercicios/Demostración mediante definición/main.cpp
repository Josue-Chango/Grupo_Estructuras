#include <iostream>
#include <cmath>
using namespace std;


double calcular_n_e(int n, double e) {
    return pow(n, e);  
}

double calcular_e_n(int n) {
    return exp(n);  
}

int main() {
    double e = 2.718;  
    int n0 = 10;  
    double c = 1.0; 
    double n_max = 50;  

    
    for (int n = n0; n <= n_max; n++) {
        double n_e = calcular_n_e(n, e);  
        double e_n = calcular_e_n(n);  
        
        cout << "n = " << n << ": n^e = " << n_e << ", e^n = " << e_n << endl;

        if (n_e <= c * e_n) {
            cout << "La desigualdad se cumple: " << n_e << " <= " << c * e_n << endl;
        } else {
            cout << "La desigualdad NO se cumple." << endl;
        }
    }

    system("pause");

    return 0;
}

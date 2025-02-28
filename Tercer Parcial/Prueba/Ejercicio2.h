#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <functional>

using namespace std;

class Ejercicio2{
public:
        /*double f(double n) {
            return pow(n, 3) + 6 * pow(n, 2) - 11 * n + 6;
        }


        bool verificaO(double n, double c) {
            double left = f(n);
            double right = c * pow(n, 3);

            cout << "f(n) = " << left << " , c * n^3 = " << right << endl;

            return left <= right;
        }

        void verificarGeneral(double a, double b){
            for (double n = b; n <= 20; n++) {
                cout << "Verificando para n = " << n << endl;
                if (verificaO(n, a)) {
                    cout << "f(n) esta en O(n^3) para n = " << n << endl;
                } else {
                    cout << "f(n) NO esta en O(n^3) para n = " << n << endl;
                }
                cout << endl;
            }
        }*/
        const double E = 2.718281828459045; // Valor de e

        // Función para calcular n^e
        double n_e(double n) {
            return pow(n, E);
        }
        
        // Función para calcular e^n
        double e_n(double n) {
            return pow(E,n);

        }

        // Generar datos en el rango de 0.1 a 10
    /*for (double n = 0.1; n <= 10; n += 0.1) {
        file << n << " " << n_e(n) << " " << e_n(n) << endl;
    }*/
};


/*int main() {
    double c = 2; 
    double n_start = 3; 

    verificarGeneral(c,n_start);
    

    system("pause");

    
    return 0;
}*/
#include <iostream>
#include <cmath>

using namespace std;


double f(double n) {
    return pow(n, 3) + 6 * pow(n, 2) - 11 * n + 6;
}


bool verificaO(double n, double c) {
    double left = f(n);
    double right = c * pow(n, 3);

    cout << "f(n) = " << left << " , c * n^3 = " << right << endl;

    return left <= right;
}

int main() {
    double c = 2; 
    double n_start = 3; 

    for (double n = n_start; n <= 20; n++) {
        cout << "Verificando para n = " << n << endl;
        if (verificaO(n, c)) {
            cout << "f(n) esta en O(n^3) para n = " << n << endl;
        } else {
            cout << "f(n) NO esta en O(n^3) para n = " << n << endl;
        }
        cout << endl;
    }

    system("pause");

    return 0;
}

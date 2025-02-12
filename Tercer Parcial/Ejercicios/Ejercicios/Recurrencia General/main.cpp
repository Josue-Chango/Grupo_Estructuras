#include <iostream>
#include <cmath>  

using namespace std;


double T(int n) {
    
    double C1 = -3.0 / 2;
    double C2 = 3.0 / 2;

    
    return C1 * n + C2 * pow(n, 2);
}

int main() {
    int n;
    
    
    cout << "Ingrese el valor de n: ";
    cin >> n;

    
    double result = T(n);

    
    cout << "El valor de T(" << n << ") es: " << result << endl;

    
    cout << "La complejidad en función de n es O(n^2)" << endl;

    system("pause");

    return 0;
}

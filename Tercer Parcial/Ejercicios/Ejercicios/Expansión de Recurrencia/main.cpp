#include <iostream>
#include <cmath>
using namespace std;


int T(int n) {
    if (n == 1) {
        return 0;  
    }
    int cost = n * n;  
    return cost + 3 * T(n / 3);  
}


void expansion(int n) {
    cout << "Expansion de la recurrencia para n = " << n << ":" << endl;
    while (n > 1) {
        cout << "T(" << n << ") = 3T(" << n / 3 << ") + " << n * n << endl;
        n = n / 3;
    }
    cout << "T(1) = 0 (caso base)" << endl;
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "\nExpansion de la recurrencia:\n";
    expansion(n);

    
    int result = T(n);
    cout << "\nEl valor de T(" << n << ") es: " << result << endl;
    
    
    cout << "La complejidad en funcion de n es O(n^2)" << endl;

    system("pause");

    return 0;
}

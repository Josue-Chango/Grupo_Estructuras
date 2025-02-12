#include <iostream>
using namespace std;


int contarOperaciones(int n) {
    int operaciones = 0;
    
    
    for (int i = 1; i <= n; i++) {
        
        for (int j = 0; j < i; j++) {
            
            operaciones += 2;  
        }
    }
    
    return operaciones;
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    int operacionesTotales = contarOperaciones(n);

    cout << "El numero total de operaciones es: " << operacionesTotales << endl;
    cout << "Complejidad del algoritmo: O(n^2)" << endl;

    system("pause");

    return 0;
}

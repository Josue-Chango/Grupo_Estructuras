#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void generaCombinacionesRepeticion(int i, int j, vector<char>& sol, vector<char>& a, int m) {
    if (i == m) {
        
        for (int k = 0; k < m; k++) {
            cout << sol[k] << " ";
        }
        cout << endl;
        return;
    } else {
        for (int k = j; k < a.size(); k++) {
           
            sol[i] = a[k];
           
            generaCombinacionesRepeticion(i + 1, k, sol, a, m);
        }
    }
}

int main() {
    int m, n;

    cout << "Ingrese el tamaño de las combinaciones (m): ";
    cin >> m;
    cout << "Ingrese el numero de elementos (n): ";
    cin >> n;

    vector<char> a(n);
    cout << "Ingrese los " << n << " elementos:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<char> sol(m);  
    cout << "Combinaciones con repeticion:" << endl;
    generaCombinacionesRepeticion(0, 0, sol, a, m);

    int total_combinaciones = pow(n, m);
    cout << "Numero de combinaciones generadas: " << total_combinaciones << endl;

    system("pause");

    return 0;
}

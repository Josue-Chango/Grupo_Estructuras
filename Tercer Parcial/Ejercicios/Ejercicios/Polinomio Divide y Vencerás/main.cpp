#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función recursiva para evaluar el polinomio
double eval_dyv_alt(const vector<int>& c, double x, int inicio, int fin) {
    int n = fin - inicio + 1;
    if (n == 1) {
        return c[inicio];  
    } else {
        int mitad = (inicio + fin) / 2;
        double val_1 = eval_dyv_alt(c, x, inicio, mitad);  
        double val_2 = eval_dyv_alt(c, x, mitad + 1, fin);  
        return val_2 * pow(x, fin - mitad) + val_1;  
    }
}

int main() {
    int n;

    cout << "Ingrese el numero de coeficientes del polinomio: ";
    cin >> n;

    vector<int> c(n);

    cout << "Ingrese los coeficientes del polinomio (de mayor a menor grado):\n";
    for (int i = 0; i < n; i++) {
        cout << "Coeficiente de x^" << (n - i - 1) << ": ";
        cin >> c[i];
    }

    double x;
    cout << "Ingrese el valor de x para evaluar el polinomio: ";
    cin >> x;

    
    cout << "Resultado de P(x) = " << eval_dyv_alt(c, x, 0, c.size() - 1) << endl;

    
    cout << "Presione Enter para salir...";
    cin.ignore();  
    cin.get();     

    return 0;
}


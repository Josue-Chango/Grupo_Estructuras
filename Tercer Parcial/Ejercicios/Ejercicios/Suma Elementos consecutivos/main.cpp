#include <iostream>
#include <vector>
using namespace std;

vector<int> sumaParesConsecutivos(const vector<int>& a, int inicio, int fin) {
    if (inicio >= fin) {
        return {}; 
    } else {
        vector<int> resultado;

        for (int i = inicio; i < fin; i++) {
            resultado.push_back(a[i] + a[i + 1]);
        }

        return resultado;
    }
}

int main() {
    int n;

    cout << "Ingrese el numero de elementos en la lista: ";
    cin >> n;

    vector<int> a(n);

    cout << "Ingrese los " << n << " elementos de la lista:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> resultado = sumaParesConsecutivos(a, 0, a.size() - 1);
    
    cout << "Resultado (sumas de pares consecutivos): ";
    for (int num : resultado) {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}


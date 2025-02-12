#include <iostream>
#include <string>
using namespace std;

string insertarOrdenado(int a, int x) {
    string str_a = to_string(a);
    string resultado;
    bool insertado = false;
    
    for (char c : str_a) {
        if (!insertado && (x + '0' <= c)) {
            resultado += (x + '0');
            insertado = true;
        }
        resultado += c;
    }
    
    if (!insertado) {
        resultado += (x + '0');
    }
    
    return resultado;
}

int main() {
    int a, x;
    cout << "Ingrese el numero a: ";
    cin >> a;
    cout << "Ingrese el digito x: ";
    cin >> x;
    
    cout << "Numero resultante: " << insertarOrdenado(a, x) << endl;
    
    system("pause");
    return 0;
}

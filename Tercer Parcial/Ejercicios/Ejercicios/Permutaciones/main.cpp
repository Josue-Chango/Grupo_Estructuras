#include <iostream>
#include <vector>
#include <map>
using namespace std;


int generaPermutacionesRepeticion(int i, vector<char>& sol, map<char, int>& r, vector<char>& a) {
    int n = sol.size();
    if (i == n) {
        
        for (char c : sol) {
            cout << c << " ";
        }
        cout << endl;
        return 1;
    }

    int s = 0; 
    for (auto& it : r) {
        if (it.second > 0) {
            sol[i] = it.first;
            it.second--; 
            s += generaPermutacionesRepeticion(i + 1, sol, r, a);
            it.second++; 
        }
    }
    return s;
}


void generaPermutacionesRepeticionWrapper(map<char, int>& frecuencia) {
    vector<char> a;
    int total = 0;

    for (auto& it : frecuencia) {
        a.push_back(it.first);
        total += it.second;
    }

    vector<char> sol(total); 
    int num_permutaciones = generaPermutacionesRepeticion(0, sol, frecuencia, a);

    cout << "Permutaciones con repeticion halladas = " << num_permutaciones << endl;

    
    int factorial_total = 1, factorial_rep = 1;
    for (int i = 1; i <= total; i++) factorial_total *= i;
    for (auto& it : frecuencia) {
        for (int i = 1; i <= it.second; i++) factorial_rep *= i;
    }

    cout << "Permutaciones con repeticion correctas = " << (factorial_total / factorial_rep) << endl;
}

int main() {
    map<char, int> frecuencia;
    char letra;
    int repeticiones;
    int num_elementos;

    cout << "Ingrese la cantidad total de elementos: ";
    cin >> num_elementos;

    for (int i = 0; i < num_elementos; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> letra;
        cout << "Ingrese el numero de repeticiones de " << letra << ": ";
        cin >> repeticiones;
        frecuencia[letra] = repeticiones;
    }

    generaPermutacionesRepeticionWrapper(frecuencia);
    system("pause");
    return 0;
}

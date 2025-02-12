#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Actividad {
    int indice;
    int inicio;
    int fin;
};

vector<Actividad> mejorConjunto;

bool esValido(vector<Actividad>& solucion, Actividad nueva) {
    for (const auto& act : solucion) {
        if (!(nueva.inicio >= act.fin || nueva.fin <= act.inicio)) {
            return false;
        }
    }
    return true;
}

void backtracking(vector<Actividad>& actividades, vector<Actividad>& solucion, int indice) {
    if (solucion.size() > mejorConjunto.size()) {
        mejorConjunto = solucion;
    }
    
    if (indice >= actividades.size()) return;
    
    for (int i = indice; i < actividades.size(); i++) {
        if (esValido(solucion, actividades[i])) {
            solucion.push_back(actividades[i]);
            backtracking(actividades, solucion, i + 1);
            solucion.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de actividades: ";
    cin >> n;
    
    vector<Actividad> actividades(n);
    cout << "Ingrese los tiempos de inicio y fin de cada actividad: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> actividades[i].inicio >> actividades[i].fin;
        actividades[i].indice = i;
    }
    
    vector<Actividad> solucion;
    backtracking(actividades, solucion, 0);
    
    cout << "Conjunto optimo de actividades: ";
    for (const auto& act : mejorConjunto) {
        cout << "a" << act.indice << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}

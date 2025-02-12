#include <iostream>
#include <vector>
#include <map>
using namespace std;


void elementosYApariciones(const vector<char>& a, map<char, int>& apariciones, int index = 0) {
    if (index == a.size()) {
        return; 
    }
    
    if (apariciones.find(a[index]) != apariciones.end()) {
        apariciones[a[index]]++;
    } else {
        
        apariciones[a[index]] = 1;
    }

    
    elementosYApariciones(a, apariciones, index + 1);
}

int main() {
    vector<char> a;
    map<char, int> apariciones;

    cout << "Ingrese los elementos de la lista (ingrese X para terminar): " << endl;
    char elem;
    while (true) {
        cin >> elem;
        if (elem == 'X' || elem == 'x') {
            break;  
        }
        a.push_back(elem);  
    }

    
    elementosYApariciones(a, apariciones);
    
    
    cout << "Elemento - Número de apariciones:" << endl;
    for (const auto& elem : apariciones) {
        cout << elem.first << " aparece " << elem.second << " veces" << endl;
    }

    return 0;
}



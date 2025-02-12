#include <iostream>
#include <vector>
using namespace std;


vector<int> mezcla(const vector<int>& a1, const vector<int>& a2) {
    vector<int> result;
    result.push_back(a1[0]);
    result.push_back(a2[0]);
    
    
    result.insert(result.end(), a1.begin() + 1, a1.end());
    result.insert(result.end(), a2.begin() + 1, a2.end());
    
    return result;
}


vector<int> invertperm(const vector<int>& a) {
    if (a.size() <= 1) {
        return a;
    } else {
        int mitad = a.size() / 2;
        
        
        vector<int> a1 = invertperm(vector<int>(a.begin(), a.begin() + mitad));
        vector<int> a2 = invertperm(vector<int>(a.begin() + mitad, a.end()));
        
        
        return mezcla(a1, a2);
    }
}

int main() {
    vector<int> lista = {3, 5, 7, 2, 4, 8, 1, 6}; 
    vector<int> lista_permutada = invertperm(lista);
    
    
    cout << "Lista permutada: ";
    for (int val : lista_permutada) {
        cout << val << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}


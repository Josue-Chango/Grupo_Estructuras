#include <iostream>
#include <vector>

using namespace std;


vector<int> particiona(const vector<int>& a, int start, int end) {
    if (start >= end) {
        return {};  
    } else {
        vector<int> result;
        
        for (int i = start; i < end; i++) {
            if (i % 2 == 0) {
                result.push_back(a[i]);  
            }
        }
        return result;
    }
}

int main() {
    vector<int> a = {3, 8, 1, 5, 7, 2, 4, 6}; 
    
    
    vector<int> resultado = particiona(a, 0, a.size());  
    
    
    cout << "La lista con elementos de índices pares es: ";
    for (int val : resultado) {
        cout << val << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}




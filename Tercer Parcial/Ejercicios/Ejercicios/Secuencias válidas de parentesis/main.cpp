#include <iostream>
#include <vector>

using namespace std;


void parentesis(int i, int n_abiertos, int n_cerrados, string sol, int n) {
    if (i == 2 * n) {  
        cout << sol << endl;  
        return;
    } else {
        
        for (int k = 0; k < 2; k++) {
            if (k == 0) {  
                if (n_abiertos < n) {
                    
                    sol += '(';
                    parentesis(i + 1, n_abiertos + 1, n_cerrados, sol, n);  
                    sol.pop_back();  
                }
            } else {  
                if (n_cerrados < n_abiertos) {
                    
                    sol += ')';
                    parentesis(i + 1, n_abiertos, n_cerrados + 1, sol, n);  
                    sol.pop_back();  
                }
            }
        }
    }
}


void parentesis_wrapper(int n) {
    string sol = "";  
    parentesis(0, 0, 0, sol, n);  
}

int main() {
    int n = 3;  
    cout << "Secuencias válidas de paréntesis con " << n << " pares:" << endl;
    parentesis_wrapper(n);  

    system("pause");
    return 0;
}


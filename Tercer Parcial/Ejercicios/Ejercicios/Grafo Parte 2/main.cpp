#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;


bool condicion_consecutivos(int k, int sol[], const vector<vector<int>>& A) {
    for (int j = 0; j < k; j++) {
        if (A[k][j] == 1 && abs(sol[k] - sol[j]) == 1) {
            return false;  
        }
    }
    return true;
}


int genera_etiquetas(int i, int coste, vector<bool>& libres, vector<int>& sol, int& opt_val, vector<int>& opt_sol, const vector<vector<int>>& A) {
    int n = sol.size();

    
    if (i == n) {
        if (coste < opt_val) {
            opt_val = coste;
            opt_sol = sol;  
        }
        return coste;
    }

    int cost_ext = INT_MAX;

    
    for (int k = 0; k < n; k++) {
        if (libres[k] && condicion_consecutivos(i, sol.data(), A)) {
            sol[i] = k;
            libres[k] = false;  

            
            int extra = 0;
            for (int j = 0; j < i; j++) {
                if (A[i][j] == 1) {
                    extra += abs(sol[i] - sol[j]);  
                }
            }

            
            cost_ext = genera_etiquetas(i + 1, coste + extra, libres, sol, opt_val, opt_sol, A);

            libres[k] = true;  
        }
    }
    return cost_ext;
}


int genera_etiquetas_wrapper(const vector<vector<int>>& A) {
    int n = A.size();
    vector<int> sol(n, -1);  
    vector<bool> libres(n, true);  
    int opt_val = INT_MAX;
    vector<int> opt_sol(n);

    
    genera_etiquetas(0, 0, libres, sol, opt_val, opt_sol, A);

   
    cout << "Etiquetas optimas: ";
    for (int i = 0; i < n; i++) {
        cout << opt_sol[i] << " ";
    }
    cout << endl;

    cout << "Suma de pesos asociados a las aristas: ";
    int suma_pesos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i][j] == 1) {
                suma_pesos += abs(opt_sol[i] - opt_sol[j]);  
            }
        }
    }
    cout << suma_pesos << endl;

    return opt_val;
}

int main() {
    int n = 6;  
    vector<vector<int>> A = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0}
    };

    genera_etiquetas_wrapper(A);

    
    cout << "Presiona Enter para salir...";
    cin.ignore();  
    cin.get();     

    return 0;
}


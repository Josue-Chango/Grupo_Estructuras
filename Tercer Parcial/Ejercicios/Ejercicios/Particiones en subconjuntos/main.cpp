#include <iostream>
#include <vector>
using namespace std;


int particiones(int i, vector<int>& a, vector<vector<int>>& sol, vector<int>& n) {
    int nsols = 0;  
    if (i == a.size()) {
        
        return 1;
    } else {
        for (int k = 0; k < n.size(); k++) {
            if (sol[k].size() < n[k]) {  
                sol[k].push_back(a[i]);  
                nsols += particiones(i + 1, a, sol, n);  
                sol[k].pop_back();  
            }
        }
    }
    return nsols;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};  
    vector<int> n = {2, 2, 2};  
    vector<vector<int>> sol(n.size());  

   
    int resultado = particiones(0, a, sol, n);
    cout << "Número de particiones: " << resultado << endl;

    system("pause");

    return 0;
}

// Problema de la Suma de Subconjuntos
#include <iostream>
#include <vector>
using namespace std;

void encontrarSubconjuntos(vector<int> &set, vector<int> &subset, int sum, int index, int target) {
    if (sum == target) {
        cout << "Subconjunto encontrado: ";
        for (int num : subset) cout << num << " ";
        cout << endl;
        return;
    }
    if (index == set.size() || sum > target) return;
    
    subset.push_back(set[index]);
    encontrarSubconjuntos(set, subset, sum + set[index], index + 1, target);
    subset.pop_back();
    encontrarSubconjuntos(set, subset, sum, index + 1, target);
}

int main() {
    vector<int> set = {5, 10, 12, 13, 15, 18};
    int target = 30;
    vector<int> subset;
    encontrarSubconjuntos(set, subset, 0, 0, target);
    return 0;
}
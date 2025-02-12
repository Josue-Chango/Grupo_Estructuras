#include <iostream>
#include <vector>
using namespace std;


int suma_resta_alternante1(const vector<int>& a) {
    if (a.size() == 0) {
        return 0;
    } else {
        return a[0] - suma_resta_alternante1(vector<int>(a.begin() + 1, a.end()));
    }
}

int main() {
    vector<int> a = {5, 3, 8, 2, 6}; 

    int resultado = suma_resta_alternante1(a);
    cout << "Suma/resta alternante: " << resultado << endl;

    system("pause");

    return 0;
}

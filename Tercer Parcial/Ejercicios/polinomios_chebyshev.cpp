// polinomios_chebyshev.cpp
#include <iostream>
#include <cmath>
using namespace std;

double T(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    return 2 * x * T(x, n - 1) - T(x, n - 2);
}

int main() {
    cout << "T(0.5, 3) = " << T(0.5, 3) << endl;
    system("pause");
    return 0;
}
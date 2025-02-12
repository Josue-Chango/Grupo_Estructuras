// integral_combinada.cpp
#include <iostream>
#include <cmath>
using namespace std;

double integral(double (*f)(double), double a, double b, int n) {
    double s = 0, x = a, ancho = (b - a) / n;
    for (int i = 1; i <= n; ++i) {
        s += f(x);
        x += ancho;
    }
    return s * ancho;
}

double ejemploFuncion(double x) { return x * x; }

int main() {
    cout << "Integral de x^2 en [0,1]: " << integral(ejemploFuncion, 0, 1, 100) << endl;
    system("pause");
    return 0;
}
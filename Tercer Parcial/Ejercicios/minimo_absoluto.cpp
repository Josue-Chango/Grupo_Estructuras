// minimo_absoluto.cpp
#include <iostream>
#include <cmath>
using namespace std;

double minx(double a, double b, double eps, double (*f)(double)) {
    double p = (a + b) / 2;
    if (b - a < eps) return p;
    double y1 = f(p - eps), y2 = f(p + eps);
    return (y1 > y2) ? minx(p, b, eps, f) : minx(a, p, eps, f);
}

double ejemploFuncion(double x) { return x * x - 4 * x + 4; }

int main() {
    cout << "Mínimo de x^2 - 4x + 4 en [0,4]: " << minx(0, 4, 0.001, ejemploFuncion) << endl;
    system("pause");
    return 0;
}
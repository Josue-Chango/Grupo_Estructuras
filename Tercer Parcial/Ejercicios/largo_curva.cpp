// largo_curva.cpp
#include <iostream>
#include <cmath>
using namespace std;

double largo(double (*f)(double), double a, double b, int n) {
    double ancho = (b - a) / (n - 1), suma = 0, x = a, yant = f(a);
    for (int i = 1; i < n; ++i) {
        x += ancho;
        double y = f(x);
        double dif = y - yant;
        suma += sqrt(ancho * ancho + dif * dif);
        yant = y;
    }
    return suma;
}

double ejemploFuncion(double x) { return sin(x); }

int main() {
    cout << "Largo de sin(x) en [0, pi]: " << largo(ejemploFuncion, 0, M_PI, 100) << endl;
    system("pause");
    return 0;
}
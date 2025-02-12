#include <iostream>
#include <cmath>

using namespace std;


double modulo(double x, double y) {
    return sqrt(x * x + y * y);
}


double biseccion_listas(double x1, double y1, double x2, double y2, double r, double epsilon) {
    
    double xm = (x1 + x2) / 2;
    double ym = (y1 + y2) / 2;

    
    if (modulo(xm, ym) <= r + epsilon) {
        return xm;  // Encontró el punto de intersección
    }

    
    if (modulo(xm, ym) < r) {
        return biseccion_listas(xm, ym, x2, y2, r, epsilon);  
    } else {
        return biseccion_listas(x1, y1, xm, ym, r, epsilon);  
    }
}

int main() {
    double r, qx, qy, epsilon;

    
    cout << "Ingrese el radio de la circunferencia: ";
    cin >> r;
    cout << "Ingrese las coordenadas de q (qx, qy): ";
    cin >> qx >> qy;
    cout << "Ingrese el valor de epsilon (precision): ";
    cin >> epsilon;

    
    double sx = biseccion_listas(0, 0, qx, qy, r, epsilon);

    cout << "El punto de interseccion s tiene la coordenada x: " << sx << endl;
    system("pause");    
    return 0;
}

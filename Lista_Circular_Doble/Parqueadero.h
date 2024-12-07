#pragma once
#include <iostream>

class Parqueadero {
private:
    bool* espacios;  // Array dinámico para los espacios (true=ocupado, false=libre)
    int totalEspacios;  // Número total de espacios en el parqueadero
    int radio;          // Radio del círculo para la impresión

public:
    Parqueadero(int totalEspacios, int radio);
    ~Parqueadero();
    void ocuparEspacio(int espacio);
    void liberarEspacio(int espacio);
    void mostrarParqueaderoCircular();
    int getTotalEspacios();
    void expandirEspacios(int nuevosEspacios);  // Método para aumentar los espacios
};
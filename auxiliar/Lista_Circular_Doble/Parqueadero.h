#pragma once
#include "Lista_Circular_Doble.h"
#include <vector>
#include <iostream>
#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>

class Parqueadero {
private:
    int filas;
    int columnas;
    std::vector<std::vector<char>> espacios; 
    Lista_Circular_Doble<std::string> listaVehiculos; 

public:
    Parqueadero(int , int );
    void mostrarParqueadero(); 
    bool ingresarVehiculo(const std::string& , const std::string& , const std::string& , const std::string& , const std::string& , const std::string& );
    bool retirarVehiculo(const std::string& );
    void expandirParqueadero(int , int );
};
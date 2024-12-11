#pragma once
#include "Lista_Circular_Doble.h"
#include <vector>
#include <iostream>


class Parqueadero {
private:
    int filas;
    int columnas;
    std::vector<std::vector<char>> espacios; 
    Lista_Circular_Doble<std::string> listaVehiculos; 

public:
    Parqueadero(int filas, int columnas);
    void mostrarParqueadero(); 
    void ingresarVehiculo(const std::string& placa, const std::string& nombre1, const std::string& nombre2, const std::string& apellido, const std::string& cedula, const std::string& correo);
    bool retirarVehiculo(const std::string& placa);
    void expandirParqueadero(int nuevasFilas, int nuevasColumnas);
    bool buscarVehiculo(const std::string& placa);
    void guardarVehiculoEnArchivo(int fila, int columna, const std::string& placa, const std::string& nombre1, const std::string& nombre2, const std::string& apellido, const std::string& cedula, const std::string& correo);
    void cargarVehiculosDesdeArchivo();
    
};

#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "Lista.h"
#include <sstream>
#include "ListaPropietarios.h"
#include "Propietario.h"
#include <graphics.h>


using namespace std;

class Coche
{
private:
    string placa;
    string color;
    string modelo;
    string marca;
    chrono::system_clock::time_point horaIngreso;
    chrono::system_clock::time_point horaSalida;
    int anio;
    int posicion;
    Propietario propietario;

public:
void generarCodigoQR(const string& datos);
void mostrar_auto_imagen(const std::string& nombreArchivo, const std::string& modelo);
    Coche();
    Coche(string placa, string modelo, string color, string marca, int anio, Propietario propietario);
    Coche(string placa, string modelo, string color, string marca, int anio, Propietario propietario, int posicion);
    Coche(string placa, string modelo, string color, string marca,
      chrono::system_clock::time_point horaIngreso, chrono::system_clock::time_point horaSalida, Propietario propietario);

    void setHoraSalida(chrono::system_clock::time_point hora);
    void setPlaca(const string &placa);
    void setModelo(const string &modelo);
    void setMarca(const string &marca);
    void setColor(const string &color);
    Propietario getPropietario() const;

    chrono::system_clock::time_point getHoraSalida() const;
    string getPlaca() const;
    string getMarca() const;
    string getModelo() const;
    string getColor() const;
    int getAnio() const;
    int getPosicion() const;
    chrono::system_clock::time_point getHora() const;

    Coche InsertarDatos(ListaCircularDoble<Coche> &lista, ListaCircularDoble<Coche> &listaHistorial, ListaPropietarios &listaPropietarios);

    friend ostream &operator<<(ostream &os, const Coche &coche);
};

#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "Lista.h"
#include <sstream>

class Propietario;

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

public:
    Coche();
    Coche(string placa, string modelo, string color, string marca, int anio);
    Coche(string placa, string modelo, string color, string marca,
      chrono::system_clock::time_point horaIngreso, chrono::system_clock::time_point horaSalida);

    void setHoraSalida(chrono::system_clock::time_point hora);
    void setPlaca(const string &placa);
    void setModelo(const string &modelo);
    void setMarca(const string &marca);
    void setColor(const string &color);
  
    chrono::system_clock::time_point getHoraSalida() const;
    string getPlaca() const;
    string getMarca() const;
    string getModelo() const;
    string getColor() const;
    int getAnio() const;
    chrono::system_clock::time_point getHora() const;

    Coche InsertarDatos(ListaCircularDoble<Coche> &lista, ListaCircularDoble<Coche> &listaHistorial, ListaCircularDoble<Propietario> &listaPropietarios);
    friend ostream &operator<<(ostream &os, const Coche &coche);
};

/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          18/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#pragma once
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
class Persona {
private:
    T nombre1, nombre2, apellido, cedula, correo;
public:

    //setters y getters
    void setNombre1(T);
    T getNombre1();
    void setNombre2(T);
    T getNombre2();
    void setApellido(T);
    T getApellido();
    void setCedula(T);
    T getCedula();
    void setCorrero(T);
    string getCorreo();

    Persona();
    Persona(T, T, T, T, T);
    void eliminarLetra(char);

};


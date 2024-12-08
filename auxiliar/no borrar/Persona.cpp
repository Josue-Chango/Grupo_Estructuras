/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          18/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Persona.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;


template <typename T>
void Persona<T>::setNombre1(T _nombre1)
{
    nombre1 = _nombre1;
};

template <typename T>
T Persona<T>::getNombre1()
{
    return nombre1;
}

template <typename T>
void Persona<T>::setNombre2(T _nombre2)
{
    nombre2 = _nombre2;
};

template <typename T>
T Persona<T>::getNombre2()
{
    return nombre2;
}

template <typename T>
void Persona<T>::setApellido(T _apellido)
{
    apellido = _apellido;
}

template <typename T>
T Persona<T>::getApellido()
{
    return apellido;
}

template <typename T>
void Persona<T>::setCorrero(T _correo)
{
    correo = _correo;
}

template <typename T>
string Persona<T>::getCorreo()
{
    return correo;
}

template <typename T>
void Persona<T>::setCedula(T _cedula)
{
    cedula = _cedula;
};

template <typename T>
T Persona<T>::getCedula()
{
    return cedula;
}

/////////////////////////////////////////////////////

template <typename T>
Persona<T>::Persona()
{

}

template <typename T>
Persona<T>::Persona(T _nombre1, T _nombre2, T _apellido, T _cedula, T _correo)
{
    nombre1 = _nombre1;
    nombre2 = _nombre2;
    apellido = _apellido;
    cedula = _cedula;
    correo =_correo;
}


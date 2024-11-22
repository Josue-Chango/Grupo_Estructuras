/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

template<typename T>
class Nodo_Doble {
private:
    T dato;
    std::string nombre1;
    std::string nombre2 ;
    std::string apellido;
    std::string correo;
    Nodo_Doble* siguiente;
    Nodo_Doble* anterior;
public:
    Nodo_Doble(T);
    Nodo_Doble(T,T,T,T);
    void setDato(T);
    T getDato();
    void setSiguiente(Nodo_Doble*);
    void setAnterior(Nodo_Doble*);
    Nodo_Doble* getSiguiente();
    Nodo_Doble* getAnterior();

    void setNombre1(string);
    string getNombre1();
    void setNombre2(string);
    string getNombre2();
    void setApellido(string);
    string getApellido();
    void setCorreo(string);
    string getCorreo();

    friend class Lista_Doble;

    

};


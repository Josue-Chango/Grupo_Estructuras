/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/
#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "NodoHash.cpp"
#define NCASILLAS 29
#include "ModoGrafico.cpp"
 #define DELAYINSERTAR 500
#define DELAYBORRAR 500
#define DELAYBUSCAR 500

class TablaCerradaEnteros{
    private:
        NodoHash **tabla;
       
    public:
        TablaCerradaEnteros();
        ~TablaCerradaEnteros();
        //Metodos insertar
        void insertarSondeoLineal(int valor);
        void insertarSondeoCuadratico(int valor);
        void insertarSondeoDoble(int valor);
		//Metodos eliminar
        void eliminarSondeoLineal(int valor);
        void eliminarSondeoCuadratico(int valor);
        void eliminarSondeoDoble(int valor);
        void imprimir();
        void buscar(int valor);
        void buscarCuadratico(int valor);
        void buscarDoble(int valor);
        int hash(int valor);
        int hash2(int valor);
        void vaciarTabla();
        
};

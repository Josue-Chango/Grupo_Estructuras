/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/
#include <cstdlib>
#pragma once
using namespace std;

class NodoHash{
    private:
        int valor;
        NodoHash *sig;
    public:
        NodoHash(int valor);
        ~NodoHash();
        int getValor();
        NodoHash *getSig();
        void setSig(NodoHash *sig);
};
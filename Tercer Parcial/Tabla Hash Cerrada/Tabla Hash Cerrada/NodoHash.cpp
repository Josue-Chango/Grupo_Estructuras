/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "NodoHash.h"
#pragma once

/**
 * NodoHash:: NodoHash(int valor){
 *     this->valor = valor;
 *     sig = NULL;
 * }
 * 
 * @param valor el valor del nodo
 */
NodoHash:: NodoHash(int valor){
    this->valor = valor;
    sig = NULL;
}

/**
 * El destructor de la clase NodoHash
 */
NodoHash:: ~NodoHash(){
    delete sig;
}

/**
 * Devuelve el valor del nodo.
 * 
 * @return El valor del nodo.
 */
int NodoHash :: getValor(){
    return valor;
}

/**
 * *|CURSOR_MARCADOR|*
 * 
 * @return El siguiente nodo en la tabla hash.
 */
NodoHash *NodoHash :: getSig(){
    return sig;
}

/**
 * vacío NodoHash :: setSig(NodoHash *sig){
 *     esto->decir = decir;
 * }
 * 
 * @param sig es un puntero al siguiente nodo en la lista
 */
void NodoHash :: setSig(NodoHash  *sig){
    this->sig = sig;
}

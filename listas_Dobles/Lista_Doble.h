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
#include "Nodo_Doble.h"
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
class Lista_Doble {
private:
    Nodo_Doble<T>* primero;
    Nodo_Doble<T>* ultimo;
public:
    Lista_Doble();
    Lista_Doble(T,T,T,T);
    void Insertar(T);
    void Buscar(T);
    void Eliminar(T);
    void Mostrar();

    //para personas
    void insertar_persona(T, T, T ,T );
    T generar_correo(T, T, T);
    void guardarEnArchivo(const std::string&);
    void cargarDesdeArchivo(const std::string&);
    void eliminarLetra(char);
    void mostrar_persona();
};


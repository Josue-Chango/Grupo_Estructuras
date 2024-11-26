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
#include "Nodo_Circular.h"
#include "Validaciones.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template<typename T>
class Lista_Circular {
private:
    Nodo_Circular<T>* primero;
    Nodo_Circular<T>* ultimo;
public:
    Lista_Circular();
    void Insertar(T);
    void Buscar(T);
    void Eliminar(T);
    void Mostrar();

    //Funciones propias
    void insertar_persona(T, T, T, T, T);
    void mostrar_persona();
    T generar_correo(T, T, T);
    void guardarEnArchivo(const std::string&);
    void cargarDesdeArchivo(const std::string&);
    void eliminarLetra(char);
    void cifrar_cesar(int);
    void descifrar_cesar(int);
    string validar_cedula_existente();

};




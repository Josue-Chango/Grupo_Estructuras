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
#include "Validaciones.h"
#include "Nodo.h"
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
class Lista_Simple {
private:
    Nodo<T>* cabeza;
public:
    Lista_Simple();
    Lista_Simple(T, T, T);
    void insertar_persona(T, T, T, T, T);
    void Insertar_cabeza(T);
    //void Insertar_cola(T);
    void Buscar(T);
    void Eliminar(T);
    void Mostrar();
    void mostrar_persona();

    //funcion correo
    T generar_correo(T, T, T);

    //para txt
    void guardarEnArchivo(const std::string&);
    void cargarDesdeArchivo(const std::string&);

    void eliminarLetra(char);

    void cifrar_cesar(int);
    void descifrar_cesar(int);
    T validar_cedula_existente();
};


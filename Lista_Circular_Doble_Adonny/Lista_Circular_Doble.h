#pragma once
#include "Nodo_Circular_Doble.h"
#include "Validaciones.h"
#include <string>
#include <iostream>

template<typename T>
class Lista_Circular_Doble {
private:
    Nodo_Circular_Doble<T>* cabeza;
    Nodo_Circular_Doble<T>* cola;

public:
    Lista_Circular_Doble();
    ~Lista_Circular_Doble();

	void insertar_persona(T, T, T, T, T);

    void insertar(T);
    void eliminar(T);
    void mostrar();
    bool buscar(int);
	void Buscar(T);

	//funcion correo
    T generar_correo(T, T, T);

	//para txt
    void guardarEnArchivo(const std::string&);
    void cargarDesdeArchivo(const std::string&);


    // Nuevos métodos
    void eliminarLetra(char);
    void cifrar_cesar(int);
    void descifrar_cesar(int);
    T validar_cedula_existente();
};




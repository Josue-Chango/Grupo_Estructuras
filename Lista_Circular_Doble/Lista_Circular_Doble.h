#pragma once
#include "Nodo_Circular_Doble.h"
#include <fstream>
#include <sstream>
#include <string>

template<typename T>
class Lista_Circular_Doble
{
private:
	Nodo_Circular_Doble<T>* cabeza;
	Nodo_Circular_Doble<T>* cola;
public:
	Lista_Circular_Doble();
	//~Lista_Circular_Doble();
	void insertar(T);
	void eliminar(T);
	void mostrar();
	bool buscar(T);

	//Funciones propias
    void insertar_persona(T, T, T, T, T, T);
    void mostrar_persona();
    T generar_correo(T, T, T);
    void guardarEnArchivo(const std::string&);
    void cargarDesdeArchivo(const std::string&);
    void eliminarLetra(char);
    void cifrar_cesar(int);
    void descifrar_cesar(int);
    std::string validar_cedula_existente();
    std::string validar_placa_existente();
    bool buscar_Placa(std::string _placa);

};



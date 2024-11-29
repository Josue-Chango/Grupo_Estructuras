#pragma once
#include "Nodo_Circular_Doble.h"

template<typename T>
class Lista_Circular_Doble
{
private:
	Nodo_Circular_Doble<T>* cabeza;
	Nodo_Circular_Doble<T>* cola;
public:
	Lista_Circular_Doble();
	~Lista_Circular_Doble();
	void insertar(T);
	void eliminar(T);
	void mostrar();
	bool buscar(T);
};



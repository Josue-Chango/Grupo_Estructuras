#pragma once

template<typename T>
class Nodo_Circular_Doble
{
private:
	T dato;
	Nodo_Circular_Doble* siguiente;
	Nodo_Circular_Doble* anterior;
public:
	Nodo_Circular_Doble(T);
	~Nodo_Circular_Doble();
	void setDato(T);
	T getDato();
	void setSiguiente(Nodo_Circular_Doble*);
	Nodo_Circular_Doble* getSiguiente();
	void setAnterior(Nodo_Circular_Doble*);
	Nodo_Circular_Doble* getAnterior();
};



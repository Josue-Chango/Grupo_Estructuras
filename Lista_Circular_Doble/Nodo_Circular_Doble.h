#pragma once
#include <string>
template<typename T>
class Nodo_Circular_Doble
{
private:
	T dato, nombre1, nombre2, apellido, cedula, correo;
	T placa, hora;
	Nodo_Circular_Doble* siguiente;
	Nodo_Circular_Doble* anterior;
public:
	Nodo_Circular_Doble(T);
	Nodo_Circular_Doble(T,T,T,T,T,T);
	Nodo_Circular_Doble(T,T,T,T,T,T,T);
	~Nodo_Circular_Doble();
	void setDato(T);
	T getDato();
	void setSiguiente(Nodo_Circular_Doble*);
	Nodo_Circular_Doble* getSiguiente();
	void setAnterior(Nodo_Circular_Doble*);
	Nodo_Circular_Doble* getAnterior();

	//Funcionesnpropias
	void setNombre1(T);
	T getNombre1();
	void setNombre2(T);
	T getNombre2();
	void setApellido(T);
	T getApellido();
	void setCedula(T);
	T getCedula();
	void setCorreo(T);
	T getCorreo();
	void setPlaca(T);
	T getPlaca();
	void setHora(T);
	T getHora();
};



#pragma once
template<typename T>
class Nodo_Circular_Doble
{
private:
	T dato;
    T nombre1;
    T nombre2;
    T apellido;
    T cedula;
	Nodo_Circular_Doble* siguiente;
	Nodo_Circular_Doble* anterior;
	T correo;
public:
	Nodo_Circular_Doble(T);
	Nodo_Circular_Doble(T, T, T, T, T);
	~Nodo_Circular_Doble();
	void setDato(T);
	T getDato();
	void setSiguiente(Nodo_Circular_Doble*);
	Nodo_Circular_Doble* getSiguiente();
	void setAnterior(Nodo_Circular_Doble*);
	Nodo_Circular_Doble* getAnterior();
	 void setNombre1(T);
    T getNombre1();
    void setNombre2(T);
    T getNombre2();
    void setApellido(T);
    T getApellido();
    void setCorrero(T);
    T getCorreo();
    void setCedula(T);
    T getCedula();
};



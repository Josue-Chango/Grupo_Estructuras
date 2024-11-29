#pragma once
template<typename T>
class NodoDoble
{
private:
	T dato;
    T nombre1;
    T nombre2;
    T apellido;
    T cedula;
	NodoDoble* siguiente;
	NodoDoble* anterior;
	T correo;
public:
	NodoDoble(T);
	NodoDoble(T, T, T, T, T);
	~NodoDoble();
	void setDato(T);
	T getDato();
	void setSiguiente(NodoDoble*);
	NodoDoble* getSiguiente();
	void setAnterior(NodoDoble*);
	NodoDoble* getAnterior();
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



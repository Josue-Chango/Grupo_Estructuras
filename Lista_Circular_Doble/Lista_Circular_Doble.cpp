#include "Lista_Circular_Doble.h"
#include <iostream>
using namespace std;

template<typename T>
Lista_Circular_Doble<T>::Lista_Circular_Doble()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}

template<typename T>
Lista_Circular_Doble<T>::~Lista_Circular_Doble()
{
}

template<typename T>
void Lista_Circular_Doble<T>::insertar(T dato)
{
	Nodo_Circular_Doble<T>* nuevo = new Nodo_Circular_Doble(dato);
	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevo;
		this->cola = nuevo;
		this->cabeza->setSiguiente(this->cola);
		this->cabeza->setAnterior(this->cola);
		this->cola->setSiguiente(this->cabeza);
		this->cola->setAnterior(this->cabeza);
	}
	else
	{
		this->cola->setSiguiente(nuevo);
		nuevo->setAnterior(this->cola);
		nuevo->setSiguiente(this->cabeza);
		this->cabeza->setAnterior(nuevo);
		this->cola = nuevo;
	}
}

template<typename T>
void Lista_Circular_Doble<T>::eliminar(T dato)
{
	if (this->cabeza != nullptr)
	{
		if (this->cabeza->getDato() == dato)
		{
			Nodo_Circular_Doble<T>* aux = this->cabeza;
			this->cabeza = this->cabeza->getSiguiente();
			this->cabeza->setAnterior(this->cola);
			this->cola->setSiguiente(this->cabeza);
			delete aux;
		}
		else
		{
			Nodo_Circular_Doble<T>* aux = this->cabeza;
			while (aux->getSiguiente() != this->cabeza)
			{
				if (aux->getSiguiente()->getDato() == dato)
				{
					Nodo_Circular_Doble<T>* aux2 = aux->getSiguiente();
					aux->setSiguiente(aux2->getSiguiente());
					aux2->getSiguiente()->setAnterior(aux);
					delete aux2;
					break;
				}
				aux = aux->getSiguiente();
			}
		}
	}
}

template<typename T>
void Lista_Circular_Doble<T>::mostrar()
{
	if (this->cabeza != nullptr)
	{
		Nodo_Circular_Doble<T>* aux = this->cabeza;
		do
		{
			cout << aux->getDato() << " ";
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		cout << endl;
	}
}

template<typename T>
bool Lista_Circular_Doble<T>::buscar(T dato)
{
	if (this->cabeza != nullptr)
	{
		Nodo_Circular_Doble<T>* aux = this->cabeza;
		do
		{
			if (aux->getDato() == dato)
			{
				return true;
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}
	return false;
}





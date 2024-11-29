#include "ListaCircularDoble.h"
#include <string>
//#include "NodoDoble.cpp"
#include "NodoDoble.h"
#include <iostream>
using namespace std;
template <typename T>
ListaCircularDoble<T>::ListaCircularDoble()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}

template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble()
{
}

template <typename T>
void ListaCircularDoble<T>::insertar_persona(T _nombre1, T _nombre2, T _apellido, T _cedula, T _correo)
{
    //Crear un nuevo nodo con los datos de la persona
    NodoDoble<T>* nuevo = new NodoDoble(_nombre1, _nombre2, _apellido, _cedula, _correo);
    
    // Si la lista está vacía, el nuevo nodo será tanto el cabeza como el último nodo
    if (cabeza == nullptr) {
        cabeza = nuevo;
        nuevo->setSiguiente(cabeza);  // El siguiente del último nodo apunta al primero
        nuevo->setAnterior(cabeza);   // El anterior del primer nodo apunta al último
    }
    else {
        // Si la lista no está vacía, insertamos el nuevo nodo al final
        NodoDoble<T>* aux = cabeza;
        while (aux->getSiguiente() != cabeza) {  // Recorremos hasta llegar al nodo que apunta a cabeza
            aux = aux->getSiguiente();
        }
        // Conectamos el nuevo nodo al final de la lista
        aux->setSiguiente(nuevo);
        nuevo->setAnterior(aux);
        
        // Hacemos que el nuevo nodo apunte de vuelta a la cabeza y la cabeza apunte al nuevo nodo
        nuevo->setSiguiente(cabeza);
        cabeza->setAnterior(nuevo);
    }
}

template <typename T>
void ListaCircularDoble<T>::insertar(T dato)
{
	NodoDoble<T>* nuevo = new NodoDoble(dato);
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

template <typename T>
void ListaCircularDoble<T>::eliminar(T dato)
{
	if (this->cabeza != nullptr)
	{
		if (this->cabeza->getDato() == dato)
		{
			NodoDoble<T>* aux = this->cabeza;
			this->cabeza = this->cabeza->getSiguiente();
			this->cabeza->setAnterior(this->cola);
			this->cola->setSiguiente(this->cabeza);
			delete aux;
		}
		else
		{
			NodoDoble<T>* aux = this->cabeza;
			while (aux->getSiguiente() != this->cabeza)
			{
				if (aux->getSiguiente()->getDato() == dato)
				{
					NodoDoble<T>* aux2 = aux->getSiguiente();
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

template <typename T>
void ListaCircularDoble<T>::mostrar()
{
	if (this->cabeza != nullptr)
	{
		NodoDoble<T>* aux = this->cabeza;
		do
		{
			cout << aux->getDato() << " ";
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		cout << endl;
	}
}

template <typename T>
bool ListaCircularDoble<T>::buscar(int dato)
{
	if (this->cabeza != nullptr)
	{
		NodoDoble<T>* aux = this->cabeza;
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

template<typename T> 
 void ListaCircularDoble<T>::Buscar(T _dato) {
    NodoDoble<T>* aux = this->cabeza;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            cout << "El dato " << _dato << " si se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

// Eliminar una letra específica de todos los nodos

template <typename T>
void ListaCircularDoble<T>::eliminarLetra(char letra) {
    if (!cabeza) return;

    NodoDoble<T>* actual = cabeza;
    do {
        std::string datoStr;

        // Si T es un tipo numérico, usa std::to_string
        if constexpr (std::is_arithmetic<T>::value) {
            datoStr = std::to_string(actual->getDato());
        } else {
            // Si no es numérico, convierte el dato a string si es necesario
            datoStr = actual->getDato();
        }

        std::string resultado;
        for (char c : datoStr) {
            if (c != letra) resultado += c;
        }

        // Solo realiza la conversión de vuelta si T es numérico
        if constexpr (std::is_arithmetic<T>::value) {
            actual->setDato(std::stoi(resultado)); // Convertimos el resultado de vuelta a int
        } else {
            actual->setDato(resultado); // Si T no es numérico, simplemente asignamos el resultado
        }

        actual = actual->getSiguiente();
    } while (actual != cabeza);
}

// Cifrado César para los valores de los nodos
template <typename T>
void ListaCircularDoble<T>::cifrar_cesar(int desplazamiento) {
    if (!cabeza) return;

    NodoDoble<T>* actual = cabeza;
    do {
        std::string datoStr = std::to_string(actual->getDato());
        std::string resultado;
        for (char c : datoStr) {
            if (std::isdigit(c)) {
                int nuevoValor = ((c - '0') + desplazamiento) % 10; // Para cifrar dígitos
                resultado += std::to_string(nuevoValor);
            } else {
                resultado += c;
            }
        }
        actual->setDato(std::stoi(resultado)); // Convertimos el resultado de vuelta a int
        actual = actual->getSiguiente();
    } while (actual != cabeza);
}

// Descifrado César
template <typename T>
void ListaCircularDoble<T>::descifrar_cesar(int desplazamiento) {
    cifrar_cesar(-desplazamiento); // Reutilizamos cifrar_cesar con desplazamiento negativo
}

template <typename T>
T ListaCircularDoble<T>::validar_cedula_existente() {
    Validaciones<std::string> validador;
    std::string cedulaNueva;
    bool cedulaDuplicada;

    do {
        cedulaDuplicada = false;
        cedulaNueva = validador.Ingresar_Cedula();

        NodoDoble<T>* actual = cabeza;
        do {
            // Usamos std::to_string solo si T es un tipo numérico
            std::string datoStr;
            if constexpr (std::is_arithmetic<T>::value) {
                datoStr = std::to_string(actual->getDato()); // Solo para tipos numéricos
            } else {
                datoStr = actual->getDato(); // Para tipos como std::string, no usamos std::to_string
            }

            if (datoStr == cedulaNueva) {
                std::cout << "Cédula ya existente. Ingrese una nueva cédula." << std::endl;
                cedulaDuplicada = true;
                break;
            }
            actual = actual->getSiguiente();
        } while (actual != cabeza);

    } while (cedulaDuplicada);

    return cedulaNueva;
}






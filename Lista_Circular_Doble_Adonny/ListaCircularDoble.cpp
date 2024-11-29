#include "ListaCircularDoble.h"
#include <string>
#include <cstring>
//#include "NodoDoble.h"
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

template<typename T>
void ListaCircularDoble<T>::cifrar_cesar(int desplazamiento) {
    Nodo_Circular<T>* actual = primero;
    if (primero == NULL) {
        cout << endl << "La lista esta vacia, imposible cifrar " << endl;
    }
    else {
        std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        std::string nombre1_cifrado = "";
        std::string nombre2_cifrado = "";
        std::string apellido_cifrado = "";
        std::string cedula_cifrado = "";
        std::string correo_cifrado = "";

        do {
            std::string nombre1 = actual->getNombre1();
            std::string nombre2 = actual->getNombre2();
            std::string apellido = actual->getApellido();
            std::string cedula = actual->getCedula();
            std::string correo = actual->getCorreo();

            for (char caracter : nombre1) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice + desplazamiento) % alfabeto.length();
                    nombre1_cifrado += alfabeto[nuevo_indice];
                } else {
                    nombre1_cifrado += caracter;
                }
            }
            //nombre = nombre_cifrado;

            for (char caracter : nombre2) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice + desplazamiento) % alfabeto.length();
                    nombre2_cifrado += alfabeto[nuevo_indice];
                } else {
                    nombre2_cifrado += caracter;
                }
            }

            for (char caracter : apellido) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice + desplazamiento) % alfabeto.length();
                    apellido_cifrado += alfabeto[nuevo_indice];
                } else {
                    apellido_cifrado += caracter;
                }
            }
            //apellido = apellido_cifrado;

            for (char caracter : cedula) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice + desplazamiento) % alfabeto.length();
                    cedula_cifrado += alfabeto[nuevo_indice];
                } else {
                    cedula_cifrado += caracter;
                }
            }

            for (char caracter : correo) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice + desplazamiento) % alfabeto.length();
                    correo_cifrado += alfabeto[nuevo_indice];
                } else {
                    correo_cifrado += caracter;
                }
            }
            //correo = correo_cifrado;

            actual->setNombre1(nombre1_cifrado);
            actual->setNombre2(nombre2_cifrado);
            actual->setApellido(apellido_cifrado);
            actual->setCedula(cedula_cifrado);
            actual->setCorreo(correo_cifrado);
            actual = actual->getSiguiente();
        }while(actual != primero);
    }
}

// Descifrado César
template<typename T>
void ListaCircularDoble<T>::descifrar_cesar(int desplazamiento) {
    Nodo_Circular<T>* actual = primero;
    if (primero == NULL) {
        cout << endl << "La lista esta vacia, imposible cifrar " << endl;
    }
    else {
        std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        std::string nombre1_cifrado = "";
        std::string nombre2_cifrado = "";
        std::string apellido_cifrado = "";
        std::string cedula_cifrado = "";
        std::string correo_cifrado = "";

        do {
            std::string nombre1 = actual->getNombre1();
            std::string nombre2 = actual->getNombre2();
            std::string apellido = actual->getApellido();
            std::string cedula = actual->getCedula();
            std::string correo = actual->getCorreo();

            for (char caracter : nombre1) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice - desplazamiento) % alfabeto.length();
                    nombre1_cifrado += alfabeto[nuevo_indice];
                } else {
                    nombre1_cifrado += caracter;
                }
            }
            //nombre = nombre_cifrado;

            for (char caracter : nombre2) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice - desplazamiento) % alfabeto.length();
                    nombre2_cifrado += alfabeto[nuevo_indice];
                } else {
                    nombre2_cifrado += caracter;
                }
            }

            for (char caracter : apellido) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice - desplazamiento) % alfabeto.length();
                    apellido_cifrado += alfabeto[nuevo_indice];
                } else {
                    apellido_cifrado += caracter;
                }
            }
            //apellido = apellido_cifrado;

            for (char caracter : cedula) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice - desplazamiento) % alfabeto.length();
                    cedula_cifrado += alfabeto[nuevo_indice];
                } else {
                    cedula_cifrado += caracter;
                }
            }

            for (char caracter : correo) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice - desplazamiento) % alfabeto.length();
                    correo_cifrado += alfabeto[nuevo_indice];
                } else {
                    correo_cifrado += caracter;
                }
            }
            //correo = correo_cifrado;

            actual->setNombre1(nombre1_cifrado);
            actual->setNombre2(nombre2_cifrado);
            actual->setApellido(apellido_cifrado);
            actual->setCedula(cedula_cifrado);
            actual->setCorreo(correo_cifrado);
            actual = actual->getSiguiente();
        }while (actual != primero);
    }
}

template <typename T>
T ListaCircularDoble<T>::validar_cedula_existente()
{
     Nodo_Circular<T>* aux = primero;
    bool repetir = true, valido = true;
    std::string _cedula = "";
    Validaciones<T> ingreso;
    do{
        repetir = false;
        valido = true;
        _cedula = ingreso.Ingresar_Cedula();
        while (aux != NULL) {
            if (_cedula.compare(aux->getCedula()) == 0){
                cout << endl << "Cedula ya existente" << endl << "Ingrese nueva cedula " << endl;
                system("pause");
                valido = false;
                break;
            }
            aux = aux->getSiguiente();
        }
        if (valido == false){
            repetir = true;
        }else if(valido == true){
            repetir = false;
        }
    }while(repetir == true);
    return _cedula;
}

template <typename T>
T ListaCircularDoble<T>::generar_correo(T _nombre, T _nombre2, T _apellido)
{
    NodoDoble<T>* aux = cabeza;
    string n1=_nombre, n2=_nombre2;

    char* cadena = new char[n1.length()+1];
    std::strcpy(cadena, n1.c_str());
    char* cadena2 = new char[n2.length()+1];
    std::strcpy(cadena2, n2.c_str());

        std::string completo =" ";
        std::string ap = _apellido;
    if(cadena2 == NULL /*|| n2 == ""*/) {
        n1 = *(cadena+0);
        n1 = n1 + *(cadena+1);
        //n1 = resultado[0];
        //n1 = n1 + resultado[1];
        completo = n1 + ap +"@espe.edu.ec";
        while (aux != NULL) {
            if (completo.compare(aux->getCorreo()) == 0){
                for (int i = 2 ; completo.compare(aux->getCorreo()) == 0 ; i++){
                    completo = n1 + ap + to_string(i) + "@espe.edu.ec";
                }
            }
            aux = aux->getSiguiente();
        }
    }else if(cadena == NULL || n1 == "") {
        n2 = *(cadena2+0);
        n2 = n2 + cadena2[1];
        completo = n2 + ap +"@espe.edu.ec";
        while (aux != NULL) {
            if (completo.compare(aux->getCorreo()) == 0){
                for (int i = 2 ; completo.compare(aux->getCorreo()) == 0 ; i++){
                    completo = n2 + ap + to_string(i) + "@espe.edu.ec";
                }
            }
            aux = aux->getSiguiente();
        }
    }else{
        n1 = *(cadena+0);
        n2 = *(cadena2+0);
        completo = n1 + n2 + ap +"@espe.edu.ec";
        while (aux != NULL) {
            if (completo.compare(aux->getCorreo()) == 0){
                for (int i = 2 ; completo.compare(aux->getCorreo()) == 0 ; i++){
                    completo = n1 + n2 + ap + to_string(i) + "@espe.edu.ec";
                }
            }
            aux = aux->getSiguiente();
        }
    }
        //delete[] resultado;
     delete[] cadena;
    delete[] cadena2;
    return completo;
}






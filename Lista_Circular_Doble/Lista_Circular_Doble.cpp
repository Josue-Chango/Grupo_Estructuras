#include "Lista_Circular_Doble.h"
#include "Nodo_Circular_Doble.h"
#include "Validaciones.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

template<typename T>
Lista_Circular_Doble<T>::Lista_Circular_Doble()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}
/*
template<typename T>
Lista_Circular_Doble<T>::~Lista_Circular_Doble()
{
}*/

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

/////////////////////////////////////////////////77

template<typename T>
void Lista_Circular_Doble<T>::insertar_persona(T _nombre1, T _nombre2, T _apellido, T _cedula, T _correo, T _placa)
{
    string aux;
    for (char c: _nombre1){
        aux = aux + (char)toupper(c);
    }
    _nombre1 = aux;
    aux = "";

    for (char c: _nombre2){
        aux = aux + (char)toupper(c);
    }
    _nombre2 = aux;
    aux = "";

    for (char c: _apellido){
        aux = aux + (char)toupper(c);
    }
    _apellido = aux;
	Nodo_Circular_Doble<T>* nuevo = new Nodo_Circular_Doble(_nombre1, _nombre2, _apellido, _cedula, _correo, _placa);
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
void Lista_Circular_Doble<T>::mostrar_persona()
{
	if (this->cabeza != nullptr)
	{
		Nodo_Circular_Doble<T>* aux = this->cabeza;
		do
		{
			cout << aux->getNombre1() << " " << aux->getNombre2() << " " << aux->getApellido() << " " << aux->getCedula() << " " << aux->getCorreo() << " " << aux->getPlaca() << "->";
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		cout << endl;
	}
}

template <typename T>
T Lista_Circular_Doble<T>::generar_correo(T _nombre, T _nombre2, T _apellido)
{
    Nodo_Circular_Doble<T>* aux = this->cabeza;
    string n1=_nombre, n2=_nombre2, ap, completo = "";

    for (char c: _apellido){
        ap = ap + (char)tolower(c);
    }
    
    if ((n1 != "" && n2 != "") || ap!="")  {
        char* cadena = new char[n1.length()+1];
        std::strcpy(cadena, n1.c_str());
        char* cadena2 = new char[n2.length()+1];
        std::strcpy(cadena2, n2.c_str());
        if (this->cabeza == nullptr){
            n1 = (char)tolower(*(cadena+0));
            n2 = (char)tolower(*(cadena2+0));
            completo = n1 + n2 + ap +  "@espe.edu.ec";
            return completo;
        }
            
            
        if(n2 == "") {
            n1 = (char)tolower(*(cadena+0));
            n1 = n1 + (char)tolower(*(cadena+1));
            //n1 = resultado[0];
            //n1 = n1 + resultado[1];
            completo = n1 + ap +"@espe.edu.ec";
            do {
                if (completo.compare(aux->getCorreo()) == 0){
                    for (int i = 2 ; completo.compare(aux->getCorreo()) == 0 ; i++){
                        completo = n1 + ap + to_string(i) + "@espe.edu.ec";
                    }
                }
                aux = aux->getSiguiente();
            }while (aux != this->cabeza);
        }else if(n1 == "") {
            n2 = (char)tolower(*(cadena2+0));
            n2 = n2 + (char)tolower(cadena2[1]);
            completo = n2 + ap +"@espe.edu.ec";
            do {
                if (completo.compare(aux->getCorreo()) == 0){
                    for (int i = 2 ; completo.compare(aux->getCorreo()) == 0 ; i++){
                        completo = n2 + ap + to_string(i) + "@espe.edu.ec";
                    }
                }
                aux = aux->getSiguiente();
            }while (aux != this->cabeza);
        }else{
            n1 = (char)tolower(*(cadena+0));
            n2 = (char)tolower(*(cadena2+0));
            completo = n1 + n2 + ap +"@espe.edu.ec";
            int paso = 0, numero = 0;
            bool cambio = false;
            char* aux_completo = new char[completo.length()+1];
            strcpy(aux_completo, completo.c_str());
            string correo_aux = aux->getCorreo();
            do {
                for (char c:correo_aux){
                    if (c==*(aux_completo+paso)){
                        cambio = true;
                    }else if (c!=*(aux_completo+paso)){
                        cambio = false;
                        break;
                    }
                }
                if(cambio == true){
                    do{
                    completo = n1 + n2 + ap + to_string(numero++) + "@espe.edu.ec";
                    for (char c:correo_aux){
                        if (c==*(aux_completo+paso)){
                            cambio = true;
                        }else if (c!=*(aux_completo+paso)){
                            cambio = false;
                            break;
                        }
                    }
                    }while(cambio!=true);
                }
                /*
                if (completo.compare(aux->getCorreo()) == 0){
                    for (int i = 2 ; completo.compare(aux->getCorreo()) == 0 ; i++){
                        completo = n1 + n2 + ap + to_string(i) + "@espe.edu.ec";
                    }
                }*/
                aux = aux->getSiguiente();
            }while (aux != this->cabeza);
        }
            //delete[] resultado;
        delete[] cadena;
        delete[] cadena2;
        return completo;
        }else {
            cout << "Persona no ingresada" << endl << "La persona necesita al menos un nombre y un apellido " << endl;
            return completo;
        }
}


template <typename T>
void Lista_Circular_Doble<T>::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::trunc);
    if (archivo.is_open()) {
        Nodo_Circular_Doble<T>* actual = this->cabeza;
        do {
            archivo << actual->getNombre1() << "," << actual->getNombre2() << "," << actual->getApellido() << "," << actual->getCedula() << "," << actual->getCorreo() << "," << actual->getPlaca() << std::endl;
            actual = actual->getSiguiente();
        }while (actual != this->cabeza);
        archivo.close();
        std::cout << "Lista guardada correctamente en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

template <typename T>
void Lista_Circular_Doble<T>::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream iss(linea);
            std::string nombre1, nombre2, apellido, cedula, correo,placa;
            std::getline(iss, nombre1, ',');
            std::getline(iss, nombre2, ',');
            std::getline(iss, apellido, ',');
            std::getline(iss, cedula, ',');
            std::getline(iss, correo, ',');
            std::getline(iss, placa, ',');
            insertar_persona(nombre1, nombre2, apellido, cedula, correo, placa);
        }
        archivo.close();
        std::cout << "Lista cargada correctamente desde " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}


template <typename T>
void Lista_Circular_Doble<T>::eliminarLetra(char letra) {
    Nodo_Circular_Doble<T>* actual = this->cabeza;
    do {
        std::string nombre1 = actual->getNombre1();
        std::string nombre2 = actual->getNombre2();
        std::string apellido = actual->getApellido();
        std::string correo = actual->getCorreo();

        std::string nuevoNombre1;
        for (char c : nombre1) {
            if (c != letra) {
                nuevoNombre1 += c;
            }
        }
        nombre1 = nuevoNombre1;

        std::string nuevoNombre2;
        for (char c : nombre2) {
            if (c != letra) {
                nuevoNombre2 += c;
            }
        }
        nombre2 = nuevoNombre2;

        std::string nuevoApellido;
        for (char c : apellido) {
            if (c != letra) {
                nuevoApellido += c;
            }
        }
        apellido = nuevoApellido;

        std::string nuevoCorreo;
        for (char c : correo) {
            if (c != letra) {
                nuevoCorreo += c;
            }
        }
        correo = nuevoCorreo;
        actual->setNombre1(nuevoNombre1);
        actual->setNombre2(nuevoNombre2);
        actual->setApellido(nuevoApellido);
        actual->setCorreo(nuevoCorreo);
        actual = actual->getSiguiente();
    }    while (actual != this->cabeza);
}


template<typename T>
void Lista_Circular_Doble<T>::cifrar_cesar(int desplazamiento) {
    Nodo_Circular_Doble<T>* actual = this->cabeza;
    if (this->cabeza == nullptr) {
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
        }while(actual != this->cabeza);
    }
}

template<typename T>
void Lista_Circular_Doble<T>::descifrar_cesar(int desplazamiento) {
    Nodo_Circular_Doble<T>* actual = this->cabeza;
    if (this->cabeza == nullptr) {
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
        }while (actual != this->cabeza);
    }
}


template <typename T>
std::string Lista_Circular_Doble<T>::validar_cedula_existente()
{
    Nodo_Circular_Doble<T>* aux = this->cabeza;
    bool repetir = true, valido = true;
    std::string _cedula = "";
    Validaciones<T> ingreso;
    do{
        repetir = false;
        valido = true;
        _cedula = ingreso.Ingresar_Cedula();
        if (this->cabeza == nullptr){
            repetir = false;
        }else{
            do {
                if (_cedula.compare(aux->getCedula()) == 0){
                    cout << endl << "Cedula ya existente" << endl << "Ingrese nueva cedula " << endl;
                    system("pause");
                    valido = false;
                    break;
                }
                aux = aux->getSiguiente();
            }while (aux != this->cabeza);
            if (valido == false){
                repetir = true;
            }else if(valido == true){
                repetir = false;
            }
        }
    }while(repetir == true);
    return _cedula;
}



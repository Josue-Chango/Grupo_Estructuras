#include "Lista_Circular_Doble.h"
#include "Nodo_Circular_Doble.h"
#include "Validaciones.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>
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
				if (aux->getSiguiente()->getPlaca() == dato)
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
                /*if (_cedula.compare(aux->getCedula()) == 0 &&){
                    cout << endl << "Cedula ya existente" << endl << "Ingrese nueva cedula " << endl;
                    system("pause");
                    valido = false;
                    break;
                }*/
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

template <typename T>
std::string Lista_Circular_Doble<T>::validar_placa_existente()
{
    Nodo_Circular_Doble<T>* aux = this->cabeza;
    bool repetir = true, valido = true;
    std::string _placa = "";
    Validaciones<T> ingreso;
    do{
        repetir = false;
        valido = true;
        _placa = ingreso.Ingresar_Placa();
        if (this->cabeza == nullptr){
            repetir = false;
        }else{
            do {
                if (_placa.compare(aux->getPlaca()) == 0){
                    system("cls");
                    cout << "Placa ya existente en el parqueadero" << endl << "Ingrese nueva placa " << endl;
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
    return _placa;
}

template<typename T>
bool Lista_Circular_Doble<T>::buscar_Placa(std::string _placa)
{
	if (this->cabeza != nullptr)
	{
		Nodo_Circular_Doble<T>* aux = this->cabeza;
		do
		{
			if (aux->getPlaca() == _placa)
			{
				return true;
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}
	return false;
}

template <typename T>
void Lista_Circular_Doble<T>::registro(T _nombre1, T _nombre2, T _apellido, T _cedula, T _correo, T _placa, T _fecha, T _hora, T _minuto, T _segundo)
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
	Nodo_Circular_Doble<T>* nuevo = new Nodo_Circular_Doble(_nombre1, _nombre2, _apellido, _cedula, _correo, _placa, _fecha, _hora, _minuto, _segundo);
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
void Lista_Circular_Doble<T>::guardar_Registro (const std::string& nombreArchivo)
{
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (archivo.is_open()) {
        Nodo_Circular_Doble<T>* actual = this->cabeza;
        do {
            archivo << actual->getNombre1() << "," << actual->getNombre2() << "," << actual->getApellido() << "," << actual->getCedula() << "," << actual->getCorreo() << "," << actual->getPlaca() << "," << actual->getFecha() << "," << actual->getHora() << "," << actual->getMinuto() << "," << actual->getSegundo() << std::endl;
            actual = actual->getSiguiente();
        }while (actual != this->cabeza);
        archivo.close();
        std::cout << "Lista guardada correctamente en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

template <typename T>
void Lista_Circular_Doble<T>::cargar_Registro(const std::string &nombreArchivo)
{
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        int lineasAgregadas = 0;
        while (std::getline(archivo, linea)) {
            std::stringstream iss(linea);
            std::string nombre1, nombre2, apellido, cedula, correo, placa, fecha, hora, minuto, segundo;
            std::getline(iss, nombre1, ',');
            std::getline(iss, nombre2, ',');
            std::getline(iss, apellido, ',');
            std::getline(iss, cedula, ',');
            std::getline(iss, correo, ',');
            std::getline(iss, placa, ',');
            std::getline(iss, fecha, ',');
            std::getline(iss, hora, ',');
            std::getline(iss, minuto, ',');
            std::getline(iss, segundo, ',');
            registro(nombre1, nombre2, apellido, cedula, correo, placa, fecha, hora, minuto, segundo);
        }
        archivo.close();
        std::cout << "Lista cargada correctamente desde " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

template<typename T>
void Lista_Circular_Doble<T>::mostrar_Registro(std::string _placa)
{
	if (this->cabeza != nullptr)
	{
		Nodo_Circular_Doble<T>* aux = this->cabeza;
		do
		{
            if(_placa == aux->getPlaca()){
                cout << aux->getNombre1() << " " << aux->getNombre2() << " " << aux->getApellido() << " " << aux->getCedula() << " " << aux->getCorreo() << " " << aux->getPlaca() << "," << aux->getFecha() << "," << aux->getHora() << "," << aux->getMinuto() << "," << aux->getSegundo() << endl;
            }
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		cout << endl;
	}
}

template<typename T>
void Lista_Circular_Doble<T>::eliminar_Vehiculo(T _placa)
{
	if (this->cabeza != nullptr)
	{
		if (this->cabeza->getPlaca() == _placa)
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
				if (aux->getSiguiente()->getPlaca() == _placa)
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
/*
template <typename T>
bool Lista_Circular_Doble<T>::validar_formato_hora(std::string hora) {
    // Validar que la hora tenga el formato correcto (HH:MM:SS)
    if(hora.length() != 8 || hora[2] != ':' || hora[5] != ':') {
    return false;
    }
    int hh = std::stoi(hora.substr(0, 2));
    int mm = std::stoi(hora.substr(3, 2));
    int ss = std::stoi(hora.substr(6, 2));

    if (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59) {
        return false;
    }

    return true;
    }
*/

template <typename T>
void Lista_Circular_Doble<T>::mostrar_RegistroPorRangoHoras(string horaInicioEntrada, string horaFinEntrada) {
    // Descomponer las horas de inicio y fin
    int horaInicio, minutoInicio, segundoInicio;
    int horaFin, minutoFin, segundoFin;

    // Descomponer la hora de inicio
    std::stringstream ssInicio(horaInicioEntrada);
    char separador;
    ssInicio >> horaInicio >> separador >> minutoInicio >> separador >> segundoInicio;

    // Descomponer la hora de fin
    std::stringstream ssFin(horaFinEntrada);
    ssFin >> horaFin >> separador >> minutoFin >> separador >> segundoFin;

    // Validación: Verificamos si la cadena de entrada es correcta, sin necesidad de comprobación del formato
    if (ssInicio.fail() || ssFin.fail()) {
        std::cerr << "Formato de hora incorrecto." << std::endl;
        return;
    }

    // Validar rangos de hora
    if (horaInicio < 0 || horaInicio >= 24 || minutoInicio < 0 || minutoInicio >= 60 || segundoInicio < 0 || segundoInicio >= 60 ||
        horaFin < 0 || horaFin >= 24 || minutoFin < 0 || minutoFin >= 60 || segundoFin < 0 || segundoFin >= 60) {
        std::cerr << "Valores fuera de rango." << std::endl;
        return;
    }

    if (this->cabeza != nullptr) {
        Nodo_Circular_Doble<T>* aux = this->cabeza;
        auto filtroRangoHoras = [horaInicio, minutoInicio, segundoInicio, horaFin, minutoFin, segundoFin](int hora, int minuto, int segundo) {
            // Convertir las horas, minutos y segundos a un valor comparable (HHMMSS)
            int tiempoInicio = horaInicio * 10000 + minutoInicio * 100 + segundoInicio;
            int tiempoFin = horaFin * 10000 + minutoFin * 100 + segundoFin;
            int tiempoActual = hora * 10000 + minuto * 100 + segundo;
            return tiempoActual >= tiempoInicio && tiempoActual <= tiempoFin;
        };

        do {
            // Obtener la hora, minuto y segundo del nodo actual
            int hora = std::stoi(aux->getHora());  // Convertir la hora de string a int
            int minuto = std::stoi(aux->getMinuto());  // Convertir los minutos de string a int
            int segundo = std::stoi(aux->getSegundo()); // Convertir los segundos de string a int (si está disponible)

            // Comprobar si el vehículo está dentro del rango de horas
            if (filtroRangoHoras(hora, minuto, segundo)) {
                std::cout << aux->getNombre1() << " " << aux->getNombre2() << " " 
                          << aux->getApellido() << " " << aux->getCedula() << " " 
                          << aux->getCorreo() << " " << aux->getPlaca() << ", "
                          << aux->getFecha() << ", " 
                          << std::setw(2) << std::setfill('0') << hora << ":" 
                          << std::setw(2) << std::setfill('0') << minuto << ":" 
                          << std::setw(2) << std::setfill('0') << segundo << std::endl;
            }
            aux = aux->getSiguiente();
        } while (aux != this->cabeza);
        std::cout << std::endl;
    }
}


template <typename T>
void Lista_Circular_Doble<T>::descomponerHora(const std::string& horaEntrada, int& hora, int& minuto, int& segundo) {
    std::stringstream ss(horaEntrada);
    char separador; // Para almacenar el carácter ':' entre hora, minutos y segundos

    // Usamos stringstream para dividir la cadena en tres partes
    ss >> hora >> separador >> minuto >> separador >> segundo;

    // Verificar que la cadena tiene el formato correcto y los valores son válidos
    if (ss.fail() || separador != ':' || hora < 0 || hora >= 24 || minuto < 0 || minuto >= 60 || segundo < 0 || segundo >= 60) {
        std::cerr << "Formato de hora incorrecto o valores fuera de rango." << std::endl;
    }
}

template <typename T>
bool Lista_Circular_Doble<T>::validarHora( std::string horaInicio,  std::string horaFinal) {
    // Convertir las horas de cadena de caracteres a objeto time_t
    std::tm tmInicio = {};
    std::tm tmFinal = {};
    std::istringstream issInicio(horaInicio), issFinal(horaFinal);
    issInicio >> std::get_time(&tmInicio, "%H:%M:%S");
    issFinal >> std::get_time(&tmFinal, "%H:%M:%S");

    // Comparar las horas
    time_t tInicio = std::mktime(&tmInicio);
    time_t tFinal = std::mktime(&tmFinal);
    if (tInicio <= tFinal){
        return true ;
    }else {
        return false;
    }
}


// Función auxiliar para parsear la hora
bool parseHora(const std::string& horaStr, int& hora, int& minuto, int& segundo)
{
    std::stringstream iss(horaStr);
    std::string horaStr_, minutoStr, segundoStr;

    std::getline(iss, horaStr_, ':');
    std::getline(iss, minutoStr, ':');
    std::getline(iss, segundoStr, ':');

    try {
        hora = std::stoi(horaStr_);
        minuto = std::stoi(minutoStr);
        segundo = std::stoi(segundoStr);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

// Función auxiliar para verificar si la hora es válida
bool esHoraValida(const std::string& horaStr, const std::string& minutoStr, const std::string& segundoStr)
{
    return !horaStr.empty() && !minutoStr.empty() && !segundoStr.empty();
}

// Función auxiliar para verificar si la hora está dentro de los límites
bool esEntreLimites(const std::string& horaStr, const std::string& minutoStr, const std::string& segundoStr,
                    int hora1, int minuto1, int segundo1, int hora2, int minuto2, int segundo2)
{
    int hora = std::stoi(horaStr);
    int minuto = std::stoi(minutoStr);
    int segundo = std::stoi(segundoStr);

    return (hora >= hora1 && hora <= hora2 && minuto >= minuto1 && minuto <= minuto2 && segundo >= segundo1 && segundo <= segundo2);
}


template<typename T>
void Lista_Circular_Doble<T>::buscarEnRegistroNuevo(std::string hora_inicio, std::string hora_final) {
    int hora1, minuto1, segundo1;
    if (!parseHora(hora_inicio, hora1, minuto1, segundo1)) {
        std::cerr << "Error al descomponer la hora de inicio" << std::endl;
        return;
    }

    int hora2, minuto2, segundo2;
    if (!parseHora(hora_final, hora2, minuto2, segundo2)) {
        std::cerr << "Error al descomponer la hora final" << std::endl;
        return;
    }

    if (this->cabeza != nullptr) {
        Nodo_Circular_Doble<T>* aux = this->cabeza;
        do {
            std::cout << "Verificando registro: " << aux->getNombre1() << " " << aux->getHora() << ":" << aux->getMinuto() << ":" << aux->getSegundo() << std::endl;
            
            if (esHoraValida(aux->getHora(), aux->getMinuto(), aux->getSegundo()) &&
                esEntreLimites(aux->getHora(), aux->getMinuto(), aux->getSegundo(), hora1, minuto1, segundo1, hora2, minuto2, segundo2)) {
                
                std::cout << aux->getNombre1() << " " << aux->getNombre2() << " " << aux->getApellido() << " "
                          << aux->getCedula() << " " << aux->getCorreo() << " " << aux->getPlaca() << ","
                          << aux->getFecha() << "," << aux->getHora() << "," << aux->getMinuto() << "," << aux->getSegundo() << std::endl;
            }
            aux = aux->getSiguiente();
        } while (aux != this->cabeza);
    }
}



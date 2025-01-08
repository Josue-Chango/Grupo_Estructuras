/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          18/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Lista_Simple.h"
#include "Validaciones.h"
#include "Nodo.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;


template <typename T>
Lista_Simple<T>::Lista_Simple()
{
    cabeza = NULL;
}

template <typename T>
Lista_Simple<T>::Lista_Simple(T _nombre, T _apellido, T _correo)
{
    cabeza = NULL;
}

template <typename T>
void Lista_Simple<T>::insertar_persona(T _nombre1, T _nombre2, T _apellido, T _cedula, T _correo)
{
    Nodo<T>* nuevo = new Nodo(_nombre1, _nombre2, _apellido, _cedula, _correo);
    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {
        Nodo<T>* aux = cabeza;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

template <typename T>
void Lista_Simple<T>::Insertar_cabeza(T _dato)
{
    Nodo<T>* nuevo = new Nodo(_dato);
    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {
        Nodo<T>* aux = cabeza;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

template<typename T> 
 void Lista_Simple<T>::Buscar(T _dato) {
    Nodo<T>* aux = cabeza;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            cout << "El dato " << _dato << " si se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

template<typename T> 
 void Lista_Simple<T>::Eliminar(T _dato) {
    Nodo<T>* aux = cabeza;
    Nodo<T>* anterior = NULL;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            if (anterior == NULL) {
                cabeza = aux->getSiguiente();
            }
            else {
                anterior->setSiguiente(aux->getSiguiente());
            }
            delete aux;
            cout << "El dato " << _dato << " se ha eliminado de la lista" << endl;
            return;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

template<typename T> 
 void Lista_Simple<T>::Mostrar() {
    Nodo<T>* aux = cabeza;
    while (aux != NULL) {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

template <typename T>
void Lista_Simple<T>::mostrar_persona()
{
    Nodo<T>* aux = cabeza;
    while (aux != NULL) {
        cout << aux->getNombre1() << " " << aux->getNombre2() << " " << aux->getApellido() << " " << aux->getCedula() << " "<< aux->getCorreo() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

template <typename T>
T Lista_Simple<T>::generar_correo(T _nombre, T _nombre2, T _apellido)
{
    Nodo<T>* aux = cabeza;
    string n1=_nombre, n2=_nombre2;
    /*int ultimaPosicion = 0;
    
    
    size_t tamaño = n1.length() + 1;
    char* cadena = new char[tamaño];
    strcpy(cadena, n1.c_str());
    cout << "tamaño" << tamaño << endl;
    for (int i = 0; i < tamaño; ++i) {
        if (*(auxiliar+i) == ' ') {
            ultimaPosicion = i;
            cout << "ultimo espacio " << i <<endl;
        }
    }

    string cad;

    for (int i = 0; ultimaPosicion+i < tamaño; i++){
        cad = cad + *(auxiliar+(ultimaPosicion+(i)));
    }
    
    tamaño = cad.length() + 1;
    char* cadena = new char[tamaño];
    strcpy(cadena, n1.c_str());
    delete[] auxiliar;

    //strcpy(cadena, n1.c_str());
    size_t tamaño2 = n2.length() + 1;
    char* cadena2 = new char[tamaño2];
    strcpy(cadena2, n2.c_str());
        std::string completo ="";
        std::string ap = _apellido;
*/
    
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

template <typename T>
void Lista_Simple<T>::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::trunc);
    if (archivo.is_open()) {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            archivo << actual->getNombre1() << "," << actual->getNombre2() << "," << actual->getApellido() << "," << actual->getCedula() << "," << actual->getCorreo() << std::endl;
            actual = actual->getSiguiente();
        }
        archivo.close();
        std::cout << "Lista guardada correctamente en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

template <typename T>
void Lista_Simple<T>::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream iss(linea);
            std::string nombre1, nombre2, apellido, cedula, correo;
            std::getline(iss, nombre1, ',');
            std::getline(iss, nombre2, ',');
            std::getline(iss, apellido, ',');
            std::getline(iss, cedula, ',');
            std::getline(iss, correo, ',');
            insertar_persona(nombre1, nombre2, apellido, cedula, correo);
        }
        archivo.close();
        std::cout << "Lista cargada correctamente desde " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

template <typename T>
void Lista_Simple<T>::eliminarLetra(char letra) {
    Nodo<T>* actual = cabeza;

    while (actual != nullptr) {
        std::string nombre1 = actual->getNombre1();
        std::string nombre2 = actual->getNombre2();
        std::string apellido = actual->getApellido();
        std::string cedula = actual->getCedula();
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

        std::string nuevaCedula;
        for (char c : cedula) {
            if (c != letra) {
                nuevaCedula += c;
            }
        }
        cedula = nuevaCedula;

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
        actual->setCedula(nuevaCedula);
        actual->setCorrero(nuevoCorreo);
        actual = actual->getSiguiente();
    }
}


template<typename T>
void Lista_Simple<T>::cifrar_cesar(int desplazamiento) {
    if (cabeza == NULL) {
        cout << endl << "La lista esta vacia, imposible cifrar " << endl;
    }
    else {
        std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        std::string nombre1_cifrado = "";
        std::string nombre2_cifrado = "";
        std::string apellido_cifrado = "";
        std::string cedula_cifrado = "";
        std::string correo_cifrado = "";

        Nodo<T>* actual = cabeza;

        while (actual != nullptr) {
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
            actual->setCorrero(correo_cifrado);
            actual = actual->getSiguiente();
        }
    }
}

template<typename T>
void Lista_Simple<T>::descifrar_cesar(int desplazamiento) {
    
        Nodo<T>* actual = cabeza;
    if (cabeza == NULL) {
        cout << endl << "La lista esta vacia, imposible cifrar " << endl;
    }
    else {
        std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        std::string nombre1_cifrado = "";
        std::string nombre2_cifrado = "";
        std::string apellido_cifrado = "";
        std::string cedula_cifrado = "";
        std::string correo_cifrado = "";


        while (actual != nullptr) {
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
            actual->setCorrero(correo_cifrado);
            actual = actual->getSiguiente();
        }
    }
}

/*
template<typename T>
void Lista_Simple<T>::cifrar_cesar(int desplazamiento) {
    
    Nodo<T>* actual = cabeza;
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía, imposible cifrar" << std::endl;
    } else {
        std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        auto cifrar_cadena = [*](std::string* cadena) {
            std::string cadena_cifrada = "";
            for (char caracter : cadena) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice + desplazamiento) % alfabeto.length();
                    cadena_cifrada += alfabeto[nuevo_indice];
                } else {
                    cadena_cifrada += caracter;
                }
            }
            cadena = cadena_cifrada;
        };

        while (actual != nullptr) {
            actual->setNombre1(cifrar_cadena(actual->getNombre1()));
            actual->setNombre2(cifrar_cadena(actual->getNombre2()));
            actual->setApellido(cifrar_cadena(actual->getApellido()));
            actual->setCedula(cifrar_cadena(actual->getCedula()));
            actual->setCorrero(cifrar_cadena(actual->getCorreo()));
            actual = actual->getSiguiente();
        }
    }
}

template<typename T>
void Lista_Simple<T>::descifrar_cesar(int desplazamiento) {
    Nodo<T>* actual = cabeza;
    if (actual == nullptr) {
        std::cout << "La lista está vacía, imposible descifrar" << std::endl;
    } else {
        std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        auto descifrar_cadena = [&](std::string& cadena) {
            std::string cadena_descifrada = "";
            for (char caracter : cadena) {
                if (isalpha(caracter)) {
                    int indice = alfabeto.find(tolower(caracter));
                    int nuevo_indice = (indice - desplazamiento + alfabeto.length()) % alfabeto.length();
                    cadena_descifrada += alfabeto[nuevo_indice];
                } else {
                    cadena_descifrada += caracter;
                }
            }
            cadena = cadena_descifrada;
        };


        while (actual != nullptr) {
            descifrar_cadena(actual->getNombre1());
            descifrar_cadena(actual->getNombre2());
            descifrar_cadena(actual->getApellido());
            descifrar_cadena(actual->getCedula());
            descifrar_cadena(actual->getCorreo());
            actual = actual->getSiguiente();
        }
    }
}*/

template <typename T>
T Lista_Simple<T>::validar_cedula_existente()
{
    Nodo<T>* aux = cabeza;
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

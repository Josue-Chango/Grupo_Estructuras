/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "Lista_Circular.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
Lista_Circular<T>::Lista_Circular() {
    primero = NULL;
    ultimo = NULL;
}

template<typename T>
void Lista_Circular<T>::Insertar(T dato) {
    Nodo_Circular<T>* nuevo = new Nodo_Circular<T>(dato);
    if (primero == NULL) {
        primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = primero;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
    }
}

template<typename T>
void Lista_Circular<T>::Buscar(T dato) {
    Nodo_Circular<T>* actual = new Nodo_Circular<T>(dato);
    actual = primero;
    bool encontrado = false;
    if (primero != NULL) {
        do {
            if (actual->getDato() == dato) {
                cout << "El elemento " << dato << " ha sido encontrado en la lista" << endl;
                encontrado = true;
            }
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            cout << "El elemento " << dato << " no ha sido encontrado en la lista" << endl;
        }
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

template<typename T>
void Lista_Circular<T>::Eliminar(T dato) {
    Nodo_Circular<T>* actual = new Nodo_Circular<T>(dato);
    actual = primero;
    Nodo_Circular<T>* anterior = new Nodo_Circular<T>(dato);
    anterior = NULL;
    bool encontrado = false;
    if (primero != NULL) {
        do {
            if (actual->getDato() == dato) {
                if (actual == primero) {
                    primero = primero->getSiguiente();
                }
                else if (actual == ultimo) {
                    anterior->setSiguiente(primero);
                }
                else {
                    anterior->setSiguiente(actual->getSiguiente());
                }
                cout << "El elemento " << dato << " ha sido eliminado de la lista" << endl;
                encontrado = true;
            }
            anterior = actual;
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            cout << "El elemento " << dato << " no ha sido encontrado en la lista" << endl;
        }
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

template<typename T>
void Lista_Circular<T>::Mostrar() {
    Nodo_Circular<T>* actual = new Nodo_Circular<T>(0);
    actual = primero;
    if (primero != NULL) {
        do {
            cout << actual->getDato() << " -> ";
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

template <typename T>
void Lista_Circular<T>::insertar_persona(T _nombre1, T _nombre2, T _apellido, T _correo)
{
    Nodo_Circular<T>* nuevo = new Nodo_Circular(_nombre1, _nombre2, _apellido, _correo);
    if (primero == NULL) {
         primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = primero;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
    }
}

template <typename T>
void Lista_Circular<T>::mostrar_persona()
{
    Nodo_Circular<T>* actual = new Nodo_Circular<T>(0);
    actual = primero;
    if (primero != NULL) {
        do {
            cout << actual->getNombre1() << " " << actual->getNombre2() << " " << actual->getApellido() << " " << actual->getCorreo() << " -> ";
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

template <typename T>
T Lista_Circular<T>::generar_correo(T _nombre, T _nombre2, T _apellido)
{
    Nodo_Circular<T>* aux = primero;
    string n1=_nombre, n2=_nombre2, ap=_apellido, completo =" ";;
    
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
    if ((n1 != "" && n2 != "") || ap!="")  {
        char* cadena = new char[n1.length()+1];
        std::strcpy(cadena, n1.c_str());
        char* cadena2 = new char[n2.length()+1];
        std::strcpy(cadena2, n2.c_str());

            
            
        if(n2 == "") {
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
        }else if(n1 == "") {
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
        }else {
            cout << "Persona no ingresada" << endl << "La persona necesita al menos un nombre y un apellido " << endl;
            return completo;
        }
    
}

template <typename T>
void Lista_Circular<T>::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::trunc);
    if (archivo.is_open()) {
        Nodo_Circular<T>* actual = primero;
        while (actual != nullptr) {
            archivo << actual->getNombre1() << "," << actual->getNombre2() << "," << actual->getApellido() << "," << actual->getCorreo() << std::endl;
            actual = actual->getSiguiente();
        }
        archivo.close();
        std::cout << "Lista guardada correctamente en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

template <typename T>
void Lista_Circular<T>::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream iss(linea);
            std::string nombre1, nombre2, apellido, correo;
            std::getline(iss, nombre1, ',');
            std::getline(iss, nombre2, ',');
            std::getline(iss, apellido, ',');
            std::getline(iss, correo, ',');
            insertar_persona(nombre1, nombre2, apellido, correo);
        }
        archivo.close();
        std::cout << "Lista cargada correctamente desde " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

template <typename T>
void Lista_Circular<T>::eliminarLetra(char letra) {
    Nodo_Circular<T>* actual = primero;

    while (actual != nullptr) {
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
    }
}
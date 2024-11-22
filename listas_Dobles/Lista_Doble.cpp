/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "Lista_Doble.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

template<typename T>
Lista_Doble<T>::Lista_Doble() {
    primero = NULL;
    ultimo = NULL;
}

template <typename T>
Lista_Doble<T>::Lista_Doble(T _nombre1, T _nombre2, T _apellido, T _correo)
{
    primero = NULL;
    ultimo = NULL;
}

template<typename T>
void Lista_Doble<T>::Insertar(T _dato) {
    Nodo_Doble<T>* nuevo = new Nodo_Doble(_dato);
    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
}

template<typename T>
void Lista_Doble<T>::Buscar(T _dato) {
    Nodo_Doble<T>* aux = primero;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            cout << "El dato " << _dato << " se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

template<typename T>
void Lista_Doble<T>::Eliminar(T _dato) {
    Nodo_Doble<T>* aux = primero;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            if (aux == primero) {
                primero = primero->getSiguiente();
                primero->setAnterior(NULL);
            }
            else if (aux == ultimo) {
                ultimo = ultimo->getAnterior();
                ultimo->setSiguiente(NULL);
            }
            else {
                aux->getAnterior()->setSiguiente(aux->getSiguiente());
                aux->getSiguiente()->setAnterior(aux->getAnterior());
            }
            delete aux;
            cout << "El dato " << _dato << " se ha eliminado de la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

template<typename T>
void Lista_Doble<T>::Mostrar() {
    Nodo_Doble<T>* aux = primero;
    while (aux != NULL) {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << endl;
}

template <typename T>
void Lista_Doble<T>::insertar_persona(T _nombre1, T _nombre2, T _apellido, T _correo)
{
    Nodo_Doble<T>* nuevo = new Nodo_Doble(_nombre1, _nombre2, _apellido, _correo);
    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
}

template <typename T>
T Lista_Doble<T>::generar_correo(T _nombre1, T _nombre2, T _apellido)
{
    Nodo_Doble<T>* aux = primero;
    Nodo_Doble<T>* aux2 = ultimo;
    string n1=_nombre1, n2=_nombre2;
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
    
    cout << n1 << endl;
    char* cadena = new char[n1.length()+1];
    std::strcpy(cadena, n1.c_str());
    cout << cadena << endl;
    cout << n1 << endl;
    char* cadena2 = new char[n2.length()+1];
    std::strcpy(cadena2, n2.c_str());
    cout << cadena2 << endl;

        std::string completo =" ";
        std::string ap = _apellido;
    if(cadena2 == NULL || n2 == "") {
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
void Lista_Doble<T>::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::trunc);
    if (archivo.is_open()) {
        Nodo_Doble<T>* actual = primero;
        while (actual != nullptr) {
            archivo << actual->getNombre1() << "," << actual->getNombre2() << actual->getApellido() << "," << actual->getCorreo() << std::endl;
            actual = actual->getSiguiente();
        }
        archivo.close();
        std::cout << "Lista guardada correctamente en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

template <typename T>
void Lista_Doble<T>::cargarDesdeArchivo(const std::string& nombreArchivo) {
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

template<typename T>
void Lista_Doble<T>::eliminarLetra(char letra) {
    Nodo_Doble<T>* actual = primero;
    Nodo_Doble<T>* actualAtras = ultimo;

    while (actual != nullptr) {
        std::string nombre1 = actual->getNombre1();
        std::string nombre2 = actual->getNombre2();
        std::string apellido = actual->getApellido();
        std::string correo = actual->getCorreo();

        std::string nuevoNombre;
        for (char c : nombre1) {
            if (c != letra) {
                nuevoNombre += c;
            }
        }
        nombre1 = nuevoNombre;

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
        actual->setNombre1(nuevoNombre);
        actual->setNombre2(nuevoNombre2);
        actual->setApellido(nuevoApellido);
        actual->setCorreo(nuevoCorreo);
        actual = actual->getSiguiente();
    }
}

template <typename T>
void Lista_Doble<T>::mostrar_persona()
{
    Nodo_Doble<T>* aux = primero;
    while (aux != NULL) {
        cout << aux->getNombre1() << " " << aux->getNombre2() << " " << aux->getApellido() << " "<< aux->getCorreo() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << endl;
}
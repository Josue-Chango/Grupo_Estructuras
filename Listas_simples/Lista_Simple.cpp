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
#include <cstring>
#include <string>

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
void Lista_Simple<T>::insertar_persona(T _nombre, T _apellido, T _correo)
{
    Nodo<T>* nuevo = new Nodo(_nombre, _apellido, _correo);
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

/*template<typename T> 
 void Lista_Simple<T>::Insertar_cola(T _dato) {
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
}*/

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
        cout << aux->getNombre() << " " << aux->getApellido() << " "<< aux->getCorreo() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

template <typename T>
T Lista_Simple<T>::generar_correo(T _nombre, T _nombre2, T _apellido)
{
    Nodo<T>* aux = cabeza;
    string n1=_nombre, n2=_nombre2;
    int ultimaPosicion = 0;
    
    
    size_t tamaño = n1.length() + 1;
    char* cadena = new char[tamaño];
    strcpy(cadena, n1.c_str());
    /*cout << "tamaño" << tamaño << endl;
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
    delete[] auxiliar;*/

    //strcpy(cadena, n1.c_str());
    size_t tamaño2 = n2.length() + 1;
    char* cadena2 = new char[tamaño2];
    strcpy(cadena2, n2.c_str());
        std::string completo ="";
        std::string ap = _apellido;
    if(cadena2 == NULL || n2 == "") {
        n1 = *(cadena+0);
        n1 = n1 + cadena[1];
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

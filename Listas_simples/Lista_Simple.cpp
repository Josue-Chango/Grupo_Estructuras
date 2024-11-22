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
#include <fstream>
#include <sstream>


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
void Lista_Simple<T>::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::trunc);
    if (archivo.is_open()) {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            archivo << actual->getNombre() << "," << actual->getApellido() << "," << actual->getCorreo() << std::endl;
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
            std::string nombre, apellido, correo;
            std::getline(iss, nombre, ',');
            std::getline(iss, apellido, ',');
            std::getline(iss, correo, ',');
            insertar_persona(nombre, apellido, correo);
        }
        archivo.close();
        std::cout << "Lista cargada correctamente desde " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

/*template <typename T>
void Lista_Simple<T>::eliminarLetra(char letra) {
    Nodo<T>* actual = cabeza;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->dato == letra) {
            if (actual == cabeza) {
                cabeza = actual->siguiente;
                delete actual;
                actual = cabeza;
            } else {
                anterior->siguiente = actual->siguiente;
                Nodo<T>* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}
*/
template <typename T>
void Lista_Simple<T>::eliminarLetra(string letra) {
    Nodo<T>* actual = cabeza;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr) {
        std::string nombre = actual->getNombre();
        std::string apellido = actual->getApellido();
        std::string correo = actual->getCorreo();



        nombre.erase(std::remove(nombre.begin(), nombre.end(), letra), nombre.end());
        apellido.erase(std::remove(apellido.begin(), apellido.end(), letra), apellido.end());
        correo.erase(std::remove(correo.begin(), correo.end(), letra), correo.end());

        actual->setNombre() = static_cast<T>(nombre);
        actual->setApellido() = static_cast<T>(apellido);
        actual->setCorrero() = static_cast<T>(correo);

        // Avanzar al siguiente elemento
        anterior = actual;
        actual = actual->siguiente;
    }
}

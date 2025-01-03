#include "Lista.h"
#include <fstream>
#include <iostream>
using namespace std;

template <typename T>
ListaSimple<T>::ListaSimple() : primero(nullptr) {}

template <typename T>
void ListaSimple<T>::insertar(T dato, const std::string& nombreArchivo) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (!primero) {
        primero = nuevo;
    } else {
        Nodo<T>* temp = primero;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevo);
    }
    GuardarArchivo(nombreArchivo);
}

template <typename T>
void ListaSimple<T>::buscarPorPlaca(string placa) {
    Nodo<T>* temp = primero;
    while (temp != nullptr) {
        if (temp->getDato().placa == placa) {
            cout << "Encontrado: " << temp->getDato() << endl;
            return;
        }
        temp = temp->getSiguiente();
    }
    cout << "No se encontró el vehículo con placa: " << placa << endl;
}

template <typename T>
void ListaSimple<T>::eliminarPorPlaca(string placa) {
    if (!primero) {
        cout << "La lista está vacía." << endl;
        return;
    }

    if (primero->getDato().placa == placa) {
        Nodo<T>* temp = primero;
        primero = primero->getSiguiente();
        delete temp;
        cout << "Vehículo eliminado." << endl;
        return;
    }

    Nodo<T>* temp = primero;
    while (temp->getSiguiente() && temp->getSiguiente()->getDato().placa != placa) {
        temp = temp->getSiguiente();
    }

    if (temp->getSiguiente()) {
        Nodo<T>* nodoAEliminar = temp->getSiguiente();
        temp->setSiguiente(nodoAEliminar->getSiguiente());
        delete nodoAEliminar;
        cout << "Vehículo eliminado." << endl;
    } else {
        cout << "No se encontró el vehículo con placa: " << placa << endl;
    }
}

template <typename T>
void ListaSimple<T>::mostrar(Nodo<T>* aux) {
    Nodo<T>* temp = primero;
    while (temp != nullptr) {
        cout << temp->getDato() << endl;
        temp = temp->getSiguiente();
    }
}

template <typename T>
void ListaSimple<T>::CargarArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    T dato;
    while (archivo >> dato) {
        insertar(dato, ""); // No guardamos en archivo durante carga.
    }

    archivo.close();
}

template <typename T>
void ListaSimple<T>::GuardarArchivo(string nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    Nodo<T>* temp = primero;
    while (temp != nullptr) {
        archivo << temp->getDato() << endl;
        temp = temp->getSiguiente();
    }

    archivo.close();
}

template <typename T>
void ListaSimple<T>::salirDelParqueadero(const std::string& placa) {
    eliminarPorPlaca(placa);
}

template <typename T>
std::string ListaSimple<T>::cifrarTexto(const std::string& texto) {
    std::string cifrado;
    for (char c : texto) {
        cifrado += c + 3;
    }
    return cifrado;
}

template <typename T>
std::string ListaSimple<T>::descifrarTexto(const std::string& texto) {
    std::string descifrado;
    for (char c : texto) {
        descifrado += c - 3;
    }
    return descifrado;
}

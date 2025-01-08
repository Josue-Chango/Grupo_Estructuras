#include "Lista.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>


template <typename T>
ListaSimple<T>::ListaSimple() : primero(nullptr) {}

template <typename T>
void ListaSimple<T>::insertar(T dato, const std::string& nombreArchivo) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (!primero) {
        primero = nuevo;
    } else {
        Nodo<T>* aux = primero;
        while (aux->getSiguiente()) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
    GuardarArchivo(nombreArchivo); // Guardar en archivo tras la inserción
}

template <typename T>
void ListaSimple<T>::buscarPorPlaca(string placa) {
    Nodo<T>* aux = primero;
    bool encontrado = false;
    while (aux) {
        if (aux->getDato().getPlaca() == placa) {
            std::cout << aux->getDato() << std::endl;
            encontrado = true;
            break;
        }
        aux = aux->getSiguiente();
    }
    if (!encontrado) {
        std::cout << "No se encontró un vehículo con la placa: " << placa << std::endl;
    }
}

template <typename T>
void ListaSimple<T>::BusquedaAvanzada(string criterio, string valorInicio, string valorFin) {
    Nodo<T>* aux = primero;
    while (aux) {
        T dato = aux->getDato();
        if (criterio == "marca" && dato.getMarca() >= valorInicio && dato.getMarca() <= valorFin) {
            std::cout << dato << std::endl;
        } else if (criterio == "modelo" && dato.getModelo() >= valorInicio && dato.getModelo() <= valorFin) {
            std::cout << dato << std::endl;
        }
        aux = aux->getSiguiente();
    }
}

template <typename T>
void ListaSimple<T>::eliminarPorPlaca(string placa) {
    Nodo<T>* aux = primero;
    Nodo<T>* anterior = nullptr;

    while (aux) {
        if (aux->getDato().getPlaca() == placa) {
            if (anterior) {
                anterior->setSiguiente(aux->getSiguiente());
            } else {
                primero = aux->getSiguiente();
            }
            delete aux;
            std::cout << "Vehículo con placa " << placa << " eliminado." << std::endl;
            return;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
    std::cout << "No se encontró un vehículo con la placa: " << placa << std::endl;
}

template <typename T>
void ListaSimple<T>::mostrar(Nodo<T>* aux) {
    if (!aux) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    while (aux) {
        std::cout << aux->getDato() << std::endl;
        aux = aux->getSiguiente();
    }
}

template <typename T>
void ListaSimple<T>::CargarArchivo(string nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    T dato;
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        ss >> dato; // Asegúrate de tener sobrecargado el operador `>>` para T
        insertar(dato, ""); // Insertar en la lista sin guardar de nuevo en archivo
    }
    archivo.close();
}

template <typename T>
void ListaSimple<T>::GuardarArchivo(string nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    Nodo<T>* aux = primero;
    while (aux) {
        archivo << aux->getDato() << std::endl; // Asegúrate de tener sobrecargado el operador `<<` para T
        aux = aux->getSiguiente();
    }
    archivo.close();
}

template <typename T>
void ListaSimple<T>::salirDelParqueadero(const std::string& placa) {
    Nodo<T>* aux = primero;
    while (aux) {
        if (aux->getDato().getPlaca() == placa) {
            auto horaSalida = std::chrono::system_clock::now();
            aux->getDato().setHoraSalida(horaSalida);
            std::cout << "Vehículo con placa " << placa << " ha salido del parqueadero." << std::endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    std::cout << "No se encontró un vehículo con la placa: " << placa << std::endl;
}

template <typename T>
std::string ListaSimple<T>::cifrarTexto(const std::string& texto) {
    std::string cifrado = texto;
    std::transform(cifrado.begin(), cifrado.end(), cifrado.begin(), [](char c) {
        return c + 3; // Ejemplo de cifrado simple (César)
    });
    return cifrado;
}

template <typename T>
std::string ListaSimple<T>::descifrarTexto(const std::string& texto) {
    std::string descifrado = texto;
    std::transform(descifrado.begin(), descifrado.end(), descifrado.begin(), [](char c) {
        return c - 3; // Inverso del cifrado
    });
    return descifrado;
}

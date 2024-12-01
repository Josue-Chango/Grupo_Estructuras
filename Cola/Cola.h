#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <queue>
#include <string>

template<typename T, typename U>  // T para el nombre y U para la edad
class Elemento {
private:
    std::string nombre;
    U edad;  // La edad ahora es del tipo U (template)

public:
    // Constructor
    Elemento(std::string nombre = "", U edad = U()) : nombre(nombre), edad(edad) {}

    // Métodos getter y setter para el nombre
    std::string getNombre() const { return nombre; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }

    // Métodos getter y setter para la edad
    U getEdad() const { return edad; }
    void setEdad(U nuevaEdad) { edad = nuevaEdad; }

    // Mostrar el elemento
    void mostrar() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
    }
};

template<typename T, typename U>  // T para el tipo de la cola y U para la edad
class Cola {
private:
    std::queue<Elemento<T, U>> cola;

public:
    // Agregar un elemento a la cola
    void agregarElemento(const Elemento<T, U>& elemento);

    // Eliminar un elemento de la cola
    void eliminarElemento();

    // Buscar un elemento por nombre
    void buscarElemento(const std::string& nombre);

    // Editar un elemento en la cola
    void editarElemento(const std::string& nombre);

    // Mostrar todos los elementos en la cola
    void mostrarElementos();
};

#endif // COLA_H





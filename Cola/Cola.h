#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <queue>
#include <string>

class Elemento {
private:
    std::string nombre;
    int edad;

public:
    // Constructor
    Elemento(std::string nombre = "", int edad = 0) : nombre(nombre), edad(edad) {}

    // Métodos getter y setter para el nombre
    std::string getNombre() const { return nombre; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }

    // Métodos getter y setter para la edad
    int getEdad() const { return edad; }
    void setEdad(int nuevaEdad) { edad = nuevaEdad; }

    // Mostrar el elemento
    void mostrar() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
    }
};

class Cola {
private:
    std::queue<Elemento> cola;

public:
    // Agregar un elemento a la cola
    void agregarElemento(const Elemento& elemento);

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



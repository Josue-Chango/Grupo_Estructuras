#ifndef ARBOLAA_H
#define ARBOLAA_H

#include "NodoAA.h"
#include "Lista.h"     
#include "Coche.h" 
#include <graphics.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

template <typename T>
class ArbolAA {
public:
    ArbolAA() : raiz(nullptr) {}

    void insertar(int clave);
    void insertarPersona(T,T,T,T);
    void buscar(int clave);
    void eliminar(int clave);
    void mostrar();
    int altura(NodoAA<T>* nodo);
    int profundidad(int clave);
    int niveles();
    NodoAA<T>* raiz;
    void verArbol();
    void guardarEnArchivo(const std::string& nombreArchivo);
    void reconstruirDesdeArchivo(const std::string& nombreArchivo);
    //void insertarNodo(const std::string& nombre, const std::string& apellido, const std::string& cedula, const std::string& placa);
    void cargarDesdeArchivoParqueadero(const std::string& nombreArchivo);
    void imprimirArbol(NodoAA<T>* nodo, int espacio);
    void insertarPuestosOcupados(ListaCircularDoble<Coche>& listaCoches);
private:
    

    NodoAA<T>* inclinar(NodoAA<T>* nodo);
    NodoAA<T>* dividir(NodoAA<T>* nodo);
    NodoAA<T>* insertar(NodoAA<T>* nodo, int clave);
    NodoAA<T>* insertarPersona(NodoAA<T>* nodo, T _nombre, T _apellido, T _cedula, T _placa);
    NodoAA<T>* eliminar(NodoAA<T>* nodo, int clave);
    void recorridoInorden(NodoAA<T>* nodo);
    void recorridoPreorden(NodoAA<T>* nodo);
    void recorridoPostorden(NodoAA<T>* nodo);
    void dibujarArbol(NodoAA<T>* nodo, int x, int y, int offset);
    void guardarEnArchivoRecursivo(NodoAA<T>* nodo, std::ofstream& archivo);
    

};


template <typename T>
NodoAA<T>* ArbolAA<T>::inclinar(NodoAA<T>* nodo) {
    if (nodo == nullptr || nodo->izquierda == nullptr)
        return nodo;

    if (nodo->izquierda->nivel == nodo->nivel) {
        NodoAA<T>* izquierda = nodo->izquierda;
        nodo->izquierda = izquierda->derecha;
        izquierda->derecha = nodo;
        return izquierda;
    }

    return nodo;
}

template <typename T>
NodoAA<T>* ArbolAA<T>::dividir(NodoAA<T>* nodo) {
    if (nodo == nullptr || nodo->derecha == nullptr || nodo->derecha->derecha == nullptr)
        return nodo;

    if (nodo->nivel == nodo->derecha->derecha->nivel) {
        NodoAA<T>* derecha = nodo->derecha;
        nodo->derecha = derecha->izquierda;
        derecha->izquierda = nodo;
        derecha->nivel++;
        return derecha;
    }

    return nodo;
}

template <typename T>
NodoAA<T>* ArbolAA<T>::insertar(NodoAA<T>* nodo, int clave) {
    if (nodo == nullptr)
        return new NodoAA<T>(clave);

    if (clave < nodo->clave)
        nodo->izquierda = insertar(nodo->izquierda, clave);
    else if (clave > nodo->clave)
        nodo->derecha = insertar(nodo->derecha, clave);
    else
        return nodo;

    nodo = inclinar(nodo);
    nodo = dividir(nodo);
    return nodo;
}

template <typename T>
void ArbolAA<T>::insertar(int clave) {
    raiz = insertar(raiz, clave);
}

template <typename T>
NodoAA<T>* ArbolAA<T>::insertarPersona(NodoAA<T>* nodo, T _nombre, T _apellido, T _cedula, T _placa) {
    if (nodo == nullptr)
        return new NodoAA<T>(_nombre, _apellido, _cedula, _placa);

    if (stoi(_cedula) < stoi(nodo->cedula))
        nodo->izquierda = insertarPersona(nodo->izquierda, _nombre, _apellido, _cedula, _placa);
    else if (stoi(_cedula) > stoi(nodo->cedula))
        nodo->derecha = insertarPersona(nodo->derecha, _nombre, _apellido, _cedula, _placa);
    else
        return nodo;

    nodo = inclinar(nodo);
    nodo = dividir(nodo);
    return nodo;
}

template <typename T>
inline void ArbolAA<T>::insertarPersona(T _nombre, T _apellido, T _cedula, T _placa)
{
    raiz = insertarPersona(raiz, _nombre, _apellido, _cedula, _placa);
}

template <typename T>
void ArbolAA<T>::buscar(int clave) {
    NodoAA<T>* actual = raiz;
    int nivel = 0;
    
    while (actual != nullptr) {
        if (clave == actual->clave) {
            std::cout << "Encontrado en el nivel " << nivel << ", nodo con clave " << actual->clave << std::endl;
            return; // Aquí se puede devolver la profundidad si es necesario
        } else if (clave < actual->clave) {
            actual = actual->izquierda;
        } else {
            actual = actual->derecha;
        }
        nivel++;
    }
    
    std::cout << "No encontrado" << std::endl;
    return;
}

template <typename T>
NodoAA<T>* ArbolAA<T>::eliminar(NodoAA<T>* nodo, int clave) {
    if (nodo == nullptr) {
        return nullptr;
    }

    // Búsqueda del nodo a eliminar
    if (clave < nodo->clave) {
        nodo->izquierda = eliminar(nodo->izquierda, clave);
    } else if (clave > nodo->clave) {
        nodo->derecha = eliminar(nodo->derecha, clave);
    } else {
        // Nodo encontrado
        if (nodo->izquierda == nullptr) {
            return nodo->derecha;
        } else if (nodo->derecha == nullptr) {
            return nodo->izquierda;
        } else {
            // Nodo con dos hijos
            NodoAA<T>* minDerecho = nodo->derecha;
            while (minDerecho->izquierda != nullptr) {
                minDerecho = minDerecho->izquierda;
            }
            nodo->clave = minDerecho->clave;
            nodo->derecha = eliminar(nodo->derecha, minDerecho->clave);
        }
    }

    // Ajustar el árbol después de la eliminación
    nodo = inclinar(nodo);
    nodo = dividir(nodo);
    return nodo;
}

template <typename T>
void ArbolAA<T>::eliminar(int clave) {
    raiz = eliminar(raiz, clave);
}

template <typename T>
void ArbolAA<T>::recorridoInorden(NodoAA<T>* nodo) {
    if (nodo == nullptr)
        return;
    recorridoInorden(nodo->izquierda);
    std::cout << nodo->clave << " ";
    recorridoInorden(nodo->derecha);
}

template <typename T>
void ArbolAA<T>::recorridoPreorden(NodoAA<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->clave << " ";  // Visitar el nodo raíz
        recorridoPreorden(nodo->izquierda);  // Recorrer el subárbol izquierdo
        recorridoPreorden(nodo->derecha);  // Recorrer el subárbol derecho
    }
}

template <typename T>
void ArbolAA<T>::recorridoPostorden(NodoAA<T>* nodo) {
    if (nodo != nullptr) {
        recorridoPostorden(nodo->izquierda);  // Recorrer el subárbol izquierdo
        recorridoPostorden(nodo->derecha);  // Recorrer el subárbol derecho
        std::cout << nodo->clave << " ";  // Visitar el nodo raíz
    }
}

template <typename T>
void ArbolAA<T>::mostrar() {
    std::cout << "recorrido inorden: ";
    recorridoInorden(raiz);
    std::cout << std::endl;
    std::cout << "recorrido preorden: ";
    recorridoPreorden(raiz);
    std::cout << std::endl;
    std::cout << "recorrido postorden: ";
    recorridoPostorden(raiz);
    std::cout << std::endl;
}

template <typename T>
int ArbolAA<T>::altura(NodoAA<T>* nodo) {
    if (nodo == nullptr) {
        return -1; // Altura de un árbol vacío es -1
    }
    int alturaIzquierda = altura(nodo->izquierda);
    int alturaDerecha = altura(nodo->derecha);
    return std::max(alturaIzquierda, alturaDerecha) + 1;
}

template <typename T>
int ArbolAA<T>::profundidad(int clave) {
    NodoAA<T>* actual = raiz;
    int nivel = 0;
    
    while (actual != nullptr) {
        if (clave == actual->clave) {
            return nivel; // Devolver la profundidad del nodo encontrado
        } else if (clave < actual->clave) {
            actual = actual->izquierda;
        } else {
            actual = actual->derecha;
        }
        nivel++;
    }
    
    return -1; // Indicar que no se encontró el nodo
}

template <typename T>
int ArbolAA<T>::niveles() {
    return altura(raiz) + 1; // La cantidad de niveles es altura + 1
}

template <typename T>
void ArbolAA<T>::dibujarArbol(NodoAA<T>* nodo, int x, int y, int offset) {
    if (nodo == nullptr) return;

    // Dibujar el nodo actual
    circle(x, y, 20);
    //outtextxy(x - 10, y - 10, to_string(nodo->data).c_str());
    char buffer[10];
    sprintf(buffer, "%d", nodo->clave); // Convierte el entero a una cadena
    outtextxy(x - 10, y - 10, buffer); // Usa la cadena para graficar

    // Dibujar el subárbol izquierdo
    if (nodo->izquierda) {
        line(x, y, x - offset, y + 50);
        dibujarArbol(nodo->izquierda, x - offset, y + 50, offset / 2);
    }

    // Dibujar el subárbol derecho
    if (nodo->derecha) {
        line(x, y, x + offset, y + 50);
        dibujarArbol(nodo->derecha, x + offset, y + 50, offset / 2);
    }
}

/*template <typename T>
void ArbolAA<T>::verArbol() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    dibujarArbol(raiz, getmaxx() / 3, 50, 100); // Dibuja el árbol centrado en la pantalla
    getch();
    closegraph();
}*/
template <typename T>
void ArbolAA<T>::verArbol() {
    if (raiz == nullptr) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }

    imprimirArbol(raiz, 0);
}

template <typename T>
void ArbolAA<T>::imprimirArbol(NodoAA<T>* nodo, int espacio) {
    if (nodo == nullptr) return;

    const int ESPACIO_ENTRE_NIVELES = 6;
    espacio += ESPACIO_ENTRE_NIVELES;

    // Primero imprime el subárbol derecho
    imprimirArbol(nodo->derecha, espacio);

    // Imprime el nodo con el espaciado correcto
    std::cout << std::endl;
    for (int i = ESPACIO_ENTRE_NIVELES; i < espacio; i++)
        std::cout << " ";
    std::cout << nodo->clave << "\n";

    // Luego imprime el subárbol izquierdo
    imprimirArbol(nodo->izquierda, espacio);
}

template <typename T>
void ArbolAA<T>::guardarEnArchivoRecursivo(NodoAA<T>* nodo, std::ofstream& archivo) {
    if (nodo != nullptr) {
        archivo << nodo->getNombre() << "," << nodo->getApellido() << "," << nodo->getCedula() << "," << nodo->getPlaca() << std::endl;
        guardarEnArchivoRecursivo(nodo->izquierda, archivo);
        guardarEnArchivoRecursivo(nodo->derecha, archivo);
    }
}

template <typename T>
void ArbolAA<T>::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::out);
    if (archivo.is_open()) {
        guardarEnArchivoRecursivo(raiz, archivo);
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
}

template <typename T>
void ArbolAA<T>::reconstruirDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::in);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string nombre, apellido, cedula, placa;
            std::getline(ss, nombre, ',');
            std::getline(ss, apellido, ',');
            std::getline(ss, cedula, ',');
            std::getline(ss, placa, ',');
            insertarPersona(nombre, apellido, cedula, placa);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
}

template <typename T>
void ArbolAA<T>::insertarPuestosOcupados(ListaCircularDoble<Coche>& listaCoches) {
    Nodo<Coche>* actual = listaCoches.getPrimero();

    if (actual != nullptr) {
        do {
            Coche coche = actual->getDato();
            if (coche.getPuesto() > 0) {  // ✅ Insertar solo los puestos ocupados
                insertar(coche.getPuesto());
            }
            actual = actual->getSiguiente();
        } while (actual != listaCoches.getPrimero());
    }
}


/*template <typename T>
void ArbolAA<T>::insertarNodo(const std::string& nombre, const std::string& apellido, const std::string& cedula, const std::string& placa) {
    //NodoAA<T>* nuevoNodo = new NodoAA<T>(nombre, apellido, cedula, placa);
    raiz = insertarPersona(raiz, nombre, apellido, cedula, placa);
}*/

template <typename T>
    void ArbolAA<T>::cargarDesdeArchivoParqueadero(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string nombre, apellido, cedula, placa, correo;
            std::getline(ss, nombre, ',');
            std::getline(ss, apellido, ',');
            std::getline(ss, cedula, ',');
            std::getline(ss, correo, ',');
            std::getline(ss, placa, ',');
            insertarPersona(nombre, apellido, cedula, placa);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
    }



#endif // ARBOLAA_H

#include "ArbolAA.h"
#include <iostream>

Nodo* ArbolAA::inclinar(Nodo* nodo) {
    if (nodo == nullptr || nodo->izquierda == nullptr)
        return nodo;

    if (nodo->izquierda->nivel == nodo->nivel) {
        Nodo* izquierda = nodo->izquierda;
        nodo->izquierda = izquierda->derecha;
        izquierda->derecha = nodo;
        return izquierda;
    }

    return nodo;
}

Nodo* ArbolAA::dividir(Nodo* nodo) {
    if (nodo == nullptr || nodo->derecha == nullptr || nodo->derecha->derecha == nullptr)
        return nodo;

    if (nodo->nivel == nodo->derecha->derecha->nivel) {
        Nodo* derecha = nodo->derecha;
        nodo->derecha = derecha->izquierda;
        derecha->izquierda = nodo;
        derecha->nivel++;
        return derecha;
    }

    return nodo;
}

Nodo* ArbolAA::insertar(Nodo* nodo, int clave) {
    if (nodo == nullptr)
        return new Nodo(clave);

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

void ArbolAA::insertar(int clave) {
    raiz = insertar(raiz, clave);
}

bool ArbolAA::buscar(int clave) {
    Nodo* actual = raiz;
    int nivel = 0;
    
    while (actual != nullptr) {
        if (clave == actual->clave) {
            std::cout << "Encontrado en el nivel " << nivel << ", nodo con clave " << actual->clave << std::endl;
            return true; // Aquí se puede devolver la profundidad si es necesario
        } else if (clave < actual->clave) {
            actual = actual->izquierda;
        } else {
            actual = actual->derecha;
        }
        nivel++;
    }
    
    std::cout << "No encontrado" << std::endl;
    return false;
}

Nodo* ArbolAA::eliminar(Nodo* nodo, int clave) {
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
            Nodo* minDerecho = nodo->derecha;
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

void ArbolAA::eliminar(int clave) {
    raiz = eliminar(raiz, clave);
}

void ArbolAA::recorridoInorden(Nodo* nodo) {
    if (nodo == nullptr)
        return;
    recorridoInorden(nodo->izquierda);
    std::cout << nodo->clave << " ";
    recorridoInorden(nodo->derecha);
}

void ArbolAA::recorridoPreorden(Nodo* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->clave << " ";  // Visitar el nodo raíz
        recorridoPreorden(nodo->izquierda);  // Recorrer el subárbol izquierdo
        recorridoPreorden(nodo->derecha);  // Recorrer el subárbol derecho
    }
}

void ArbolAA::recorridoPostorden(Nodo* nodo) {
    if (nodo != nullptr) {
        recorridoPostorden(nodo->izquierda);  // Recorrer el subárbol izquierdo
        recorridoPostorden(nodo->derecha);  // Recorrer el subárbol derecho
        std::cout << nodo->clave << " ";  // Visitar el nodo raíz
    }
}

void ArbolAA::mostrar() {
    recorridoInorden(raiz);
    std::cout << std::endl;
    recorridoPreorden(raiz);
    std::cout << std::endl;
    recorridoPostorden(raiz);
    std::cout << std::endl;
}

int ArbolAA::altura(Nodo* nodo) {
    if (nodo == nullptr) {
        return -1; // Altura de un árbol vacío es -1
    }
    int alturaIzquierda = altura(nodo->izquierda);
    int alturaDerecha = altura(nodo->derecha);
    return std::max(alturaIzquierda, alturaDerecha) + 1;
}

int ArbolAA::profundidad(int clave) {
    Nodo* actual = raiz;
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

int ArbolAA::niveles() {
    return altura(raiz) + 1; // La cantidad de niveles es altura + 1
}

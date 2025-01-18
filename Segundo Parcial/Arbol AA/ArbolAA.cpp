#include "ArbolAA.h"
#include <iostream>
#include <graphics.h>

template <typename T>
Nodo<T>* ArbolAA<T>::inclinar(Nodo<T>* nodo) {
    if (nodo == nullptr || nodo->izquierda == nullptr)
        return nodo;

    if (nodo->izquierda->nivel == nodo->nivel) {
        Nodo<T>* izquierda = nodo->izquierda;
        nodo->izquierda = izquierda->derecha;
        izquierda->derecha = nodo;
        return izquierda;
    }

    return nodo;
}

template <typename T>
Nodo<T>* ArbolAA<T>::dividir(Nodo<T>* nodo) {
    if (nodo == nullptr || nodo->derecha == nullptr || nodo->derecha->derecha == nullptr)
        return nodo;

    if (nodo->nivel == nodo->derecha->derecha->nivel) {
        Nodo<T>* derecha = nodo->derecha;
        nodo->derecha = derecha->izquierda;
        derecha->izquierda = nodo;
        derecha->nivel++;
        return derecha;
    }

    return nodo;
}

template <typename T>
Nodo<T>* ArbolAA<T>::insertar(Nodo<T>* nodo, int clave) {
    if (nodo == nullptr)
        return new Nodo<T>(clave);

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
void ArbolAA<T>::buscar(int clave) {
    Nodo<T>* actual = raiz;
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
Nodo<T>* ArbolAA<T>::eliminar(Nodo<T>* nodo, int clave) {
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
            Nodo<T>* minDerecho = nodo->derecha;
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
void ArbolAA<T>::recorridoInorden(Nodo<T>* nodo) {
    if (nodo == nullptr)
        return;
    recorridoInorden(nodo->izquierda);
    std::cout << nodo->clave << " ";
    recorridoInorden(nodo->derecha);
}

template <typename T>
void ArbolAA<T>::recorridoPreorden(Nodo<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->clave << " ";  // Visitar el nodo raíz
        recorridoPreorden(nodo->izquierda);  // Recorrer el subárbol izquierdo
        recorridoPreorden(nodo->derecha);  // Recorrer el subárbol derecho
    }
}

template <typename T>
void ArbolAA<T>::recorridoPostorden(Nodo<T>* nodo) {
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
int ArbolAA<T>::altura(Nodo<T>* nodo) {
    if (nodo == nullptr) {
        return -1; // Altura de un árbol vacío es -1
    }
    int alturaIzquierda = altura(nodo->izquierda);
    int alturaDerecha = altura(nodo->derecha);
    return std::max(alturaIzquierda, alturaDerecha) + 1;
}

template <typename T>
int ArbolAA<T>::profundidad(int clave) {
    Nodo<T>* actual = raiz;
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
void ArbolAA<T>::dibujarArbol(Nodo<T>* nodo, int x, int y, int offset) {
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

template <typename T>
void ArbolAA<T>::verArbol() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    dibujarArbol(raiz, getmaxx() / 2, 50, 200); // Dibuja el árbol centrado en la pantalla
    getch();
    closegraph();
}
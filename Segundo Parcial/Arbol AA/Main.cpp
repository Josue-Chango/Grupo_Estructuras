#include "ArbolAA.h"
#include <iostream>
#include <graphics.h>

int main() {
    ArbolAA<int> arbol;

    // Inserción de elementos
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(20);

    // Visualización del árbol
    std::cout << "Arbol AA: " << std::endl;
    arbol.mostrar();

    // Búsqueda de elementos
    std::cout << "Buscando 7: ";
    arbol.buscar(7) ;
    std::cout << std::endl;

    std::cout << "Buscando 8: ";
    arbol.buscar(8);
    std::cout << std::endl;

    // Eliminación de elementos
    arbol.eliminar(15);
    std::cout << "Arbol AA despues de eliminar 15: " << std::endl;
    arbol.mostrar();

    std::cout << "Altura del arbol: " << arbol.altura(arbol.raiz) << std::endl;
    std::cout << "Niveles del arbol: " << arbol.niveles() << std::endl;
    int clave = 10;
    int profundidad = arbol.profundidad(clave);
    if (profundidad != -1) {
        std::cout << "Profundidad del nodo " << clave << ": " << profundidad << std::endl;
    } else {
        std::cout << "Nodo no encontrado." << std::endl;
    }

    arbol.verArbol();

    system("pause");
    return 0;
}

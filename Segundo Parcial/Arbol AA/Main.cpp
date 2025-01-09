#include "ArbolAA.cpp"
#include <iostream>

int main() {
    ArbolAA arbol;

    // Inserción de elementos
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(20);

    // Visualización del árbol
    std::cout << "Árbol AA: ";
    arbol.mostrar();

    // Búsqueda de elementos
    std::cout << "Buscando 7: " << (arbol.buscar(7) ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscando 8: " << (arbol.buscar(8) ? "Encontrado" : "No encontrado") << std::endl;

     // Visualización del árbol
    std::cout << "Árbol AA: ";
    arbol.mostrar();

    // Búsqueda de elementos
    std::cout << "Buscando 7: ";
    arbol.buscar(7); // Ahora solo se pasa la clave

    std::cout << "Buscando 8: ";
    arbol.buscar(8); // Ahora solo se pasa la clave

    // Eliminación de elementos
    arbol.eliminar(15);
    std::cout << "Árbol AA después de eliminar 15: ";
    arbol.mostrar();
    

     std::cout << "Altura del árbol: " << arbol.altura(arbol.raiz) << std::endl;
    std::cout << "Niveles del árbol: " << arbol.niveles() << std::endl;
    int clave = 10;
    int profundidad = arbol.profundidad(clave);
    if (profundidad != -1) {
        std::cout << "Profundidad del nodo " << clave << ": " << profundidad << std::endl;
    } else {
        std::cout << "Nodo no encontrado." << std::endl;
    }

    system("pause");
    return 0;
}

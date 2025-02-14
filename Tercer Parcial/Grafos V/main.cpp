#include <iostream>
#include "Grafo.h"
#include "Validaciones.h"
#include <graphics.h>

void mostrarMenu() {
    std::cout << "---- GRAFOS BUSQUEDA EN AMPLITUD ----\n";
    std::cout << "\n";
    std::cout << "1. Grafo Dirigido\n";
    std::cout << "2. Grafo No Dirigido\n";
    std::cout << "3. Salir\n"; 
    std::cout << "\n";
    std::cout << "Seleccione una opcion: ";
}

void mostrarSubMenu() {
    std::cout << "1. Representacion Logica\n";
    std::cout << "2. Representacion de lista de adyacencia\n";
    std::cout << "3. Representacion de la matriz de adyacencia\n";
    std::cout << "4. Regresar\n"; 
    std::cout << "Seleccione una opcion: ";
}

void inicializarGraphics() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); 
    if (graphresult() != grOk) {
        std::cerr << "Error al inicializar la biblioteca gráfica: " << grapherrormsg(graphresult()) << std::endl;
        exit(1);
    }
}

void mostrarListaAdyacencia(Grafo& grafo) {
    for (int i = 0; i < grafo.nodos.size(); ++i) {
        std::cout << "Nodo " << i << ": ";
        for (NodoGrafo* adyacente : grafo.nodos[i]->adyacentes) {
            std::cout << adyacente->valor << " ";
        }
        std::cout << std::endl;
    }
}

void mostrarMatrizAdyacencia(Grafo& grafo) {
    int n = grafo.nodos.size();
    std::vector<std::vector<int>> matriz(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (NodoGrafo* adyacente : grafo.nodos[i]->adyacentes) {
            matriz[i][adyacente->valor] = 1;
        }
    }
    std::cout << "Matriz de adyacencia:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Grafo grafo;
    Validaciones validaciones;
    int opcion, subOpcion, verticeInicial;

    while (true) { 
       system("cls");
        mostrarMenu();
        std::cin >> opcion;

        if (!validaciones.esOpcionValida(opcion)) {
            std::cout << "Opcion invalida.\n";
            continue; 
        }

        if (opcion == 3) {
            std::cout << "Saliendo del programa...\n";
            break; 
        }

        switch (opcion) {
            case 1:
            case 2:
                mostrarSubMenu();
                std::cin >> subOpcion;

                if (!validaciones.esOpcionValida(subOpcion)) {
                    std::cout << "Opcion invalida.\n";
                    continue; 
                }

                if (subOpcion == 4) {
                    continue; 
                }

                switch (subOpcion) {
                    case 1:
                        std::cout << "Ingrese el vertice inicial (0-7): ";
                        std::cin >> verticeInicial;

                        if (!validaciones.esNumeroValido(verticeInicial)) {
                            std::cout << "Vertice invalido.\n";
                            continue; 
                        }

                        std::cout << "Inicializando gráficos...\n";
                        inicializarGraphics();
                        std::cout << "Graficando el grafo...\n";
                        grafo.graficar(verticeInicial); 
                        std::cout << "Presione cualquier tecla para cerrar el grafico...\n";
                        getch(); 
                        closegraph();
                        break;
                    case 2:
                        std::cout << "Ingrese el vertice inicial (0-7): ";
                        std::cin >> verticeInicial;

                        if (!validaciones.esNumeroValido(verticeInicial)) {
                            std::cout << "Vertice invalido.\n";
                            continue; 
                        }

                        std::cout << "Inicializando gráficos...\n";
                        inicializarGraphics();
                        std::cout << "Graficando la lista de adyacencia...\n";
                        grafo.graficarListaAdyacencia(verticeInicial); 
                        std::cout << "Presione cualquier tecla para cerrar el grafico...\n";
                        getch(); 
                        closegraph();
                        break;
                    case 3:
                        std::cout << "Ingrese el vertice inicial (0-7): "; 
                        std::cin >> verticeInicial;

                        if (!validaciones.esNumeroValido(verticeInicial)) {
                            std::cout << "Vertice invalido.\n";
                            continue; 
                        }

                        std::cout << "Inicializando gráficos...\n";
                        inicializarGraphics();
                        std::cout << "Graficando la matriz de adyacencia...\n";
                        grafo.graficarMatrizAdyacencia(verticeInicial); 
                        std::cout << "Presione cualquier tecla para cerrar el grafico...\n";
                        getch(); 
                        closegraph();
                        break;
                    default:
                        std::cout << "Opcion invalida.\n";
                        continue; 
                }
                break;
            default:
                std::cout << "Opcion invalida.\n";
                continue; 
        }
    }

    return 0;
}

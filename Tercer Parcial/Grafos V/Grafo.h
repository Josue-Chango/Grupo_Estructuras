#ifndef GRAFO_H
#define GRAFO_H

#include "nodoGrafo.h"
#include <vector>

class Grafo {
public:
    std::vector<NodoGrafo*> nodos;
    Grafo();
    void agregarArista(int origen, int destino, bool dirigido);
    void bfs(int verticeInicial);
    void graficar(int verticeInicial);
    void dibujarFlecha(int x1, int y1, int x2, int y2);
    void graficarAristas();
    void graficarListaAdyacencia(int verticeInicial);
    void graficarMatrizAdyacencia(int verticeInicial);
};

#endif

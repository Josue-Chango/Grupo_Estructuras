#ifndef NODOGRAFO_H
#define NODOGRAFO_H

#include <vector>

class NodoGrafo {
public:
    int valor;
    std::vector<NodoGrafo*> adyacentes;
    NodoGrafo(int val);
};

#endif

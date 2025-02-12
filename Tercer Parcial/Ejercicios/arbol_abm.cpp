// arbol_abm.cpp
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo(int v, Nodo* i = nullptr, Nodo* d = nullptr) : valor(v), izq(i), der(d) {}
};

bool esABM(Nodo* x) {
    if (!x) return true;
    if ((x->izq && x->valor > x->izq->valor) || (x->der && x->valor > x->der->valor)) return false;
    return esABM(x->izq) && esABM(x->der);
}

int main() {
    Nodo* raiz = new Nodo(2, new Nodo(5, new Nodo(8), new Nodo(5)), new Nodo(4, nullptr, new Nodo(7)));
    cout << (esABM(raiz) ? "El árbol es ABM" : "El árbol no es ABM") << endl;
    return 0;
}
// arbol_espejo.cpp
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo(int v, Nodo* i = nullptr, Nodo* d = nullptr) : valor(v), izq(i), der(d) {}
};

bool espejos(Nodo* x, Nodo* y) {
    if (!x && !y) return true;
    if (!x || !y) return false;
    return (x->valor == y->valor) && espejos(x->izq, y->der) && espejos(x->der, y->izq);
}

int main() {
    Nodo* a = new Nodo(1, new Nodo(2), new Nodo(3));
    Nodo* b = new Nodo(1, new Nodo(3), new Nodo(2));
    cout << (espejos(a, b) ? "Los árboles son espejos" : "Los árboles no son espejos") << endl;
    system("pause");
    return 0;
}
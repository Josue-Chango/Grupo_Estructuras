#ifndef OPERACIONESMATRIZ_H
#define OPERACIONESMATRIZ_H

#include "Matriz.h"

class OperacionesMatriz {
public:
    // Método para sumar dos matrices y guardar el resultado en una tercera
    static void sumar(const Matriz& mat1, const Matriz& mat2, Matriz& matSuma);
};

#endif // OPERACIONESMATRIZ_H

#include "Validaciones.h"
#include <iostream>

bool Validaciones::esNumeroValido(int numero) {
    return numero >= 0 && numero <= 7; // Validate numbers 0 to 7
}

bool Validaciones::esOpcionValida(int opcion) {
    return opcion >= 1 && opcion <= 3; // Validate options 1, 2, and 3
}

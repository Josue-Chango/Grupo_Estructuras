#include "Elemento.h"

// Implementación de la función para verificar si una cadena es un entero
bool esEntero(string linea) {
    int i = 0;
    if (linea[0] == '-') {
        i = 1;
    }
    for (; i < linea.length(); i++) {
        if (linea[i] < '0' || linea[i] > '9') {
            return false;
        }
    }
    return true;
}

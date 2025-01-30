#include "vehiculo_mas_cercano.h"
#include <cmath>
#include <vector>
#include <algorithm> // Para std::lower_bound

// Función para calcular la distancia
int calcularDistancia(int posicion, int posicionReferencia) {
    return std::abs(posicion - posicionReferencia);
}

// Método para buscar el vehículo más cercano
Coche VehiculoMasCercano::buscarVehiculoMasCercano(ListaCircularDoble<Coche>& lista, int posicionReferencia) {
    // Convertir la lista circular a un vector de coches
    std::vector<Coche> coches;
    Nodo<Coche>* actual = lista.getPrimero();
    do {
        coches.push_back(actual->getDato());
        actual = actual->getSiguiente();
    } while (actual != lista.getPrimero());

    // Ordenar los coches por posición
    std::sort(coches.begin(), coches.end(), [posicionReferencia](const Coche& a, const Coche& b) {
        return calcularDistancia(a.getPosicion(), posicionReferencia) < calcularDistancia(b.getPosicion(), posicionReferencia);
    });


    // Retornar el coche más cercano
    return coches.front();
}

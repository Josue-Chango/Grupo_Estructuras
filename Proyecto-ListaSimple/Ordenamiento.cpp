#include "Ordenamiento.h"
#include <algorithm>

void Ordenamiento::ordenarPorPlaca(std::vector<Propietario>& propietarios) {
    std::sort(propietarios.begin(), propietarios.end(), [](const Propietario& a, const Propietario& b) {
        return a.getPlaca() < b.getPlaca();
    });
}

void Ordenamiento::ordenarPorNombre(std::vector<Propietario>& propietarios) {
    std::sort(propietarios.begin(), propietarios.end(), [](const Propietario& a, const Propietario& b) {
        return a.getNombre() < b.getNombre();
    });
}
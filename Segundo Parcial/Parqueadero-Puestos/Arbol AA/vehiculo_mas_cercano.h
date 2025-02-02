#ifndef VEHICULO_MAS_CERCANO_H
#define VEHICULO_MAS_CERCANO_H

#include "Coche.h"
#include "Lista.h"
#include <vector>

class VehiculoMasCercano {
public:
    static Coche buscarVehiculoMasCercano(ListaCircularDoble<Coche>& lista, int posicionReferencia);
};

#endif

#include <iostream>
#include "Menu.h"

int main() {
    // Instancia de la lista de propietarios
    ListaPropietarios listaPropietarios;
    listaPropietarios.cargarArchivo("propietarios.txt");

    // Instancia de las listas simples para coches
    ListaSimple<Coche> listaCochesHistorial;
    listaCochesHistorial.CargarArchivo("autos_historial.txt");

    ListaSimple<Coche> listaCoches;
    listaCoches.CargarArchivo("autos.txt");

    // Llamada al menú principal
    menu(listaCoches, listaCochesHistorial, listaPropietarios);

    return 0;
}


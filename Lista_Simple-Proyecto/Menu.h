#pragma once
#include <iostream>
#include <vector>
#include "Coche.h"
#include "Lista.h"
#include "ListaPropietarios.h"

using namespace std;

// Declaración de funciones para el menú interactivo
void menu(ListaSimple<Coche> &lista, ListaSimple<Coche> &listaHistorial, ListaPropietarios &listaPropietarios);
int menuInteractivo(const vector<string> &opciones, const string &titulo = "Menu Interactivo");
void menuBusquedaAvanzada(ListaSimple<Coche> &lista, ListaSimple<Coche> &listaHistorial);
void menuOrdenar(ListaSimple<Coche> &lista, ListaSimple<Coche> &listaHistorial);

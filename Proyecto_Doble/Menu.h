#pragma once
#include <iostream>
#include <vector>
#include "Lista.h"
#include "ListaPropietarios.h"


using namespace std;

void menu(ListaDoble<Coche> &lista, ListaDoble<Coche> &listaHistorial, ListaPropietarios &listaPropietarios);
int menuInteractivo(const vector<string> &opciones, const string &titulo = "Menu Interactivo");
void menuBusquedaAvanzada(ListaDoble<Coche> &lista, ListaDoble<Coche> &listaHistorial);
void menuOrdenar(ListaDoble<Coche> &lista, ListaDoble<Coche> &listaHistorial);
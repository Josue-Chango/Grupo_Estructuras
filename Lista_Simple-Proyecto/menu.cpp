#include <iostream>
#include <vector>
#include <conio.h>
#include "ListaPropietarios.h"
#include "Coche.h"
#include "Lista.h"
#include "Validaciones.h"
#include "ValidacionPlaca.h"
#include "Menu.h"
#include "Ordenamiento.h"

using namespace std;

Coche coche;

int menuInteractivo(const vector<string> &opciones, const string &titulo) {
    int seleccion = 0;
    const int numOpciones = opciones.size();

    while (true) {
        system("cls");

        cout << "========================================" << endl;
        cout << "        " << titulo << endl;
        cout << "========================================" << endl;

        for (int i = 0; i < numOpciones; ++i) {
            if (i == seleccion) {
                cout << " > " << opciones[i] << " < " << endl;
            } else {
                cout << "   " << opciones[i] << endl;
            }
        }

        char tecla = _getch();

        if (tecla == 'a' || tecla == 72) {
            seleccion = (seleccion - 1 + numOpciones) % numOpciones;
        } else if (tecla == 's' || tecla == 80) {
            seleccion = (seleccion + 1) % numOpciones;
        } else if (tecla == 13) {
            return seleccion;
        }
    }
}

void menuGestionPropietarios(ListaPropietarios &listaPropietarios) {
    bool salirSubmenu = false;
    while (!salirSubmenu) {
        system("cls");
        vector<string> opcionesPropietarios = {
            "Agregar Propietario",
            "Mostrar Propietarios",
            "Buscar Propietario por Cedula",
            "Eliminar Placa de Propietario",
            "Volver al Menu Principal"};

        int seleccionPropietarios = menuInteractivo(opcionesPropietarios, "Menu de Gestion de Propietarios");

        switch (seleccionPropietarios) {
        case 0:
            agregarPropietario(listaPropietarios);
            listaPropietarios.guardarArchivo("propietarios.txt");
            break;
        case 1:
            listaPropietarios.mostrarPropietarios();
            system("pause");
            break;
        case 2: {
            string cedula;
            cout << "Ingrese la cedula a buscar: ";
            cin >> cedula;
            Propietario *propietario = listaPropietarios.buscarPropietarioPorCedula(cedula);
            if (propietario) {
                cout << "Propietario encontrado: " << propietario->toString() << endl;
            } else {
                cout << "Propietario no encontrado." << endl;
            }
            system("pause");
            break;
        }
        case 3:
            eliminarPlacaPropietario(listaPropietarios);
            listaPropietarios.guardarArchivo("propietarios.txt");
            break;
        case 4:
            salirSubmenu = true;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    }
}

void menu(ListaSimple<Coche> &lista, ListaSimple<Coche> &listaHistorial, ListaPropietarios &listaPropietarios) {
    vector<string> opciones = {
        "Insertar Coche",
        "Mostrar Lista de Coches",
        "Busqueda de Coche Por Placa",
        "Menu de Gestion de Propietarios",
        "Liberar el parqueadero",
        "Ordenar lista de coches",
        "Salir"};

    while (true) {
        int seleccion = menuInteractivo(opciones, "Menu de Parqueadero");

        switch (seleccion) {
        case 0: {
            if (listaPropietarios.estaVacia()) {
                cout << "No hay propietarios registrados. Registre un propietario antes de continuar." << endl;
                break;
            }

            Coche nuevoCoche = Coche().InsertarDatos(lista, listaHistorial, listaPropietarios);
            lista.insertar(nuevoCoche, "autos.txt");
            listaHistorial.insertar(nuevoCoche, "autos_historial.txt");
            break;
        }
        case 1:
            lista.mostrar(lista.getPrimero());
            break;
        case 2: {
            string placa;
            cout << "Ingrese la placa a buscar: ";
            cin >> placa;
            lista.buscarPorPlaca(placa);
            break;
        }
        case 3:
            menuGestionPropietarios(listaPropietarios);
            break;
        case 4: {
            string placa;
            cout << "Ingrese la placa del coche a liberar: ";
            cin >> placa;
            lista.eliminarPorPlaca(placa);
            listaHistorial.salirDelParqueadero(placa);
            break;
        }
        case 5:
            menuOrdenar(lista, listaHistorial);
            break;
        case 6:
            lista.GuardarArchivo("autos.txt");
            listaHistorial.GuardarArchivo("autos_historial.txt");
            listaPropietarios.guardarArchivo("propietarios.txt");
            cout << "Guardando datos y saliendo..." << endl;
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }

        system("pause");
    }
}

void menuOrdenar(ListaSimple<Coche> &lista, ListaSimple<Coche> &listaHistorial) {
    vector<string> opcionesMetodo = {
        "Quick Sort",
        "Bubble Sort",
        "Volver al Menu Principal"};

    int seleccionMetodo = menuInteractivo(opcionesMetodo, "Seleccione el metodo de ordenamiento:");
    if (seleccionMetodo == 2) return;

    vector<string> opcionesOrdenar = {
        "Ordenar por Placa",
        "Ordenar por Marca",
        "Volver al Menu Principal"};

    int seleccionOrdenar = menuInteractivo(opcionesOrdenar, "Seleccione el criterio de ordenamiento:");
    if (seleccionOrdenar == 2) return;

    if (seleccionMetodo == 0) {
        ordenarLista(lista, [](const Coche &a, const Coche &b) { return a.getPlaca() < b.getPlaca(); });
        cout << "Lista ordenada por placa." << endl;
    } else if (seleccionMetodo == 1) {
        ordenarListaBubbleSort(lista, [](const Coche &a, const Coche &b) { return a.getPlaca() < b.getPlaca(); });
        cout << "Lista ordenada por placa con Bubble Sort." << endl;
    }
}


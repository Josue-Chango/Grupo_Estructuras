#pragma once
#include "Nodo.h"

using namespace std;

template <typename T>
class ListaSimple {
private:
    Nodo<T>* primero;

public:
    Nodo<T>* getPrimero() {
        return primero;
    }
    ListaSimple();
    void insertar(T dato, const std::string& nombreArchivo);
    void buscarPorPlaca(string placa);
    void BusquedaAvanzada(string criterio, string valorInicio, string valorFin);
    void eliminarPorPlaca(string placa);
    void mostrar(Nodo<T> *aux);
    void CargarArchivo(string nombreArchivo);
    void GuardarArchivo(string nombreArchivo);
    void salirDelParqueadero(const std::string& placa);
    static std::string cifrarTexto(const std::string &texto);
    static std::string descifrarTexto(const std::string &texto);
};

#include "Lista.cpp"

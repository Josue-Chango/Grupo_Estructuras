#pragma once
#include "Nodo.h"
#include <graphics.h>

//const int TOTAL_PUESTOS = 20;       
//extern bool puestos[TOTAL_PUESTOS];

using namespace std;

template <typename T>
class ListaCircularDoble {
private:
      
    Nodo<T>* ultimo;    
    Nodo<T>* primero;
public:
     
  Nodo<T>* getPrimero() {
        return primero;
    }
    
    ListaCircularDoble();     
    void insertar(T dato,const std::string& nombreArchivo);    
    void buscarPorPlaca(string placa);
    Nodo<T>* obtenerNodoPorPlaca(string placa);
    void BusquedaAvanzada(string criterio, string valorInicio, string valorFin);      
    void eliminarPorPlaca(string placa);    
    void mostrar(Nodo<T> *aux);  
    void CargarArchivo(string nombreArchivo);
    void GuardarArchivo(string nombreArchivo);
    void salirDelParqueadero(const std::string& placa);
    static std::string cifrarTexto(const std::string &texto); // Declarar como estático
    static std::string descifrarTexto(const std::string &texto);
};

extern void liberarPuesto(int puesto);


#include "Lista.cpp"


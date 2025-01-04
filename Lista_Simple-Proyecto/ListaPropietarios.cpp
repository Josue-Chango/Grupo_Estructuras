#include "ListaPropietarios.h"
#include "Lista.h"
#include <fstream>
#include <sstream>
#include <algorithm>

// Agregar un propietario a la lista
void ListaPropietarios::agregarPropietario(const Propietario &propietario)
{
    propietarios.push_back(propietario);
}

// Buscar un propietario por cédula
Propietario* ListaPropietarios::buscarPropietarioPorCedula(const string &cedula)
{
    for (auto &propietario : propietarios)
    {
        if (propietario.getCedula() == cedula)
        {
            return &propietario;
        }
    }
    return nullptr;
}

// Mostrar todos los propietarios
void ListaPropietarios::mostrarPropietarios() const
{
    for (const auto &propietario : propietarios)
    {
        cout << propietario.toString() << endl;
    }
}

// Verificar si la lista está vacía
bool ListaPropietarios::estaVacia() const
{
    return propietarios.empty();
}

// Cargar propietarios desde un archivo
void ListaPropietarios::cargarArchivo(const string &archivo)
{
    ifstream file(archivo);
    if (file.is_open())
    {
        string linea;
        while (getline(file, linea))
        {
            stringstream ss(linea);
            string nombre, apellido, cedula, correo, placa;
            getline(ss, nombre, ',');
            getline(ss, apellido, ',');
            getline(ss, cedula, ',');
            getline(ss, correo, ',');
            Propietario propietario(nombre, apellido, cedula, correo);
            while (getline(ss, placa, ','))
            {
                propietario.agregarPlaca(ListaSimple<Propietario>::descifrarTexto(placa));
            }
            agregarPropietario(propietario);
        }
        file.close();
    }
}

// Guardar propietarios en un archivo
void ListaPropietarios::guardarArchivo(const string &archivo) const
{
    ofstream file(archivo);
    if (file.is_open())
    {
        for (const auto &propietario : propietarios)
        {
            file << propietario.getNombre() << ","
                 << propietario.getApellido() << ","
                 << propietario.getCedula() << ","
                 << propietario.getCorreo();
            for (const auto &placa : propietario.getPlacas())
            {
                file << "," << ListaSimple<Propietario>::cifrarTexto(placa);
            }
            file << endl;
        }
        file.close();
    }
}

#include <iostream>
#include "Coche.h"
#include "Menu.h"
#include "ValidacionPlaca.h"
#include "Validaciones.h"
#include "ListaPropietarios.h"
#include <string> 
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <algorithm>

using namespace std;

void Coche::mostrar_auto_imagen(const std::string& nombreArchivo, const std::string& modelo) {
    // Parte 1 del HTML antes del modelo
    std::string parte1 = R"(<!DOCTYPE html>
<html>
<head>
  <title>Imagen de Automóvil</title>
  <script>
    function showCarImage() {
      // Obtener el modelo de automóvil desde la URL
      var urlParams = new URLSearchParams(window.location.search);
      var model = urlParams.get('model') || ')";

    // Parte 2 del HTML después del modelo
    std::string parte2 = R"(';

      // Construir la URL de la imagen de Google Images
      var apiKey = "AIzaSyCmZ5odHg7yZxs2eAPnNxH-WWEW-wurOCc";
      var cx = "b2146b1832abc4b95";
      var imageUrl = "https://www.googleapis.com/customsearch/v1?key=" + apiKey + "&cx=" + cx + "&searchType=image&q=" + encodeURIComponent(model);

      // Hacer una solicitud a la API de Google Custom Search
      fetch(imageUrl)
        .then(response => response.json())
        .then(data => {
          // Obtener la URL de la primera imagen
          var imageUrl = data.items[0].link;

          // Mostrar la imagen en la página
          var imageElement = document.getElementById("carImage");
          imageElement.src = imageUrl;
        })
        .catch(error => {
          console.error("Error al obtener la imagen:", error);
        });
    }
  </script>
</head>
<body onload="showCarImage())";

    // Parte 3 del HTML después del modelo en <h2>
    std::string parte3 = R"(">
<img id="carImage" alt="Imagen de Automóvil">
</body>
</html>)";

    // Unir las partes correctamente
    std::string contenido = parte1 + modelo + parte2 + parte3;

    // Crear y escribir en el archivo TXT
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << contenido;
        archivo.close();
        std::cout << " Archivo TXT '" << nombreArchivo << "' creado exitosamente con el modelo: " << modelo << std::endl;
    } else {
        std::cerr << " Error al crear el archivo: " << nombreArchivo << std::endl;
    }
}

Coche::Coche()
{
    this->placa = "";
    this->marca = "";
    this->modelo = "";
    this->color = "";
}

Coche::Coche(string placa, string modelo, string color, string marca, int anio, Propietario propietario)
    : placa(placa), modelo(modelo), color(color), marca(marca), anio(anio), propietario(propietario), horaIngreso(chrono::system_clock::now()) {}

Coche::Coche(string placa, string modelo, string color, string marca,
             chrono::system_clock::time_point horaIngreso, chrono::system_clock::time_point horaSalida, Propietario propietario)
    : placa(placa), modelo(modelo), color(color), marca(marca), anio(0), horaIngreso(horaIngreso), horaSalida(horaSalida), propietario(propietario) {}

Coche::Coche(string placa, string modelo, string color, string marca, int anio, Propietario propietario, int posicion)
    : placa(placa), modelo(modelo), color(color), marca(marca), anio(anio), propietario(propietario), posicion(posicion), horaIngreso(chrono::system_clock::now()) {}



void Coche::setHoraSalida(chrono::system_clock::time_point hora)
{
    horaSalida = hora;
}

void Coche::setPlaca(const string &placa)
{
    this->placa = placa;
}

void Coche::setModelo(const string &modelo)
{
    this->modelo = modelo;
}

void Coche::setMarca(const string &marca)
{
    this->marca = marca;
}

void Coche::setColor(const string &color)
{
    this->color = color;
}

chrono::system_clock::time_point Coche::getHoraSalida() const
{
    return horaSalida;
}

string Coche::getPlaca() const
{
    return placa;
}

string Coche::getMarca() const
{
    return marca;
}

string Coche::getModelo() const
{
    return modelo;
}

string Coche::getColor() const
{
    return color;
}

int Coche::getAnio() const
{
    return anio;
}

chrono::system_clock::time_point Coche::getHora() const
{
    return horaIngreso;
}

int Coche::getPosicion() const {
    return posicion;
}


ostream &operator<<(ostream &os, const Coche &coche)
{
    os << "Placa: " << coche.placa << "\nMarca: " << coche.marca
       << "\nModelo: " << coche.modelo << "\nColor: " << coche.color
       << "\n----------------------------------------" << endl;

    time_t tiempoIngreso = chrono::system_clock::to_time_t(coche.horaIngreso);
    os << "\nHora de Ingreso: " << ctime(&tiempoIngreso)
       << "\n----------------------------------------" << endl;

    if (coche.horaSalida == chrono::system_clock::time_point())
    {
        os << "\nHora de Salida: N/A" << endl;
    }
    else
    {
        time_t tiempoSalida = chrono::system_clock::to_time_t(coche.horaSalida);
        os << "\nHora de Salida: " << ctime(&tiempoSalida)
           << "\n----------------------------------------" << endl;
    }

    return os;
}


Coche Coche::InsertarDatos(ListaCircularDoble<Coche> &lista, ListaCircularDoble<Coche> &listaHistorial, ListaPropietarios &listaPropietarios)
{
    Validaciones validaciones;
    Placa<Coche> validador;

    string placa, modelo, color, marca;
    int anio = 0;
    Propietario* propietario = nullptr;

    while (true)
    {
        placa = validador.ingresarPlaca(lista.getPrimero());
        
        Nodo<Coche> *temp = lista.getPrimero();
        bool placaDuplicada = false;

        if (temp != nullptr)
        {
            do
            {
                Coche cocheActual = temp->getDato();

                if (cocheActual.getPlaca() == placa && cocheActual.getHoraSalida() == chrono::system_clock::time_point())
                {
                    cout << "\nEl coche con la placa " << placa << " ya esta en el parqueadero. Ingrese una placa nueva." << endl;
                    placaDuplicada = true;
                    break;
                }

                temp = temp->getSiguiente();
            } while (temp != lista.getPrimero());
        }

        if (!placaDuplicada)
        {
            break;
        }
    }

    Nodo<Coche> *tempHistorial = listaHistorial.getPrimero();
    if (tempHistorial != nullptr)
    {
        do
        {
            Coche cocheHistorial = tempHistorial->getDato();

            if (cocheHistorial.getPlaca() == placa)
            {
                cout << "\nLa placa " << placa << " fue encontrada en el historial. Recuperando datos..." << endl;
                modelo = cocheHistorial.getModelo();
                color = cocheHistorial.getColor();
                marca = cocheHistorial.getMarca();

                cout << "Marca: " << marca << "\nColor: " << color << "\nModelo: " << modelo << "\n";
                string foto = "Auto.html";
                string automovil = modelo + " " + color;
                mostrar_auto_imagen(foto, automovil);
                string comando = "start " + foto;
                system(comando.c_str());
                vector<string> opciones = {"Si", "No"};
                int seleccion = menuInteractivo(opciones, "Auto encontrado en el sistema.\n¿Desea sobreescribir los datos del historial?");

                if (seleccion == 0) 
                {
                    system("cls");
                    cout << "========================================" << endl;
                    cout << "        Datos Recuperados Exitosamente  " << endl;
                    cout << "========================================" << endl;
                    cout << "\nMarca:    " << marca << endl;
                    cout << "Modelo:   " << modelo << endl;
                    cout << "Color:    " << color << endl;
                    cout << "Placa:    " << placa << endl;

                    do {
                        string cedula;
                        do
                        {
                            cedula = validaciones.ingresarCedula("Ingrese la cedula del propietario: ");
                            if (!validaciones.validarCedula(cedula))
                            {
                                cout << "Cedula invalida. Intente de nuevo." << endl;
                            }
                        } while (!validaciones.validarCedula(cedula));

                        propietario = listaPropietarios.buscarPropietarioPorCedula(cedula);
                        if (propietario != nullptr) {
                            propietario->agregarPlaca(placa);
                            cout << "Placa asociada exitosamente al propietario." << endl;
                            string foto = "Auto.html";
                            string automovil = modelo + " " + color;
                            mostrar_auto_imagen(foto, automovil);
                            string comando = "start " + foto;
                            system(comando.c_str());
                            listaPropietarios.guardarArchivo("propietarios.txt");
                            break;
                        } else {
                            cout << "Propietario no encontrado. Intente de nuevo." << endl;
                        }
                    } while (true);

                    return Coche(placa, modelo, color, marca, anio, *propietario);
                }
                else 
                {
                    system("cls");
                    cout << "\nPor favor, ingrese los datos manualmente:" << endl;
                    break;
                }
            }

            tempHistorial = tempHistorial->getSiguiente();
        } while (tempHistorial != listaHistorial.getPrimero());
    }

    marca = validaciones.ingresarString("Ingrese la marca: ");
    color = validaciones.ingresarString("Ingrese el color: ");
    modelo = validaciones.ingresarString("Ingrese el modelo: ");

    do {
        string cedula;
         do
        {
            cedula = validaciones.ingresarCedula("Ingrese la cedula del propietario: ");
            if (!validaciones.validarCedula(cedula))
            {
                cout << "Cedula invalida. Intente de nuevo." << endl;
            }
        } while (!validaciones.validarCedula(cedula));

        propietario = listaPropietarios.buscarPropietarioPorCedula(cedula);
        if (propietario != nullptr) {
            propietario->agregarPlaca(placa);
            string foto = "Auto.html";
            string automovil = modelo + " " + color;
            cout << "Placa asociada exitosamente al propietario." << endl;
            mostrar_auto_imagen(foto, automovil);
            listaPropietarios.guardarArchivo("propietarios.txt");
            string comando = "start " + foto;
            system(comando.c_str());
            break;
        } else {
            cout << "Propietario no encontrado. Intente de nuevo." << endl;
        }
    } while (true);

    return Coche(placa, modelo, color, marca, anio, *propietario);
}

Propietario Coche::getPropietario() const {
    return propietario;
}



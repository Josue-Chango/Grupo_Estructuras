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
#include <fstream>

using namespace std;


const int TOTAL_PUESTOS = 20;  // Puedes ajustar este número según la capacidad del parqueadero
bool puestos[TOTAL_PUESTOS] = {false}; 

//  Función para guardar el estado de los puestos
void guardarEstadoPuestos() {
    ofstream archivo("puestos.txt");
    for (int i = 0; i < TOTAL_PUESTOS; i++) {
        archivo << puestos[i] << endl;
    }
    archivo.close();
}

//  Función para cargar el estado de los puestos
void cargarEstadoPuestos() {
    ifstream archivo("puestos.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < TOTAL_PUESTOS && !archivo.eof(); i++) {
            archivo >> puestos[i];
        }
        archivo.close();
    }
}

void liberarPuesto(int puesto) {
    if (puesto > 0 && puesto <= TOTAL_PUESTOS) {
        puestos[puesto - 1] = false;  // Marcar el puesto como libre
        std::cout << "El puesto " << puesto << " ha sido liberado." << endl;
    } else {
        std::cout << "Número de puesto inválido." << endl;
    }
}

void Coche::generarCodigoQR(const string& datos) {
    string apiUrl = "https://api.qrserver.com/v1/create-qr-code/?size=200x200&data=" + datos;
    string outputFile = "codigoQR.png";

    string command = "curl -o " + outputFile + " \"" + apiUrl + "\"";

    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "✅ Código QR generado y guardado en " << outputFile << endl;
        system(("start " + outputFile).c_str()); // Abrir en Windows
    } else {
        std::cout << "❌ Error al generar el código QR." << endl;
    }
}

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

void Coche::setPuesto(int p) {
    posicion = p;
}

int Coche::getPuesto() const {
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
    int anio = 0, puestoAsignado = -1;
    Propietario* propietario = nullptr;

    cargarEstadoPuestos();

    // Asignar el primer puesto disponible
    for (int i = 0; i < TOTAL_PUESTOS; i++) {
        if (!puestos[i]) {  // Si el puesto está libre
            puestos[i] = true;  // Marcar como ocupado
            puestoAsignado = i + 1;  // Los puestos comienzan desde 1
            break;
        }
    }

    if (puestoAsignado == -1) {
        std::cout << "No hay puestos disponibles en el parqueadero." << endl;
        return Coche();  // Retornar un coche vacío si no hay espacio
    }

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
                    std::cout << "\nEl coche con la placa " << placa << " ya esta en el parqueadero. Ingrese una placa nueva." << endl;
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
                std::cout << "\nLa placa " << placa << " fue encontrada en el historial. Recuperando datos..." << endl;
                modelo = cocheHistorial.getModelo();
                color = cocheHistorial.getColor();
                marca = cocheHistorial.getMarca();

                std::cout << "Marca: " << marca << "\nColor: " << color << "\nModelo: " << modelo << "\n";
                string foto = "Auto.html";
                string automovil = marca + " " + modelo + " " + color;
                mostrar_auto_imagen(foto, automovil);
                string comando = "start " + foto;
                generarCodigoQR(placa);
                system(comando.c_str());
                vector<string> opciones = {"Si", "No"};
                int seleccion = menuInteractivo(opciones, "Auto encontrado en el sistema.\n¿Desea sobreescribir los datos del historial?");

                if (seleccion == 0) 
                {
                    system("cls");
                    std::cout << "========================================" << endl;
                    std::cout << "        Datos Recuperados Exitosamente  " << endl;
                    std::cout << "========================================" << endl;
                    std::cout << "\nMarca:    " << marca << endl;
                    std::cout << "Modelo:   " << modelo << endl;
                    std::cout << "Color:    " << color << endl;
                    std::cout << "Placa:    " << placa << endl;

                    do {
                        string cedula;
                        do
                        {
                            cedula = validaciones.ingresarCedula("Ingrese la cedula del propietario: ");
                            if (!validaciones.validarCedula(cedula))
                            {
                                std::cout << "Cedula invalida. Intente de nuevo." << endl;
                            }
                        } while (!validaciones.validarCedula(cedula));

                        propietario = listaPropietarios.buscarPropietarioPorCedula(cedula);
                        if (propietario != nullptr) {
                            propietario->agregarPlaca(placa);
                            std::cout << "Placa asociada exitosamente al propietario." << endl;
                            listaPropietarios.guardarArchivo("propietarios.txt");
                            guardarEstadoPuestos();
                            break;
                        } else {
                            std::cout << "Propietario no encontrado. Intente de nuevo." << endl;
                        }
                    } while (true);

                    return Coche(placa, modelo, color, marca, anio, *propietario, puestoAsignado);
                }
                else 
                {
                    system("cls");
                    std::cout << "\nPor favor, ingrese los datos manualmente:" << endl;
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
                std::cout << "Cedula invalida. Intente de nuevo." << endl;
            }
        } while (!validaciones.validarCedula(cedula));

        propietario = listaPropietarios.buscarPropietarioPorCedula(cedula);
        if (propietario != nullptr) {
            propietario->agregarPlaca(placa);
            listaPropietarios.guardarArchivo("propietarios.txt");
            std::cout << "Placa asociada exitosamente al propietario." << endl;
            break;
        } else {
            std::cout << "Propietario no encontrado. Intente de nuevo." << endl;
        }
    } while (true);

    std::cout << "Coche ingresado exitosamente en el puesto: " << puestoAsignado << endl;
    guardarEstadoPuestos();
    return Coche(placa, modelo, color, marca, anio, *propietario, puestoAsignado);
}


Propietario Coche::getPropietario() const {
    return propietario;
}




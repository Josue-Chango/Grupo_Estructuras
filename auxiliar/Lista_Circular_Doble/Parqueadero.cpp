#include "Parqueadero.h"

// Constructor
Parqueadero::Parqueadero(int filas, int columnas) : filas(filas), columnas(columnas) {
    espacios.resize(filas, std::vector<char>(columnas, 'O')); // Todos los espacios están libres inicialmente
}

// Muestra el parqueadero en consola
void Parqueadero::mostrarParqueadero() {
    for (const auto& fila : espacios) {
        for (const auto& espacio : fila) {
            std::cout << "[" << espacio << "]";
        }
        std::cout << std::endl;
    }
}

// Ingresa un vehículo al parqueadero
bool Parqueadero::ingresarVehiculo(const std::string& placa, const std::string& nombre1, const std::string& nombre2, const std::string& apellido, const std::string& cedula, const std::string& correo) {
    // Buscar un espacio libre
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (espacios[i][j] == 'O') {
                espacios[i][j] = 'X'; // Marcar espacio como ocupado
                listaVehiculos.insertar_persona(nombre1, nombre2, apellido, cedula, correo, placa); // Guardar información en la lista
                std::cout << "Vehiculo ingresado en posicion [" << i << ", " << j << "]\n";
                return true;
            }
        }
    }
    std::cout << "No hay espacios disponibles en el parqueadero.\n";
    return false;
}

// Retira un vehículo del parqueadero
bool Parqueadero::retirarVehiculo(const std::string& placa) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (espacios[i][j] == 'X') {
                if (listaVehiculos.buscar(placa)) { // Verificar si el vehículo está registrado
                    espacios[i][j] = 'O'; // Marcar espacio como libre
                    listaVehiculos.eliminar(placa); // Eliminar vehículo de la lista
                    std::cout << "Vehiculo con placa " << placa << " retirado de posicion [" << i << ", " << j << "]\n";
                    return true;
                }
            }
        }
    }
    std::cout << "Vehiculo con placa " << placa << " no encontrado.\n";
    return false;
}

// Expande el tamaño del parqueadero
void Parqueadero::expandirParqueadero(int nuevasFilas, int nuevasColumnas) {
    if (nuevasFilas <= 0 || nuevasColumnas <= 0) {
        std::cout << "Dimensiones inválidas para expansión.\n";
        return;
    }
    for (int i = 0; i < filas; ++i) {
        espacios[i].resize(columnas + nuevasColumnas, 'O'); // Expandir columnas
    }
    espacios.resize(filas + nuevasFilas, std::vector<char>(columnas + nuevasColumnas, 'O')); // Expandir filas
    filas += nuevasFilas;
    columnas += nuevasColumnas;
    std::cout << "El parqueadero ha sido expandido a " << filas << " filas y " << columnas << " columnas.\n";
}
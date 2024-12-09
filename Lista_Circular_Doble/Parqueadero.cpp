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
void Parqueadero::ingresarVehiculo(const std::string& placa, const std::string& nombre1, const std::string& nombre2, const std::string& apellido, const std::string& cedula, const std::string& correo) {
    // Buscar el primer espacio disponible
    for (int fila = 0; fila < espacios.size(); ++fila) {
        for (int columna = 0; columna < espacios[fila].size(); ++columna) {
            if (espacios[fila][columna] == 'O') { // Si está disponible
                espacios[fila][columna] = 'X'; // Marcarlo como ocupado

                // Llamar a guardarVehiculoEnArchivo pasando los datos
                guardarVehiculoEnArchivo(fila, columna, placa, nombre1, nombre2, apellido, cedula, correo);
                cargarVehiculosDesdeArchivo();
                std::cout << "Vehículo ingresado correctamente en el parqueadero.\n";
                return; // Salir después de guardar el vehículo
            }
        }
    }

    std::cout << "No hay espacios disponibles.\n";
}

// Retira un vehículo del parqueadero
bool Parqueadero::retirarVehiculo(const std::string& placa) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (espacios[i][j] == 'X') {
                if (listaVehiculos.buscar_Placa(placa)) { // Verificar si el vehículo está registrado
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
// Buscar Vehiculo
bool Parqueadero::buscarVehiculo(const std::string& placa) {
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (espacios[i][j] == 'X') { // Espacio ocupado
                if (listaVehiculos.buscar_Placa(placa)) { // Buscar en la lista de vehículos
                    std::cout << "Vehiculo encontrado en la posicion [" << i << ", " << j << "]" << std::endl;
                    return true;
                }
            }
        }
    }
    std::cout << "Vehiculo no encontrado en el parqueadero." << std::endl;
    return false;
}

void Parqueadero::guardarVehiculoEnArchivo(int fila, int columna, const std::string& placa, const std::string& nombre1, const std::string& nombre2, const std::string& apellido, const std::string& cedula, const std::string& correo) {
    std::ofstream archivo("Parqueadero.txt", std::ios::app); // Abrir el archivo en modo append para agregar al final
    if (archivo.is_open()) {
        archivo << fila << " " << columna << " " << placa << " "
                << nombre1 << " " << nombre2 << " " << apellido << " "
                << cedula << " " << correo << "\n";  // Escribir la información del vehículo
        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo para guardar el vehículo\n";
    }
}

void Parqueadero::cargarVehiculosDesdeArchivo() {
    // Reiniciar el estado del parqueadero (matriz de espacios)
    for (auto& fila : espacios) {
        std::fill(fila.begin(), fila.end(), 'O'); // Reinicia todos los espacios como vacíos
    }

    // Abrir el archivo
    std::ifstream archivo("Parqueadero.txt");
    if (archivo.is_open()) {
        int fila, columna;
        std::string placa, nombre1, nombre2, apellido, cedula, correo;

        while (archivo >> fila >> columna >> placa >> nombre1 >> nombre2 >> apellido >> cedula >> correo) {
            if (fila < filas && columna < columnas) {
                // Marcar el espacio como ocupado en la matriz
                espacios[fila][columna] = 'X';

                // Insertar la información del vehículo en la lista circular
                listaVehiculos.insertar_persona(nombre1, nombre2, apellido, cedula, correo, placa);
            } else {
                std::cerr << "Error: posición (" << fila << ", " << columna << ") fuera del rango del parqueadero.\n";
            }
        }
        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo para cargar los vehículos.\n";
    }
}

#include "Parqueadero.h"
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>

Parqueadero::Parqueadero(int totalEspacios, int radio) {
    this->totalEspacios = totalEspacios;
    this->radio = radio;
    
    this->espacios = (bool*)calloc(totalEspacios, sizeof(bool)); 
    if (espacios == nullptr) {
        std::cerr << "Error al asignar memoria." << std::endl;
        exit(1);  
    }
}

Parqueadero::~Parqueadero() {
    free(espacios);
}

void Parqueadero::ocuparEspacio(int espacio) {
if (espacio >= 0 && espacio < totalEspacios) {
        espacios[espacio] = true;  // Marca el espacio como ocupado
        
        int fila = 0;
        int columna = espacio;
        while (columna >= fila + 1) {
            columna -= (fila + 1);
            fila++;
        }
        
        std::cout << "Vehiculo ingresado en la posicion [" << fila << "," << columna << "]" << std::endl;
    }
}

void Parqueadero::liberarEspacio(int espacio) {
    if (espacio >= 0 && espacio < totalEspacios) {
        espacios[espacio] = false;  
    }
}

void Parqueadero::mostrarParqueaderoCircular() {
     const int totalEspacios = this->totalEspacios;

    int nivelesMaximos = 5;  
    int espaciosRestantes = totalEspacios;
    int espaciosPorNivel = 1;  // Comienza con un solo espacio en el primer nivel

    // Dibujar cada nivel
    for (int i = 0; i < nivelesMaximos && espaciosRestantes > 0; ++i) {
        // Imprimir los espacios para el nivel actual
        for (int j = 0; j < espaciosPorNivel && espaciosRestantes > 0; ++j) {
            if (espaciosRestantes > 0) {
                // Verificamos si el espacio está ocupado o libre
                if (espacios[espaciosRestantes - 1]) {
                    printf("[X] ");  // Espacio ocupado
                } else {
                    printf("[O] ");  // Espacio libre
                }
                espaciosRestantes--;
            }
        }

        
        printf("\n");

        
        espaciosPorNivel++;
    }
}

int Parqueadero::getTotalEspacios() {
    return totalEspacios;
}

void Parqueadero::expandirEspacios(int nuevosEspacios) {
    if (nuevosEspacios <= totalEspacios) {
        std::cout << "El numero de nuevos espacios debe ser mayor al actual." << std::endl;
        return;
    }

    bool* nuevosEspaciosArray = (bool*)calloc(nuevosEspacios, sizeof(bool));
    if (nuevosEspaciosArray == nullptr) {
        std::cerr << "Error al asignar memoria para la expansion." << std::endl;
        return;
    }

    
    for (int i = 0; i < totalEspacios; ++i) {
        nuevosEspaciosArray[i] = espacios[i];
    }

    free(espacios);

    espacios = nuevosEspaciosArray;

    totalEspacios = nuevosEspacios;
}
/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo Altamirano     *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          18/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "Menus.cpp"
#include <string>
#include <fstream>
//using byte = unsigned char;
#include <random>
#include <chrono>
#include <iomanip>

// Función para generar una clave de licencia aleatoria
std::string generateLicenseKey() {
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> charDist('A', 'Z');
std::uniform_int_distribution<> numDist(0, 9);

std::string key = "";
std::string license;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            license += static_cast<char>(charDist(gen));
        }
        license += std::to_string(numDist(gen));
        license += "-";
    }
    license.pop_back();
return license;
}

// Función para guardar la clave de licencia en un archivo
void saveLicenseKey() {
std::ofstream file("license.txt");
if (file.is_open()) {
    //std::string filePath = "license.txt";
    for (int i = 0; i < 5; i++) {
        std::string licenseKey = generateLicenseKey();
        //saveLicenseKey(licenseKey);
        file << licenseKey << endl;
    }

file.close();
std::cout << "Clave de licencia guardada en: " << "license.txt" << std::endl;
} else {
std::cerr << "No se pudo abrir el archivo para guardar la clave de licencia." << std::endl;
}
}

// Función para validar una clave de licencia
bool validateLicenseKey(const std::string& key, const std::string& filePath) {
std::ifstream file(filePath);
if (file.is_open()) {
std::string storedKey;
file >> storedKey;
file.close();
return key == storedKey;
} else {
std::cerr << "No se pudo abrir el archivo para validar la clave de licencia." << std::endl;
return false;
}
}

using namespace std;


int main() {
    Menus<int> Menu;
    saveLicenseKey();
    Menu.Menu();
    return 0;
}



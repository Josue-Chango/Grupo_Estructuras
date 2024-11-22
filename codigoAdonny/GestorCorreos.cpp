#include "GestorCorreos.h"
#include <fstream>

GestorCorreos::GestorCorreos() {
    // Constructor vacío para inicializar el objeto
}

string GestorCorreos::generarCorreo(const string& nombre1, const string& nombre2, const string& apellido) {
    auto toLower = [](const string& str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    };

    string baseCorreo = toLower(nombre1.substr(0, 1) + nombre2.substr(0, 1) + apellido);
    string correo = baseCorreo;

    if (conteoCorreo[baseCorreo] > 0) {
        correo += to_string(conteoCorreo[baseCorreo]);
    }

    conteoCorreo[baseCorreo]++;
    correo += "@espe.edu.ec";

    listaCorreos.insert(correo);

    return correo;
}

void GestorCorreos::cargarCorreosExistentes(const string& nombreArchivo) {
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        cerr << "No se pudo abrir el archivo existente. Se creará uno nuevo." << endl;
        return;
    }
    string linea;
    while (getline(archivoEntrada, linea)) {
        size_t pos = linea.find('@');
        if (pos != string::npos) {
            string baseCorreo = linea.substr(0, pos);
            if (!baseCorreo.empty()) {
                char lastChar = baseCorreo.back();
                if (isdigit(baseCorreo.back())) {
                    string base = baseCorreo.substr(0, baseCorreo.find_last_not_of("0123456789") + 1);
                    int numero = stoi(baseCorreo.substr(baseCorreo.find_last_not_of("0123456789") + 1));
                    conteoCorreo[base] = max(conteoCorreo[base], numero + 1);
                }
                else {
                    conteoCorreo[baseCorreo]++;
                }
                listaCorreos.insert(linea);
            }
        }
    }
    archivoEntrada.close();
}


#ifndef GESTORCORREOS_H
#define GESTORCORREOS_H

#include <unordered_map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class GestorCorreos {
private:
    unordered_map<string, int> conteoCorreo;
    set<string> listaCorreos;

public:
    GestorCorreos();
    string generarCorreo(const string& nombre1, const string& nombre2, const string& apellido);
    void cargarCorreosExistentes(const string& nombreArchivo);
};

#endif // GESTORCORREOS_H

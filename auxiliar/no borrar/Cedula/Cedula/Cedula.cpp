#include "Cedula.h"
#include <iostream>
#include <cctype>

Cedula::Cedula() : numero("") {}

Cedula::Cedula(const std::string& numero) : numero(numero) {}

void Cedula::setNumero(const std::string& numero) {
    this->numero = numero;
}

std::string Cedula::getNumero() const {
    return numero;
}

bool Cedula::validarLongitud() const {
    return numero.length() == 10;
}

bool Cedula::validarFormato() const {
    for (char c : numero) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool Cedula::validarRegion() const {
    int region = std::stoi(numero.substr(0, 2));
    return region >= 1 && region <= 24;
}

bool Cedula::validarDigitoVerificador() const {
    int coeficientes[9] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int suma = 0;

    for (int i = 0; i < 9; ++i) {
        int valor = (numero[i] - '0') * coeficientes[i];
        if (valor > 9) {
            valor -= 9;
        }
        suma += valor;
    }

    int digitoVerificador = (10 - (suma % 10)) % 10;
    return digitoVerificador == (numero[9] - '0');
}

bool Cedula::esValida() const {
    return validarLongitud() && validarFormato() && validarRegion() && validarDigitoVerificador();
}

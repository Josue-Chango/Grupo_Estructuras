#ifndef CEDULA_H
#define CEDULA_H

#include <string>

class Cedula {
private:
    std::string numero;

    bool validarLongitud() const;
    bool validarFormato() const;
    bool validarRegion() const;
    bool validarDigitoVerificador() const;

public:
    Cedula();
    Cedula(const std::string& numero);

    void setNumero(const std::string& numero);
    std::string getNumero() const;

    bool esValida() const;
};

#endif // CEDULA_H

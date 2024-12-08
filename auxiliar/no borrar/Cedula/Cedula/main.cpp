#include "Cedula.cpp"
#include <iostream>

int main() {
    std::string inputCedula;
    std::cout << "Ingrese la cedula a validar: ";
    std::cin >> inputCedula;

    Cedula cedula(inputCedula);

    if (cedula.esValida()) {
        std::cout << "La cedula es valida." << std::endl;
        system("pause");
    } else {
        std::cout << "La cedula no es valida." << std::endl;
        system("pause");
    }

    return 0;
}

#ifndef MENUVALIDATION_H
#define MENUVALIDATION_H

#include <iostream>
#include <limits>
#include "Validaciones.h"
Validaciones<int> validar_entero;
Validaciones<std::string> validar_string;
class MenuValidation
{
public:
    
    static void displayMenu()
    {
        system("cls");
        std::cout << "....................................\n";
        std::cout << ".         Tablas Hash              .\n";
        std::cout << "....................................\n";
        std::cout << ". 1. Insertar en tabla de letras   .\n";
        std::cout << ". 2. Insertar en tabla de numeros  .\n";
        std::cout << ". 3. Visualizar tabla de letras    .\n";
        std::cout << ". 4. Visualizar tabla de numeros   .\n";
        std::cout << ". 5. Salir                         .\n";
        std::cout << "....................................\n";
        std::cout << "Elija una opcion (1-5): ";
    }

    static int getMenuOption()
    {
        int option;
        option = validar_entero.ingresar("","entero");
        //std::cin >> option;
        while (option < 1 || option > 5)
        {
            std::cout << "Opcion invalida. Intente nuevamente: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //std::cin >> option;
            option = validar_entero.ingresar("","entero");
        }
        return option;
    }

    static std::string getValue(bool isLetterMode)
    {
        system("cls");
        std::string value;
        if (isLetterMode)
        {
            std::cout << "Ingrese una letra: ";
        }
        else
        {
            std::cout << "Ingrese un numero: ";
        }
        //std::cin >> value;
        value=validar_string.ingresar("","string");
        return value;
    }

    static int getProbingMethod()
    {
        system("cls");
        std::cout << "Seleccione el metodo de sondeo:\n";
        std::cout << "1. Sondeo lineal\n";
        std::cout << "2. Sondeo cuadratico\n";
        std::cout << "3. Hash doble\n";
        std::cout << "Elija una opcion (1-3): ";
        int method;
        //std::cin >> method;
        method=validar_entero.ingresar("","entero");
        while (method < 1 || method > 3)
        {
            std::cout << "Opcion invalida. Intente nuevamente: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //std::cin >> method;
            method=validar_entero.ingresar("","entero");
        }
        std::cout << "Metodo de sondeo seleccionado: " << method << std::endl; // Mensaje de depuración
        return method;
    }

    static bool isPrime(int num)
    {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6)
        {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    static int getTableSize()
    {
        std::cout << "Ingrese el tamano de la tabla hash (se recomienda un numero primo): ";
        int size;
        //std::cin >> size;
        size=validar_entero.ingresar("","entero");
        while (size <= 0 || !isPrime(size))
        {
            std::cout << "Tamano invalido o no es primo. Intente nuevamente: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //std::cin >> size;
            size=validar_entero.ingresar("","entero");
        }
        std::cout << "Tamano de tabla seleccionado: " << size << std::endl; // Mensaje de depuración
        return size;
    }
};

#endif
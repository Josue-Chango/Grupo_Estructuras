// g++ -o hash_table_sfml main.cpp HashTable.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++11

#include "HashTable.h"
//#include "Validaciones.h"
#include "MenuValidation.h"
#include <iostream>

int main()
{
    std::cout << "Iniciando programa..." << std::endl; // Mensaje de depuración

    int tableSize = MenuValidation::getTableSize();
    int probingMethod = MenuValidation::getProbingMethod();
    HashTable letterTable(true, probingMethod, tableSize);  // Tabla para letras
    HashTable numberTable(false, probingMethod, tableSize); // Tabla para números
    int option;
    //Validaciones<int> validar;

    do
    {
        MenuValidation::displayMenu();
        option = MenuValidation::getMenuOption();

        switch (option)
        {
        case 1:
        {
            std::string value = MenuValidation::getValue(true);
            letterTable.insert(value);
            system("pause");
            break;
        }
        case 2:
        {
            std::string value = MenuValidation::getValue(false);
            numberTable.insert(value);
            system("pause");
            break;
        }
        case 3:
            letterTable.visualize();
            system("pause");
            break;
        case 4:
            numberTable.visualize();
            system("pause");
            break;
        case 5:
            std::cout << "Saliendo del programa..." << std::endl; // Mensaje de depuración
            system("pause");
            return 0;
        }
    } while (true);

    return 0;
}

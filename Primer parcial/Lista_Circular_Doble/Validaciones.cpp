/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          18/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "Validaciones.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>

using namespace std;

template <typename T>
Validaciones<T>::Validaciones()
{
}
/*
template <typename T>
T Validaciones<T>::ingresar(char *msj, char *tipo)
{
    char cad[20];
    char c;
    int i = 0;
    T valor;
    printf("%s", msj);
    while ((c = getch()) != 13)
    {
        if (tipo == "entero" || tipo == "cedula")
        {
            if (c >= '0' && c <= '9')
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "flotante" || tipo == "double")
        {
            if (c >= '0' && c <= '9')
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
            else if (c == 46)
            {
                bool aux = false;
                for (int j = 0; cad[j] != '\0'; j++)
                {
                    if (cad[j] == 46)
                    {
                        aux = true;
                        break;
                    }
                }
                if (aux == false)
                {
                    printf("%c", c);
                    cad[i++] = c;
                }
            }
        }
        else if (tipo == "string")
        {
            if (isalpha(c) || c==32)
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "char")
        {
            if (isalpha(c))
            {
                printf("%c", c);
                valor = c;
                break;
            }
            else if (c == 8)
            {
                if (c >= 'a' && c <= 'z')
                {
                    printf("\b \b");
                }
            }
        }
    }
    cad[i] = '\0';
    if (tipo == "entero")
    {
        int entero;
        entero = atoi(cad);
        return valor = entero;
    }
    else if (tipo == "flotante")
    {
        float flotante;
        for (int j = 0; cad[j] != '\0'; j++)
        {
            flotante = atof(cad);
        }
        return valor = flotante;
    }
    else if (tipo == "double")
    {
        double doble;
        for (int j = 0; cad[j] != '\0'; j++)
        {
            doble = (double)atof(cad);
        }
        return valor = doble;
    }
    else if (tipo == "char")
    {
        return valor;
    }
    else if (tipo == "string" || tipo == "cedula")
    {
        for (int j = 0; cad[j] != '\0'; j++)
        {
            valor = valor + cad[j];
        }
        return valor;
    }
}*/

template <typename T>
T Validaciones<T>::ingresar(char *msj, char *tipo)
{
    char cad[20];
    char c;
    int i = 0;
    T valor;
    printf("%s", msj);
    while ((c = getch()) != 13)
    {
        if (tipo == "entero" || tipo == "cedula")
        {
            if (c >= '0' && c <= '9')
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "flotante" || tipo == "double")
        {
            if (c >= '0' && c <= '9')
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
            else if (c == 46)
            {
                bool aux = false;
                for (int j = 0; cad[j] != '\0'; j++)
                {
                    if (cad[j] == 46)
                    {
                        aux = true;
                        break;
                    }
                }
                if (aux == false)
                {
                    printf("%c", c);
                    cad[i++] = c;
                }
            }
        }
        else if (tipo == "string")
        {
            if (i == 0 && c == 32) // Validar si es el primer carácter y es un espacio
            {
                // No hacer nada, no permitir el espacio en la primera posición
            }
            else if (isalpha(c) || c == 32)
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "char")
        {
            if (isalpha(c))
            {
                printf("%c", c);
                valor = c;
                break;
            }
            else if (c == 8)
            {
                if (c >= 'a' && c <= 'z')
                {
                    printf("\b \b");
                }
            }
        }else if (tipo == "hora")
        {
            int contador = 0;
            if (c >= '0' && c <= '9')
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                    contador = 0;
                }
            }
            else if (c == 58)
            {
                    printf("%c", c);
                    cad[i++] = c;
            }
        }

    }
    cad[i] = '\0';
    if (tipo == "entero")
    {
        int entero;
        entero = atoi(cad);
        return valor = entero;
    }
    else if (tipo == "flotante")
    {
        float flotante;
        for (int j = 0; cad[j] != '\0'; j++)
        {
            flotante = atof(cad);
        }
        return valor = flotante;
    }
    else if (tipo == "double")
    {
        double doble;
        for (int j = 0; cad[j] != '\0'; j++)
        {
            doble = (double)atof(cad);
        }
        return valor = doble;
    }
    else if (tipo == "char")
    {
        return valor;
    }
    else if (tipo == "string" || tipo == "cedula" )
    {
        for (int j = 0; cad[j] != '\0'; j++)
        {
            valor = valor + cad[j];
        }
        return valor;
    }
    else if (tipo == "hora")
    {
        //std::string hora;
        for (int j = 0; cad[j] != '\0'; j++)
        {
            valor+=cad[j];
        }
        return valor;
    }
}

template <typename T>
bool Validaciones<T>::validarLongitud(string _cedula)  {
    return _cedula.length() == 10;
}

template <typename T>
bool Validaciones<T>::validarFormato(string _cedula)  {
    for (char c : _cedula) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Validaciones<T>::validarRegion(string _cedula)  {
    int region = std::stoi(_cedula.substr(0, 2));
    return region >= 1 && region <= 24;
}

template <typename T>
bool Validaciones<T>::validarDigitoVerificador(string _cedula)  {
    int coeficientes[9] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int suma = 0;

    for (int i = 0; i < 9; ++i) {
        int valor = (_cedula[i] - '0') * coeficientes[i];
        if (valor > 9) {
            valor -= 9;
        }
        suma += valor;
    }

    int digitoVerificador = (10 - (suma % 10)) % 10;
    return digitoVerificador == (_cedula[9] - '0');
}

template <typename T>
bool Validaciones<T>::esValida(string _cedula)  {
    return validarLongitud(_cedula) && validarFormato(_cedula) && validarRegion(_cedula) && validarDigitoVerificador(_cedula);
}

template <typename T>
T Validaciones<T>::Ingresar_Cedula()
{
    string aux;
    do {
        system("cls");
        aux = ingresar("Ingrese su cedula: ", "cedula");

        if(esValida(aux) == false){
            cout << endl << "Cedula no valida" << endl << "Ingrese una cedula valida" << endl;
            system("pause");
        }
    }while(esValida(aux) == false);

    return aux;
}

template <typename T>
T Validaciones<T>::Ingresar_Placa() {
    T placa;
    bool es_valida = false;

    do {
        std::cout << "Ingrese la placa del vehiculo o motocicleta (formato: ABC-1234 o XX-123A): ";
        std::cin >> placa;
        std::string placa_str = placa;
        es_valida = true;

        if (placa_str.length() != 8 && placa_str.length() != 7) {
            es_valida = false;
        } else if (placa_str.length() == 8) {
            // Validar formato de vehículo (ABC-1234)
            for (int i = 0; i < 3; i++) {
                // Verificar que las primeras letras no sean Ñ, Q, D o F
                if (!std::isalpha(placa_str[i]) || !std::isupper(placa_str[i]) || 
                    placa_str[i] == 'Ñ' || placa_str[i] == 'Q' || placa_str[i] == 'D' || placa_str[i] == 'F') {
                    es_valida = false;
                    break;
                }
            }
            if (placa_str[3] != '-') es_valida = false;
            for (int i = 4; i < 8; i++) {
                if (!std::isdigit(placa_str[i])) {
                    es_valida = false;
                    break;
                }
            }
        } else if (placa_str.length() == 7) {
            // Validar formato de motocicleta (XX-123A)
            for (int i = 0; i < 2; i++) {
                // Verificar que las primeras letras no sean Ñ, Q, D o F
                if (!std::isalpha(placa_str[i]) || !std::isupper(placa_str[i]) || 
                    placa_str[i] == 'Ñ' || placa_str[i] == 'Q' || placa_str[i] == 'D' || placa_str[i] == 'F') {
                    es_valida = false;
                    break;
                }
            }
            if (placa_str[2] != '-') es_valida = false;
            for (int i = 3; i < 6; i++) {
                if (!std::isdigit(placa_str[i])) {
                    es_valida = false;
                    break;
                }
            }
            // Verificar que la última letra también sea válida
            if (!std::isalpha(placa_str[6]) || !std::isupper(placa_str[6]) || 
                placa_str[6] == 'Ñ' || placa_str[6] == 'Q' || placa_str[6] == 'D' || placa_str[6] == 'F') {
                es_valida = false;
            }
        } else {
            es_valida = false;
        }
        if (!es_valida) {
            std::cout << "Formato invalido o contiene letras no permitidas en el inicio. Intente nuevamente." << std::endl;
        }
    } while (!es_valida);

    return placa;
}
/*
template <typename T>
bool Validaciones<T>::Validar_Hora(std::string _hora) {
    char* auxiliar =new char[_hora.length()];
    int hms;
    strcpy(auxiliar, _hora.c_str());
    for(int i = 0;i<=_hora.length();i++){
        if (*(auxiliar+0) >= 0  && *(auxiliar+0) <= 2){
            //hms = to_integer(*(auxiliar+0)) + to_integer(*(auxiliar+1));
            return false;
        }else {
            cout << "La hora ingresada es incorrecta" << endl;
            return false;
            break;
        }
    }
    return true;
}*/

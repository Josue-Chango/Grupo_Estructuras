#include "Calculadora_Polaca.h"
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <map>
#include <cstring>
using namespace std;

template <typename T>
Calculadora_Polaca<T>::Calculadora_Polaca()
{
}

template <typename T>
T Calculadora_Polaca<T>::infija_a_prefija(T _expresion)
{
    _expresion = "(" + _expresion + ")";
    int validar1 = 0, validar2 = 0;
    string resultado = "", cadena = "";
    string resultado2 = "";
    string cadena2 = "";
    char* auxiliar = new char[_expresion.length() - 1];
    char* operadores = new char[1];
    //char* numeros = new char[1];
    for (int i = _expresion.length() - 1; i >= 0; i--) {
        cadena += _expresion[i];
    }
    std::strcpy(auxiliar, cadena.c_str());

    for (int i = 0; i <= _expresion.length() - 1; ++i) {
        if (*(auxiliar+i) == 40) {
            validar1++;
        }
        if (*(auxiliar+i) == 41) {
            validar2++;
        }
    }
    if (validar1 == validar2){
        validar1 = 0;
        validar2 = 0;
        for(int i = 0 ; i <= _expresion.length() - 1 ; i++){
            if (isdigit(*(auxiliar+i))){

                resultado = resultado + *(auxiliar+i);

            }else if(*(auxiliar+i) == 41 || *(auxiliar+i) == 47 || *(auxiliar+i) == 43 ||*(auxiliar+i) == 45 || *(auxiliar+i) == 42) {
                
                *(operadores+validar1) = *(auxiliar+i);

                validar1++;
            }else if(*(auxiliar+i) == 40){
                //*(auxiliar+i) = " ";
                int j = validar1-1;
                do{
                    resultado = resultado + *(operadores+j);
                    j--;
                }while(*(operadores+j) != 41);
                for (j; j <= validar1-1; j++){
                    *(operadores+j)= NULL;
                }
                
            }
        }
        //cout << endl << resultado << endl;
        char* cadena_final = new char[resultado.length()];
        for (int i = resultado.length(); i >= 0; i--) {
            cadena2 += resultado[i];
            
        }/*
        std::strcpy(cadena_final, cadena2.c_str());
        
        for (int j = 0; j<=resultado.length(); j++){
            resultado2 += resultado + *(cadena_final+j);
        }*/
    }else{
        cout << endl << "Se ha detectado un error sintactico" << endl;
    }
    delete[] auxiliar;
    delete[] operadores;
    return cadena2;
}

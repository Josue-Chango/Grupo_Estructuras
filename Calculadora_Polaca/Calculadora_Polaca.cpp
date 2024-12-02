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
/*
template <typename T>
T Calculadora_Polaca<T>::infija_a_sufija(T &expresionInfija)
{
    // Precedencia de operadores
    map<char, int> precedencia;
    precedencia['*'] = 3;
    precedencia['/'] = 3;
    precedencia['+'] = 2;
    precedencia['-'] = 2;
    precedencia['('] = 1;

    stack<char> pilaOperadores; // Pila para los operadores
    vector<std::string> listaSufija; // Vector para almacenar la expresión sufija
    std::stringstream ss(expresionInfija);
    std::string simbolo;

    // Separar los símbolos de la expresión infija
    while (ss >> simbolo) {
        // Si es un operando (letra o número)
        if (isalnum(simbolo[0])) {
            listaSufija.push_back(simbolo);
        }
        // Si es un paréntesis izquierdo
        else if (simbolo == "(") {
            pilaOperadores.push('(');
        }
        // Si es un paréntesis derecho
        else if (simbolo == ")") {
            while (!pilaOperadores.empty() && pilaOperadores.top() != '(') {
                listaSufija.push_back(std::string(1, pilaOperadores.top()));
                pilaOperadores.pop();
            }
            pilaOperadores.pop(); // Quitar el '(' de la pila
        }
        // Si es un operador
        else {
            char op = simbolo[0];
            while (!pilaOperadores.empty() &&
                   precedencia[pilaOperadores.top()] >= precedencia[op]) {
                listaSufija.push_back(std::string(1, pilaOperadores.top()));
                pilaOperadores.pop();
            }
            pilaOperadores.push(op);
        }
    }

    // Sacar los operadores restantes de la pila
    while (!pilaOperadores.empty()) {
        listaSufija.push_back(std::string(1, pilaOperadores.top()));
        pilaOperadores.pop();
    }

    // Combinar los elementos de la lista sufija en una sola cadena
    std::string resultado;
    for (const std::string& elemento : listaSufija) {
        if (!resultado.empty()) resultado += " ";
        resultado += elemento;
    }

    return resultado;
}*/

template <typename T>
T Calculadora_Polaca<T>::infija_a_prefija(T expresion)
{
    expresion = "(" + expresion + ")";
    int validar1 = 0, validar2 = 0;
    string resultado = "", cadena = "";
    char* auxiliar = new char[expresion.length() - 1];
    char* operadores = new char[1];
    //char* numeros = new char[1];
    for (int i = expresion.length() - 1; i >= 0; i--) {
        cadena += expresion[i];
    }
    std::strcpy(auxiliar, cadena.c_str());

    for (int i = 0; i <= expresion.length() - 1; ++i) {
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
        for(int i = 0 ; i <= expresion.length() - 1 ; i++){
            if (isdigit(*(auxiliar+i))){

                resultado = resultado + *(auxiliar+i);

            }else if(*(auxiliar+i) == 41 || *(auxiliar+i) == 47 || *(auxiliar+i) == 43 ||*(auxiliar+i) == 45 || *(auxiliar+i) == 42) {
                
                *(operadores+validar1) = *(auxiliar+i);

                validar1++;
            }else if(*(auxiliar+i) == 40){
                //*(auxiliar+i) = " ";
                int retroceso = 0;
                int j = validar1-1;
                do{
                    resultado = resultado + *(operadores+j);
                    j--;
                }while(*(operadores+j) != 41);
                *(operadores+j)= NULL;
            }
        }
    }else{
        cout << endl << "Se ha detectado un error sintactico" << endl;
    }

    return resultado;
}
/*
template <typename T>
int Calculadora_Polaca<T>::precedencia(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}



template <typename T>
T Calculadora_Polaca<T>::infija_a_prefija(T expresion) {
    // Agregar paréntesis al inicio y al final de la expresión
    expresion = "(" + expresion + ")";

    // Invertir la expresión
    string expresion_invertida = "";
    for (int i = expresion.length() - 1; i >= 0; i--) {
        expresion_invertida += expresion[i];
    }

    // Reordenar la expresión en notación polaca inversa
    stack<char> pila;
    string resultado = "";
    for (char c : expresion_invertida) {
        if (isdigit(c)) {
            resultado += c;
        } else if (c == ')') {
            pila.push(c);
        } else if (c == '(') {
            while (!pila.empty() && pila.top() != ')') {
                resultado += pila.top();
                pila.pop();
            }
            if (!pila.empty()) {
                pila.pop(); // Eliminar el paréntesis de cierre
            }
        } else { // Operador
            while (!pila.empty() && precedencia(c) <= precedencia(pila.top())) {
                resultado += pila.top();
                pila.pop();
            }
            pila.push(c);
        }
    }
    while (!pila.empty()) {
        resultado += pila.top();
        pila.pop();
    }

    return resultado;
}

// Función auxiliar para determinar la precedencia de los operadores

*/


#include "Calculadora_Polaca.h"
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

template <typename T>
Calculadora_Polaca<T>::Calculadora_Polaca() {}

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

template <typename T>
T Calculadora_Polaca<T>::infija_a_prefija(T expresion) {
    stack<string> operadores; 
    stack<string> operandos; 
    string numero;

    for (size_t i = 0; i < expresion.length(); i++) {
        char ch = expresion[i];

        if (isdigit(ch)) {
            
            numero += ch;
            
            if (i == expresion.length() - 1 || !isdigit(expresion[i + 1])) {
                operandos.push(numero);
                numero.clear();
            }
        } else if (ch == '(') {
            operadores.push(string(1, ch)); 
        } else if (ch == ')') {
           
            while (!operadores.empty() && operadores.top() != "(") {
                string op1 = operandos.top(); operandos.pop();
                string op2 = operandos.top(); operandos.pop();
                string op = operadores.top(); operadores.pop();
                operandos.push(op + " " + op2 + " " + op1);
            }
            operadores.pop(); 
        } else {
            while (!operadores.empty() && precedencia(operadores.top()[0]) > precedencia(ch)) {
                string op1 = operandos.top(); operandos.pop();
                string op2 = operandos.top(); operandos.pop();
                string op = operadores.top(); operadores.pop();
                operandos.push(op + " " + op2 + " " + op1);
            }
            operadores.push(string(1, ch));
        }
    }

    while (!operadores.empty()) {
        string op1 = operandos.top(); operandos.pop();
        string op2 = operandos.top(); operandos.pop();
        string op = operadores.top(); operadores.pop();
        operandos.push(op + " " + op2 + " " + op1);
    }

    
    return operandos.top();
}


template <typename T>
T Calculadora_Polaca<T>::evaluar_postfija(T expresion) {
    stack<char> operadores;   // Pila para operadores
    stack<string> operandos;  // Pila para operandos (postfija)
    string numero;

    for (size_t i = 0; i < expresion.length(); i++) {
        char ch = expresion[i];

        if (isdigit(ch)) {
            // Construir el número completo
            numero += ch;

            // Si es el último carácter o el siguiente no es un dígito, empujar el número completo
            if (i == expresion.length() - 1 || !isdigit(expresion[i + 1])) {
                operandos.push(numero);
                numero.clear();
            }
        } else if (ch == '(') {
            // Empujar paréntesis de apertura
            operadores.push(ch);
        } else if (ch == ')') {
            // Resolver hasta encontrar '('
            while (!operadores.empty() && operadores.top() != '(') {
                string op2 = operandos.top(); operandos.pop();
                string op1 = operandos.top(); operandos.pop();
                char op = operadores.top(); operadores.pop();
                operandos.push(op1 + op2 + op);
            }
            operadores.pop(); // Eliminar '('
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Resolver operadores de mayor precedencia antes de empujar el nuevo operador
            while (!operadores.empty() && precedencia(operadores.top()) >= precedencia(ch)) {
                string op2 = operandos.top(); operandos.pop();
                string op1 = operandos.top(); operandos.pop();
                char op = operadores.top(); operadores.pop();
                operandos.push(op1 + op2 + op);
            }
            operadores.push(ch);
        }
    }

    // Resolver los operadores restantes en la pila
    while (!operadores.empty()) {
        string op2 = operandos.top(); operandos.pop();
        string op1 = operandos.top(); operandos.pop();
        char op = operadores.top(); operadores.pop();
        operandos.push(op1 + op2 + op);
    }

    // El resultado final está en la cima de la pila
    return operandos.top();
}










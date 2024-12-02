#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <map>
#include "Validaciones.cpp"
using namespace std;

// Función para convertir una expresión infija a sufija
string infija_a_sufija(const string& expresionInfija) {
    // Precedencia de operadores
    map<char, int> precedencia;
    precedencia['*'] = 3;
    precedencia['/'] = 3;
    precedencia['+'] = 2;
    precedencia['-'] = 2;
    precedencia['('] = 1;

    stack<char> pilaOperadores; // Pila para los operadores
    vector<string> listaSufija; // Vector para almacenar la expresión sufija
    stringstream ss(expresionInfija);
    string simbolo;

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
                listaSufija.push_back(string(1, pilaOperadores.top()));
                pilaOperadores.pop();
            }
            pilaOperadores.pop(); // Quitar el '(' de la pila
        }
        // Si es un operador
        else {
            char op = simbolo[0];
            while (!pilaOperadores.empty() &&
                   precedencia[pilaOperadores.top()] >= precedencia[op]) {
                listaSufija.push_back(string(1, pilaOperadores.top()));
                pilaOperadores.pop();
            }
            pilaOperadores.push(op);
        }
    }

    // Sacar los operadores restantes de la pila
    while (!pilaOperadores.empty()) {
        listaSufija.push_back(string(1, pilaOperadores.top()));
        pilaOperadores.pop();
    }

    // Combinar los elementos de la lista sufija en una sola cadena
    string resultado;
    for (const string& elemento : listaSufija) {
        if (!resultado.empty()) resultado += " ";
        resultado += elemento;
    }

    return resultado;
}

int main() {
    Validaciones<string> ingreso_operacion;
    string expresion = "A * B + C * D", operacion;
    cout << "Expresión infija: " << expresion << endl;
    cout << "Expresión sufija: " << infija_a_sufija(expresion) << endl;

    operacion = ingreso_operacion.ingresar("Ingrese la expresion matematica: ", "operacion");
    cout << endl << infija_a_sufija(operacion);
    system("pause");
    return 0;
}
template <typename T>
T Calculadora_Polaca<T>::infija_a_prefija(T expresion) {
    // Agregar paréntesis al inicio y al final de la expresión
    expresion = "(" + expresion + ")";

    stack<char> pila;
    string resultado = "";

    for (int i = expresion.length() - 1; i >= 0; i--) {
        char c = expresion[i];

        if (isdigit(c)) {
            resultado = c + resultado;
        } else if (c == ')') {
            pila.push(c);
        } else if (c == '(') {
            while (!pila.empty() && pila.top() != ')') {
                resultado = pila.top() + resultado;
                pila.pop();
            }
            if (!pila.empty()) {
                pila.pop(); // Eliminar el paréntesis de cierre
            }
        } else { // Operador
            while (!pila.empty() && precedencia(c) < precedencia(pila.top())) {
                resultado = pila.top() + resultado;
                pila.pop();
            }
            pila.push(c);
        }
    }

    while (!pila.empty()) {
        resultado = pila.top() + resultado;
        pila.pop();
    }

    return resultado;
}

// Función auxiliar para determinar la precedencia de los operadores
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

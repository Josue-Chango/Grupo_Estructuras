#ifndef CALCULADORA_POLACA_H
#define CALCULADORA_POLACA_H

#include <iostream>
#include <queue>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <map>

template<typename T>  // T para el tipo de la cola y U para la edad
class Calculadora_Polaca {
private:
    std::string expresion;
public:
    Calculadora_Polaca();
    //T infija_a_sufija( T&);
    T infija_a_prefija(T );
    int precedencia(char );
};

#endif // CALCULADORA_POLACA_H

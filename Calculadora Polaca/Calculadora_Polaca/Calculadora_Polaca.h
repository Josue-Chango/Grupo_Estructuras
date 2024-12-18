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

template<typename T>  
class Calculadora_Polaca {
private:
    std::string expresion;
public:
    Calculadora_Polaca();
    //T infija_a_sufija( T&);
    T infija_a_prefija(T );
    T evaluar_postfija(T );
};

#endif // CALCULADORA_POLACA_H


#include "Validaciones.cpp"
#include "Calculadora_Polaca.cpp"
#include <string>
#include <stdio.h>
int main (){
    Validaciones<string> ingresar_operacion;
    Calculadora_Polaca<string> operacion;
    string op;
    op = ingresar_operacion.ingresar("Ingrese operacion matematica: ", "operacion");
    cout << endl << "Expresion infija: " << op;
    cout << endl << "Expresion prefija: " << operacion.infija_a_prefija(op) << endl;
    system("pause");
    return 0;
}
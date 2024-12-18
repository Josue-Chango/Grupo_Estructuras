
#include "Validaciones.cpp"
#include "Calculadora_Polaca.cpp"
#include <string>
#include <stdio.h>

int main (){
    Validaciones<string> ingresar_operacion;
    Calculadora_Polaca<string> operacion;
    string op;

      try {

            op = ingresar_operacion.ingresar("Ingrese operacion matematica: ", "operacion");
            cout << endl << "Expresion infija: " << op;
            cout << endl << "Expresion prefija: " << operacion.infija_a_prefija(op) << endl;
            cout << endl << "Expresion postfija: " << operacion.evaluar_postfija(op) << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    system("pause");
    return 0;
}
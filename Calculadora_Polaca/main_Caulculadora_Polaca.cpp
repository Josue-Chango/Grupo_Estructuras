
#include "Validaciones.cpp"
#include <string>
#include <stdio.h>
int main (){
    Validaciones<string> ingresar_operacion;
    string op;
    op = ingresar_operacion.ingresar("Ingrese operacion matematica: ", "operacion");
    cout << endl << op << endl;
    system("pause");
    return 0;
}
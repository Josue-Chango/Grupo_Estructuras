/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programa con validacion de entrada  *
 * Autor:                          Josue Chango                        *
 * Fecha de creacion:              09/11/2024                          *
 * Fecha de modificacion:          10/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include "Validaciones.cpp"
#include "Calculo.cpp"
#include "Fraccion.cpp"

using namespace std;

int main(){
    
    int numeroEntero1, numeroEntero2, resultadoEntero;
    float numeroFlotante1,numeroFlotante2, resultadoFlotante;
    double numeroDoble1,numeroDoble2, resultadoDoble;
    char let;
    string cadena;
    Fraccion<float> frac1, frac2, resultadoFraccion;

    Validaciones<int> entero;
    Validaciones<float> flotante;
    Validaciones<string> nombre;
    Validaciones<double> doble;
    Validaciones<char> letra;

    frac1.ingresarFraccion();
    cout << endl;
    frac1.imprimirFraccion();
    cout << endl;

    frac2.ingresarFraccion();
    cout << endl;
    frac2.imprimirFraccion();
    cout << endl;

    resultadoFraccion = resultadoFraccion.SumarFraccion(frac1, frac2);
    resultadoFraccion.imprimirResultado();
    resultadoFraccion = resultadoFraccion.RestarFraccion(frac1, frac2);
    resultadoFraccion.imprimirResultado();
    resultadoFraccion = resultadoFraccion.DividirFraccion(frac1, frac2);
    resultadoFraccion.imprimirResultado();
    resultadoFraccion = resultadoFraccion.MultiplicarFraccion(frac1, frac2);
    resultadoFraccion.imprimirResultado();

    /*numeroEntero1 = entero.ingresar("ingrese un valor entero: ", "entero");
    cout << endl << numeroEntero1 << endl;
    numeroEntero2 = entero.ingresar("ingrese un valor entero: ", "entero");
    cout << endl << numeroEntero2 << endl;
    Calculo<int> calcularEntero(numeroEntero1, numeroEntero2);
    resultadoEntero = calcularEntero.sumar();
    cout << "Resultado de la suma: " << resultadoEntero << endl;
    resultadoEntero = calcularEntero.restar();
    cout << "Resultado de la resta: " << resultadoEntero << endl;
    resultadoEntero = calcularEntero.multiplicar();
    cout << "Resultado de la multiplicacion: " << resultadoEntero << endl;

    numeroFlotante1 = flotante.ingresar("ingrese un valor flotante: ", "flotante");
    cout << endl << numeroFlotante1 << endl;
    numeroFlotante2 = flotante.ingresar("ingrese un valor flotante: ", "flotante");
    cout << endl << numeroFlotante2 << endl;
    Calculo<float> calcularFlotante(numeroFlotante1, numeroFlotante2);
    resultadoFlotante = calcularFlotante.sumar();
    cout << "Resultado de la suma: " << resultadoFlotante << endl;
    resultadoFlotante = calcularFlotante.restar();
    cout << "Resultado de la resta: " << resultadoFlotante << endl;
    resultadoFlotante = calcularFlotante.multiplicar();
    cout << "Resultado de la multiplicacion: " << resultadoFlotante << endl;

    numeroDoble1 = doble.ingresar("ingrese un valor double: ", "double");
    cout << endl << numeroDoble1 << endl;
    let = letra.ingresar("ingrese una letra: ", "char");
    cout << endl << let << endl;
    cadena = nombre.ingresar("ingrese su nombre: ", "string");
    cout << endl << cadena << endl;*/
    return 0;
}
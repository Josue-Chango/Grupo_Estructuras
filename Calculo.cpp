#include<iostream> 
#include<conio.h> 
#include "Calculo.h" 
#include <stdio.h> 
using namespace std;
template <typename T>
Calculo<T>::Calculo(T a, T b)
{
    numero1 = a;
    numero2 = b;
}
// **Funci�n para sumar los valores de a y b**
template <typename T> 
T Calculo<T>::sumar() { 
    T resultado;
    return resultado = numero1 + numero2;  
} 
// **Funci�n para restar los valores de a y b** 
template <typename T> 
T Calculo<T>::restar() { 
    T resultado;
    return resultado = numero1 - numero2;  
 } 
// **Funci�n para multiplicar los valores de a y b**
template <typename T> 
T Calculo<T>::multiplicar() { 
    T resultado;
    return resultado = numero1 * numero2;  
 } 
 


/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programa que suma fracciones        *
 * Autor:                          Josue Chango                        *
 * Fecha de creacion:              31/10/2024                          *
 * Fecha de modificacion:          01/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Fraccion.h"
#include "Validaciones.h"
#include <iostream>

using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::getNum()
// Purpose:    Implementation of Fraccion::getNum()
// Return:     float
////////////////////////////////////////////////////////////////////////
template <typename T>
float Fraccion<T>::getNum(void)
{
   return num;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::setNum(float newNum)
// Purpose:    Implementation of Fraccion::setNum()
// Parameters:
// - newNum
// Return:     void
////////////////////////////////////////////////////////////////////////
template <typename T>
void Fraccion<T>::setNum(float newNum)
{
   num = newNum;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::getDeno()
// Purpose:    Implementation of Fraccion::getDeno()
// Return:     float
////////////////////////////////////////////////////////////////////////
template <typename T>
float Fraccion<T>::getDeno(void)
{
   return deno;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::setDeno(float newDeno)
// Purpose:    Implementation of Fraccion::setDeno()
// Parameters:
// - newDeno
// Return:     void
////////////////////////////////////////////////////////////////////////
template <typename T>
void Fraccion<T>::setDeno(float newDeno)
{
   deno = newDeno;
}

template <typename T>
Fraccion<T>::Fraccion(float a, float b)
{
   num = a;
   deno = b;
}

template <typename T>
Fraccion<T>::Fraccion()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::Fraccion()
// Purpose:    Implementation of Fraccion::Fraccion()
// Return:     
////////////////////////////////////////////////////////////////////////

/*Fraccion::Fraccion()
{

}*/

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::~Fraccion()
// Purpose:    Implementation of Fraccion::~Fraccion()
// Return:     
////////////////////////////////////////////////////////////////////////

/*Fraccion::~Fraccion()
{
   // TODO : implement
}*/

template <typename T>
Fraccion<T> Fraccion<T>::SumarFraccion(Fraccion obj1, Fraccion obj2)
{
   Fraccion temporal;

   if (obj1.getDeno() == obj2.getDeno()){
      temporal.deno = obj1.getDeno();
      temporal.num = obj1.getNum() + obj2.getNum();
   }else{
      temporal.deno = obj1.getDeno() * obj2.getDeno();
      temporal.num = (obj1.getNum() * obj2.getDeno()) + (obj1.getDeno() * obj2.getNum());
   }
    return temporal;
}

template <typename T>
Fraccion<T> Fraccion<T>::DividirFraccion(Fraccion obj1, Fraccion obj2)
{
    Fraccion temporal;

   temporal.deno = obj1.getDeno() * obj2.getNum();
   temporal.num = obj1.getNum() * obj2.getDeno();
    return temporal;
}

template <typename T>
Fraccion<T> Fraccion<T>::MultiplicarFraccion(Fraccion obj1, Fraccion obj2)
{
    Fraccion temporal;

   temporal.deno = obj1.getDeno() * obj2.getDeno();
   temporal.num = obj1.getNum() * obj2.getNum();
    return temporal;
}

template <typename T>
Fraccion<T> Fraccion<T>::RestarFraccion(Fraccion obj1, Fraccion obj2)
{
   Fraccion temporal;

   if (obj1.getDeno() == obj2.getDeno()){
      temporal.deno = obj1.getDeno();
      temporal.num = obj1.getNum() - obj2.getNum();
   }else{
      temporal.deno = obj1.getDeno() * obj2.getDeno();
      temporal.num = (obj1.getNum() * obj2.getDeno()) + (obj1.getDeno() * obj2.getNum());
   }
    return temporal;
}

template <typename T>
void Fraccion<T>::ingresarFraccion()
{
   bool aux = false;
    Validaciones<float> flotante;
    num = flotante.ingresar("ingrese un valor numerador: ", "flotante");
    cout << endl;
    deno = flotante.ingresar("ingrese un valor denominador: ", "flotante");
    while(aux == false){
      if(validar() == false){
            deno = flotante.ingresar("ingrese un valor denominador: ", "flotante");
            cout << endl;
      }else if(validar() == true){
         aux = true;
      } 
    }
}

template <typename T>
void Fraccion<T>::imprimirResultado()
{
   cout << "Resultado de la operacion: " << num << "/" << deno << endl;
}

template <typename T>
bool Fraccion<T>::validar()
{
   if (deno == 0)
   {
      cout << endl;
      cout << "El denominador no puede ser 0 " << endl;
      return false;
   }else{
      return true;
   }
}

template <typename T>
void Fraccion<T>::imprimirFraccion(){
   cout << num << "/" << deno << endl;
}

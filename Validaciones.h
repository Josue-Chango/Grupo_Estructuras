/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programa con validacion de entrada  *
 * Autor:                          Josue Chango                        *
 * Fecha de creacion:              09/11/2024                          *
 * Fecha de modificacion:          10/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <conio.h>


#if !defined(__Validaciones_Validaciones_h)
#define __Validaciones_Validaciones_h

template<typename T>
class Validaciones
{
   public:
      Validaciones();
      T ingresar(char *msj, char *tipo);
   protected:
   private:
      T numero;


};

#endif
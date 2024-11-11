/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programa que suma fracciones        *
 * Autor:                          Josue Chango                        *
 * Fecha de creacion:              31/10/2024                          *
 * Fecha de modificacion:          01/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#if !defined(__Fraccion_Fraccion_h)
#define __Fraccion_Fraccion_h

template<typename T>
class Fraccion
{
   public:
      float getNum(void);
      void setNum(float newNum);
      float getDeno(void);
      void setDeno(float newDeno);
      Fraccion(float num, float deno);
      Fraccion();
      //~Fraccion();
      void ingresarFraccion();
      void imprimirResultado();
      bool validar();
      void imprimirFraccion();
      Fraccion SumarFraccion(Fraccion obj1, Fraccion obj2);
      Fraccion DividirFraccion(Fraccion obj1, Fraccion obj2);
      Fraccion MultiplicarFraccion(Fraccion obj1, Fraccion obj2);
      Fraccion RestarFraccion(Fraccion obj1, Fraccion obj2);
   protected:
   private:
      T num;
      T deno;
      Validaciones<float> flotanteFraccion;
};

#endif
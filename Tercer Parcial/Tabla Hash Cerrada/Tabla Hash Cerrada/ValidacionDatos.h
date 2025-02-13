/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/


#include"LecturaDatos.h"
#pragma once
class ValidacionDatos:public LecturaDatos
{
	public:
		char* lecturaEnteros(char const *msj) override;
		char* lecturaReales(char const *msj) override;
		char* lecturaTexto(char const *msj) override;
		char* lecturaTextoNumerico(char const *msj) override;
		int casteoEnteros(char* dato,char const *msj);
		double casteoReales(char* dato, char const *msj);
		
		
};
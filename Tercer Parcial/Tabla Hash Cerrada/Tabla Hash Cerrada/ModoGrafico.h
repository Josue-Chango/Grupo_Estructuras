/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/
 #include "NodoHash.cpp"
 #include <graphics.h>

 class ModoGrafico{
 	public:
 	ModoGrafico();
	void dibujarTabla();	
 	void dibujarTabla2(int valor, int pos);
 	void recorrerPosicionesInsertar(int pos);	
 	void recorrerPosicionesBorrar(int pos);
 	void recorrerPosicionesBuscar(int pos);
 	void borrarCasillas(int pos);
 	
 };
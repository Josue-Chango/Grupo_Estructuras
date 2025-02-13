/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/

#include"ValidacionDatos.h"
#define LONGITUD 10
#pragma once

/**
 * Lee una cadena de números del teclado y la devuelve
 * 
 * @param msj El mensaje que se mostrará al usuario.
 * 
 * @return Un puntero a una matriz de caracteres.
 */
char* ValidacionDatos::lecturaEnteros(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msj);
	while((c=getch())!=13)//ingreso de datos sin ecco(NO SE PUEDE VER)
	{
		if(c>='0'&&c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}	else if (c == 8){ //backspace
			if (i>0){
				i--;
				printf("\b \b");
			}	
		}
	}
	dato[i]='\0';
	return dato;
}
//CASTEO

/**
 * 
 * @param dato la variable que almacenará el valor
 * @param msj El mensaje que se mostrará al usuario.
 */
int ValidacionDatos::casteoEnteros(char* dato,char const *msj){	
	int valor;
	//"\nIngresar el valor a convertir a entero : "
	strcpy(dato,lecturaEnteros(msj));
	return valor=atoi(dato);
}

/**
 * Lee una cadena de caracteres del teclado y devuelve un puntero a la cadena
 * 
 * @param msj El mensaje que se mostrará al usuario.
 * 
 * @return Un puntero a una matriz de caracteres.
 */
char* ValidacionDatos::lecturaReales(char const *msj){
char *dato=new char[LONGITUD+1];
    char c;
    printf("%s",msj);
    int i=0;
	int punto=0;
    while(c = getch()){
		if (c==13){
			dato[i]='\0';
			break;
		}
		else if (c == 8){ //backspace
			if (i>0){
				i--;
				printf("\b \b");
				if (dato[i]==46){
					punto=0;
				}
				
			}	
		}
		else if(c==46){
			
			if (punto<1){
				printf("%c",c);
				dato[i]=c;
				i++;
			}
			punto++;
		}
		else{	
			if (i<LONGITUD && c>='0'&& c<='9') //limite de longitud
			{
				printf("%c",c);
				dato[i]=c;
				i++;
			}
			
		}
	
	}
	return dato;
}
//CASTEO
/**
 * Toma una cadena, la convierte en un doble y devuelve el doble
 * 
 * @param dato es la variable que almacenará los datos introducidos por el usuario.
 * @param msj El mensaje que se mostrará al usuario.
 */
double ValidacionDatos::casteoReales(char* dato,char const *msj){	
	double valor;
	strcpy(dato,lecturaReales(msj));
	return valor=atof(dato);
}

/**
 * Lee una cadena del teclado y la devuelve.
 * 
 * @param msj El mensaje que se mostrará al usuario.
 * 
 * @return Un puntero a una matriz de caracteres.
 */
char* ValidacionDatos::lecturaTexto(char const *msj){
	////
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msj);
	while((c=getch())!=13)//ingreso de datos sin ecco(NO SE PUEDE VER)
	{
		if((c>=65 && c<=90 ||c>=97 && c<=122||c==32 )){
			printf("%c",c);
			dato[i++]=c;
		}	else if (c == 8){ //backspace
			if (i>0){
				i--;
				printf("\b \b");		
			}	
		}
	}
	dato[i]='\0';
	return dato;
}

char* ValidacionDatos::lecturaTextoNumerico(char const *msj){
	////
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msj);
	while((c=getch())!=13)//ingreso de datos sin ecco(NO SE PUEDE VER)
	{
		if((c>=48 && c<=57)){
			printf("%c",c);
			dato[i++]=c;
		}	else if (c == 8){ //backspace
			if (i>0){
				i--;
				printf("\b \b");		
			}	
		}
	}
	dato[i]='\0';
	return dato;
}
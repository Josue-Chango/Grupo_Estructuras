/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/


#include "Menu.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include "ValidacionDatos.cpp"
#include "TablaCerradaEnteros.cpp"
#define Tecla_Arriba 72
#define Tecla_Abajo 80
#define Enter 13

using namespace std;

void Menu::menuPrincipal(){
	int cedula,horas,opcMP=0, opcMR=0,opcMB=0,opcTR=0,opcTH=0,opcMTH,valor=0;
	bool repetir=true,repetir2=true,repetir3=true,repetir4=true,repetir5=true,repetir6=true, repetir7 = true,repetir8 = true;
    ValidacionDatos objValidar;
    char enteroC[10];
    int entero;
	const char *titulo="MODO GRAFICO TABLA HASH CERRADA";
    const char *opciones[]={"Insertar Datos.","Cerrar aplicativo."};
	const char *titulo2="TECNICAS EVITAR COLISION";
	const char *opciones2[]={"Sondeo Lineal.","Sondeo Cuadratico","Doble hash.","Retornar al menu principal."};
	const char *titulo6="METODOS";
	const char *opciones6[]={"Insertar dato.","Eliminar dato.","Buscar dato.","Retornar al menu principal."};
	TablaCerradaEnteros objHash;
	ModoGrafico objG;

	char elementosV[10];
	

	initwindow(1150,500);
	settextstyle(7,HORIZ_DIR,6);
	outtextxy(50,1,"TABLA HASH CERRADA");
	settextstyle(7,HORIZ_DIR,2);
	setcolor(15);
	objG.dibujarTabla();
	//system("cls");
	//getch();
	do{
    	opcMP = menu(titulo,opciones,2);
    	switch(opcMP){

    		case 1:{
    			system("cls");

								//TABLA HASH
								do{
								opcTH=menu(titulo2,opciones2,4);
								switch(opcTH){
									case 1:{
										//SONDEO LINEAL
										settextstyle(7,HORIZ_DIR,6);
										outtextxy(50,100,"SONDEO LINEAL");
										settextstyle(7,HORIZ_DIR,2);
										objG.dibujarTabla();
										objHash.vaciarTabla();

										do{
    									opcMTH=menu(titulo6,opciones6,4);
    									switch(opcMTH){
    										case 1:{
    											system("cls");
    											//MODO GRAFICO

												system("cls");
												do{
												entero=objValidar.casteoEnteros(enteroC,"\nIngrese el dato-> ");
												}while(entero>999||entero<0);
    										
												objHash.insertarSondeoLineal(entero);
												break;
											}
											case 2:{
												system("cls");
												do{
												entero=objValidar.casteoEnteros(enteroC,"\nIngrese el dato que desea eliminar-> ");	
												}while(entero>999||entero<0);
												
												
												objHash.eliminarSondeoLineal(entero);
												break;
											}
											case 3:{
												system("cls");
												do{
													valor=objValidar.casteoEnteros(enteroC,"\nIngrese el valor a buscar-> ");
												}while(valor>999||valor<0);			
												objHash.buscar(valor);
												break;
											}

											case 4:{
												    settextstyle(7,HORIZ_DIR,6);
													outtextxy(50,90,"                                                                  ");
													settextstyle(7,HORIZ_DIR,2);
												repetir6=false;
												break;
											}
										}
										}while(repetir6);
										repetir6=true;



										break;
									}
									case 2:{
										//SONDEO CUADRATICO
										settextstyle(7,HORIZ_DIR,6);
										outtextxy(50,100,"SONDEO CUADRATICO");
										settextstyle(7,HORIZ_DIR,2);
										objG.dibujarTabla();
										objHash.vaciarTabla();
										do{
    									opcMTH=menu(titulo6,opciones6,4);
    									switch(opcMTH){
    										case 1:{
    											system("cls");
    											do{
    											entero=objValidar.casteoEnteros(enteroC,"\nIngrese el dato para cuadratico-> ");	
												}while(entero>999||entero<0);
    											
												objHash.insertarSondeoCuadratico(entero);

												break;
											}
											case 2:{
												system("cls");
												do{
													entero=objValidar.casteoEnteros(enteroC,"\nIngrese el dato que desea eliminar-> ");
												}while(entero>999||entero<0);
												
												objHash.eliminarSondeoCuadratico(entero);
												break;
											}
											case 3:{
												system("cls");
												do{
												valor=objValidar.casteoEnteros(enteroC,"\nIngrese el valor a buscar-> ");	
												}while(valor>999||valor<0);
												
												objHash.buscarCuadratico(valor);
												break;
											}

											case 4:{
													settextstyle(7,HORIZ_DIR,6);
													outtextxy(50,90,"                                                                  ");
													settextstyle(7,HORIZ_DIR,2);
												repetir7=false;
												break;
											}
										}
										}while(repetir7);
										repetir7=true;
											break;
									}
									case 3:{
										//SONDEO DOBLE HASH
										//system("cls");
										settextstyle(7,HORIZ_DIR,6);
										outtextxy(50,100,"SONDEO DOBLE");
										settextstyle(7,HORIZ_DIR,2);
										objG.dibujarTabla();
										objHash.vaciarTabla();
										do{
    									opcMTH=menu(titulo6,opciones6,4);
    									switch(opcMTH){
    										case 1:{
    											system("cls");
    											do{
    												entero=objValidar.casteoEnteros(enteroC,"\nIngrese el dato para doble hash-> ");
												}while(entero>999||entero<0);
    											
												objHash.insertarSondeoDoble(entero);
												break;
											}
											case 2:{
												system("cls");
												do{
												entero=objValidar.casteoEnteros(enteroC,"\nIngrese el dato que desea eliminar-> ");	
												}while(entero>999||entero<0);
												
												objHash.eliminarSondeoDoble(entero);
												break;
											}
											case 3:{
												system("cls");
												do{
												valor=objValidar.casteoEnteros(enteroC,"\nIngrese el valor a buscar-> ");	
												}while(valor>999||valor<0);
												
												objHash.buscarDoble(valor);
												break;
											}

											case 4:{
												settextstyle(7,HORIZ_DIR,6);
												outtextxy(50,90,"                                                                  ");
												settextstyle(7,HORIZ_DIR,2);
												repetir8=false;
												break;
											}
										}
										}while(repetir8);
										repetir8=true;

										break;
									}
									case 4:{
										repetir5=false;
										break;
									}
								}
								}while(repetir5);
								repetir5=true;


						break;

			}


    		case 2:{
    			system("cls");
    			cout<<"\n\t  HASTA PRONTO";
                repetir=false;
                break;
			}
		}
	}while(repetir);
}

/**
 * Muestra un menú con un título y una lista de opciones, y devuelve el número de la opción
 * seleccionada por el usuario
 *
 * @param titulo El título del menú.
 * @param opciones es una matriz de cadenas que contiene las opciones que se mostrarán en el menú.
 * @param n número de opciones
 *
 * @return La opción seleccionada por el usuario.
 */
int Menu::menu(const char *titulo,const char *opciones[],int n){
    int opcSeleccionada=1;
    int tecla;
    bool repetir=true;
    do{
        system("cls");
        gotoxy(5,3+opcSeleccionada); cout<<"-->";
        gotoxy(15,2); cout<<titulo;
        for(int i=0;i<n;i++){
            gotoxy(10,4+i); cout<<i+1<<"."<<opciones[i];
        }

        do{
            tecla=getch();
        }while(tecla!=Tecla_Arriba && tecla!=Tecla_Abajo && tecla!=Enter);

        switch (tecla)
        {
        case Tecla_Arriba:
            opcSeleccionada--;
            if(opcSeleccionada<1){
               opcSeleccionada=n;
            }
            break;
        case Tecla_Abajo:
            opcSeleccionada++;
            if(opcSeleccionada>n){
               opcSeleccionada=1;
            }
            break;
        case Enter:
            repetir=false;
            break;
        }
    }while(repetir);


    return opcSeleccionada;

}

/**
 * Mueve el cursor a la posición especificada
 *
 * @param x La coordenada x del cursor.
 * @param y La coordenada y del cursor.
 */
void Menu::gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}



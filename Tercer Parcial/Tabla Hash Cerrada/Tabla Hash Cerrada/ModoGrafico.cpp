/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/
#include "ModoGrafico.h"
ModoGrafico::ModoGrafico(){
	
}

/**
 * Dibuja una tabla con 29 celdas.
 */
void ModoGrafico::dibujarTabla(){
	char vecS[10];
	char vecValor[10];
	int x1 = 31;//espacio entre cuadros
	int x2 = 100;
	int y1 = 150;
	int y2 = 200;
	//char vecS[10];
	settextstyle(0,HORIZ_DIR,2);
	for (int i = 0; i < 29; i++) {
		// Establecemos el color de los cuadros intercambiados
	
		//cuadros
		setcolor(15);
		rectangle(x1, y1, x2, y2);
		//posiciones
		sprintf(vecS, "%d", i);
		outtextxy(x1 + 20, y1 + 55, vecS);
		 outtextxy(x1 +20, y1 + 20, "   ");
            x1 += 70;
            x2 += 70;
        //limite de la fila
		if ((i+1) % 11 == 0){
            x1 = 31;
            x2 = 100;
            y1 += 100;
            y2 += 100;
            rectangle(x1, y1, x2, y2);
		}

	//delay(500);
	}

}

/**
 * Dibuja una tabla con un valor y una posición.
 * 
 * @param valor el valor a insertar
 * @param pos posición del valor a dibujar
 */
void ModoGrafico::dibujarTabla2(int valor, int pos){
	
	char vecS[10];
	char vecValor[10];
	int x1 = 31;//espacio entre cuadros
	int x2 = 100;
	int y1 = 150;
	int y2 = 200;
	//char vecS[10];
	settextstyle(0,HORIZ_DIR,2);
	for (int i = 0; i < 29; i++) {
		// Establecemos el color de los cuadros intercambiados
		if (i == -1 || i != pos) {
			setcolor(15);
		}else {
		    //vuelves a dibujar el recuadro del valor - posicion
		    rectangle(x1, y1, x2, y2);
		    //posiciones
            sprintf(vecS, "%d", i);
            outtextxy(x1 + 20, y1 + 55, vecS);
            //valor dentro del recuadro
            sprintf(vecValor, "%d", valor);
            outtextxy(x1 +20, y1 + 20, vecValor);
            //delay(1200);
			setcolor(LIGHTBLUE);
		}
		//cuadros
		rectangle(x1, y1, x2, y2);
		//posiciones
		sprintf(vecS, "%d", i);
		outtextxy(x1 + 20, y1 + 55, vecS);
            x1 += 70;
            x2 += 70;
        //limite de la fila
		if ((i+1) % 11 == 0){
            x1 = 31;
            x2 = 100;
            y1 += 100;
            y2 += 100;
            rectangle(x1, y1, x2, y2);
		}

	//delay(500);
	}
	
}

/**
 * Dibuja un rectángulo con un número dentro, y luego dibuja otro rectángulo con un número dentro, y
 * luego dibuja otro rectángulo con un número dentro, y luego dibuja otro rectángulo con un número
 * dentro, y luego dibuja otro rectángulo con un un número dentro, y luego dibuja otro rectángulo con
 * un número dentro, y luego dibuja otro rectángulo con un número dentro, y luego dibuja otro
 * rectángulo con un número dentro, y luego dibuja otro rectángulo con un número dentro, y luego dibuja
 * otro rectángulo con un número dentro y luego dibuja otro rectángulo con un número dentro y luego
 * dibuja otro rectángulo con un número dentro y luego dibuja otro rectángulo con un número dentro y
 * luego dibuja otro rectángulo con un número dentro de él, y luego dibuja otro rectángulo con un
 * número dentro, y luego dibuja otro rectángulo con un número dentro, y luego dibuja otro rectángulo
 * con un número dentro, y luego dibuja otro rec enredo con un número dentro de él,
 * 
 * @param pos posición del valor a insertar
 */
void ModoGrafico::recorrerPosicionesInsertar(int pos){
	
	char vecS[10];
	char vecValor[10];
	int x1 = 31;//espacio entre cuadros
	int x2 = 100;
	int y1 = 150;
	int y2 = 200;
	//char vecS[10];
	settextstyle(0,HORIZ_DIR,2);
	for (int i = 0; i < 29; i++) {
		// Establecemos el color de los cuadros intercambiados
		if (i != pos) {
			setcolor(15);
		}else {

		    //vuelves a dibujar el recuadro del valor - posicion
		    rectangle(x1, y1, x2, y2);
		    //posiciones
            sprintf(vecS, "%d", i);
            outtextxy(x1 + 20, y1 + 55, vecS);
            //valor dentro del recuadro
            
			setcolor(LIGHTBLUE);

		}
		//cuadros
		rectangle(x1, y1, x2, y2);
		//posiciones
		sprintf(vecS, "%d", i);
		outtextxy(x1 + 20, y1 + 55, vecS);
            x1 += 70;
            x2 += 70;

        //limite de la fila
		if ((i+1) % 11 == 0){
            x1 = 31;
            x2 = 100;
            y1 += 100;
            y2 += 100;
            rectangle(x1, y1, x2, y2);
		}
	}
		
	
}


/**
 * Dibuja un rectángulo, luego dibuja un número dentro del rectángulo, luego dibuja otro rectángulo,
 * luego dibuja otro número dentro del rectángulo, luego dibuja otro rectángulo, luego dibuja otro
 * número dentro del rectángulo, luego dibuja otro rectángulo, luego dibuja otro número dentro del
 * rectángulo, luego dibuja otro rectángulo, luego dibuja otro número dentro del rectángulo, luego
 * dibuja otro rectángulo, luego dibuja otro número dentro del rectángulo, luego dibuja otro
 * rectángulo, luego dibuja otro número dentro del rectángulo, luego dibuja otro rectángulo, luego
 * dibuja otro número dentro del rectángulo, luego dibuja otro rectángulo, luego dibuja otro número
 * dentro del rectángulo, luego dibuja otro rectángulo, luego dibuja otro número dentro del rectángulo,
 * luego dibuja otro rectángulo, luego dibuja otro número dentro del rectángulo, luego dibuja otro
 * rectángulo, luego dibuja otro número dentro del rectángulo, luego d dibuja otro rectángulo, luego
 * dibuja otro número dentro del rectángulo, luego dibuja
 * 
 * @param pos posición del valor a borrar
 */
void ModoGrafico::recorrerPosicionesBorrar(int pos){
	
	char vecS[10];
char vecValor[10];
	int x1 = 31;//espacio entre cuadros
	int x2 = 100;
	int y1 = 150;
	int y2 = 200;
	//char vecS[10];
	settextstyle(0,HORIZ_DIR,2);
	for (int i = 0; i < 29; i++) {
		// Establecemos el color de los cuadros intercambiados
		if (i != pos) {
			setcolor(15);
		}else {

		    //vuelves a dibujar el recuadro del valor - posicion
		    rectangle(x1, y1, x2, y2);
		    //posiciones
            sprintf(vecS, "%d", i);
            outtextxy(x1 + 20, y1 + 55, vecS);
            //valor dentro del recuadro
            
			setcolor(LIGHTMAGENTA);

		}
		//cuadros
		rectangle(x1, y1, x2, y2);
		//posiciones
		sprintf(vecS, "%d", i);
		outtextxy(x1 + 20, y1 + 55, vecS);
            x1 += 70;
            x2 += 70;

        //limite de la fila
		if ((i+1) % 11 == 0){
            x1 = 31;
            x2 = 100;
            y1 += 100;
            y2 += 100;
            rectangle(x1, y1, x2, y2);
		}
	}
	
}

/**
 * Dibuja un rectángulo con un número dentro, y luego dibuja otro rectángulo con un número dentro, y
 * luego dibuja otro rectángulo con un número dentro, y luego dibuja otro rectángulo con un número
 * dentro, y luego dibuja otro rectángulo con un un número dentro, y luego dibuja otro rectángulo con
 * un número dentro, y luego dibuja otro rectángulo con un número dentro, y luego dibuja otro
 * rectángulo con un número dentro, y luego dibuja otro rectángulo con un número dentro, y luego dibuja
 * otro rectángulo con un número dentro y luego dibuja otro rectángulo con un número dentro y luego
 * dibuja otro rectángulo con un número dentro y luego dibuja otro rectángulo con un número dentro y
 * luego dibuja otro rectángulo con un número dentro de él, y luego dibuja otro rectángulo con un
 * número dentro, y luego dibuja otro rectángulo con un número dentro, y luego dibuja otro rectángulo
 * con un número dentro, y luego dibuja otro rec enredo con un número dentro de él,
 * 
 * @param pos la posición del valor a resaltar
 */
void ModoGrafico::recorrerPosicionesBuscar(int pos){
	
	char vecS[10];
char vecValor[10];
	int x1 = 31;//espacio entre cuadros
	int x2 = 100;
	int y1 = 150;
	int y2 = 200;
	
	settextstyle(0,HORIZ_DIR,2);
	for (int i = 0; i < 29; i++) {
		// Establecemos el color de los cuadros intercambiados
		if (i != pos) {
			setcolor(15);
		}else {

		    //vuelves a dibujar el recuadro del valor - posicion
		    rectangle(x1, y1, x2, y2);
		    //posiciones
            sprintf(vecS, "%d", i);
            outtextxy(x1 + 20, y1 + 55, vecS);
            //valor dentro del recuadro
           
			setcolor(LIGHTGREEN);

		}
		//cuadros
		rectangle(x1, y1, x2, y2);
		//posiciones
		sprintf(vecS, "%d", i);
		outtextxy(x1 + 20, y1 + 55, vecS);
            x1 += 70;
            x2 += 70;

        //limite de la fila
		if ((i+1) % 11 == 0){
            x1 = 31;
            x2 = 100;
            y1 += 100;
            y2 += 100;
            rectangle(x1, y1, x2, y2);
		}
	}
	
	
}

/**
 * Dibuja una cuadrícula de rectángulos y luego dibuja un rectángulo en un color diferente
 * 
 * @param pos la posición del valor a resaltar
 */
void ModoGrafico::borrarCasillas(int pos){
	

	int x1 = 31;//espacio entre cuadros
	int x2 = 100;
	int y1 = 150;
	int y2 = 200;
	char vecS[10];
	settextstyle(0,HORIZ_DIR,2);
	for (int i = 0; i < 29; i++) {
		// Establecemos el color de los cuadros intercambiados
		if (i == -1 || i != pos) {
			setcolor(15);
		}else {
		    //vuelves a dibujar el recuadro del valor - posicion
		    rectangle(x1, y1, x2, y2);
		    //posiciones
            outtextxy(x1 +20, y1 + 20, "   ");
			setcolor(LIGHTMAGENTA);
		}
		//cuadros
		rectangle(x1, y1, x2, y2);
		//posiciones
		sprintf(vecS, "%d", i);
		outtextxy(x1 + 20, y1 + 55, vecS);
            x1 += 70;
            x2 += 70;
        //limite de la fila
		if ((i+1) % 11 == 0){
            x1 = 31;
            x2 = 100;
            y1 += 100;
            y2 += 100;
            rectangle(x1, y1, x2, y2);
		}

	}
}
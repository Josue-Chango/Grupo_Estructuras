/*************************
UFA - ESPE
AUTORES: Matías Padrón, Sebastian Torres, Ariel Guevara
FECHA DE CREACIÓN: 11/01/2023
FECHA DE MODIFICACIÓN: 14/01/2023
Proyecto Unidad 2
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/
#pragma once
#include <iostream>
#include "TablaCerradaEnteros.h"
using namespace std;
ModoGrafico objG;

/**
 * EnterosTablaCerrada :: EnterosTablaCerrada(){
 *     tabla = new HashNode*[SILLAS];
 *     for ( int i = 0 ; i < NSILLAS ; i ++ ){
 *         tabla[i] = NULL;
 *     } }
 * } }
 */
TablaCerradaEnteros :: TablaCerradaEnteros(){
    tabla = new NodoHash*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }
}

/**
 * Elimina la tabla.
 */
TablaCerradaEnteros :: ~TablaCerradaEnteros(){
    /*for(int i = 0; i < NCASILLAS; i++){
        NodoHash *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            tabla[i] = tabla[i]->getSig();
            delete aux;
            aux = tabla[i];
        }
    }
    delete[] tabla;*/
}

/**
 * Inserta un valor en la tabla hash mediante un sondeo lineal.
 * 
 * @param valor el valor a insertar
 */
void TablaCerradaEnteros::insertarSondeoLineal(int valor){
    int pos = valor % NCASILLAS;
    int i = 0;
    NodoHash *aux = tabla[pos];
    //bandera que controla
    int iterador = 0;
    bool bandera = false;
    while (bandera == false && iterador <= NCASILLAS){
    	settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
    	if(pos > NCASILLAS-1){
    		pos = 0;
    		objG.recorrerPosicionesInsertar(pos);
    		delay(DELAYINSERTAR);
    		aux = tabla[pos];
    		iterador++;
		}
	    if(aux == NULL){
	        tabla[pos] = new NodoHash(valor);
            objG.recorrerPosicionesInsertar(pos);
            delay(DELAYINSERTAR);
	        objG.dibujarTabla2(valor,pos);
	        delay(DELAYINSERTAR);
	        iterador++;
	        bandera = true;
	    }
	    else{
	        while(aux != NULL && iterador <= NCASILLAS)
	        {
	            objG.recorrerPosicionesInsertar(pos);
	            delay(DELAYINSERTAR);
	        	pos++;
				aux = tabla[pos];
				iterador++;
			}
		}
			if (iterador >= NCASILLAS ){
			bandera=true;
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(700,380,"Tabla llena");
            settextstyle(5,HORIZ_DIR,1);

		}
	}
}


/**
 * Inserta un valor en la tabla hash usando sondeo cuadrático
 * 
 * @param valor el valor a insertar
 */
void TablaCerradaEnteros::insertarSondeoCuadratico(int valor){

	int pos = valor%NCASILLAS;
	int poscuadratico = 0;
    int i = 0;
    bool bandera = false;
    NodoHash *aux = tabla[pos];

    while (bandera == false && i <= NCASILLAS){
        settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
	    if(aux == NULL){
	        tabla[pos] = new NodoHash(valor);
	        objG.recorrerPosicionesInsertar(pos);
            delay(DELAYINSERTAR);
	        objG.dibujarTabla2(valor,pos);
	        delay(DELAYINSERTAR);
	        bandera = true;
	    }
	    else{
	    	poscuadratico = pos;
	        while(aux != NULL && i <= NCASILLAS)
	        {
	            objG.recorrerPosicionesInsertar(pos);
	            delay(DELAYINSERTAR );
	        	i++;
	        	pos = (poscuadratico + i*i) % NCASILLAS;
				aux = tabla[pos];
			}
		}
	}
}

/**
 * Inserta un valor en la tabla hash usando hash doble.
 * 
 * @param valor el valor a insertar
 */
void TablaCerradaEnteros::insertarSondeoDoble(int valor){
	int pos = valor%NCASILLAS;
    int auxp = pos;
    int iterador = 0;
    NodoHash *aux = tabla[pos];
    //bandera que controla
    bool bandera = false;

    while (bandera == false && iterador <= NCASILLAS){
        settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
	    if(aux == NULL){
	        tabla[pos] = new NodoHash(valor);
	        objG.recorrerPosicionesInsertar(pos);
            delay(DELAYINSERTAR);
	        objG.dibujarTabla2(valor,pos);
	        delay(DELAYINSERTAR);
	        bandera = true;
	    }
	    else{
	        while(aux != NULL && iterador <= NCASILLAS)
	        {
	            objG.recorrerPosicionesInsertar(pos);
	            delay(DELAYINSERTAR);
	        	pos += hash2(auxp);
	        	iterador++;
	        	   	if(pos > NCASILLAS-1){
                        pos -=NCASILLAS;
                        aux = tabla[pos];
                        objG.recorrerPosicionesInsertar(pos);
                        delay(DELAYINSERTAR);
					}
				aux = tabla[pos];
			}
		}
	}
}

/**
 * Elimina un valor en una tabla hash mediante sondeo lineal
 * 
 * @param valor el valor a borrar
 */
void TablaCerradaEnteros::eliminarSondeoLineal(int valor){
    int pos = valor%NCASILLAS;
    NodoHash *aux = tabla[pos];
    bool encontrado = false;
    int iterador = 0;

    while (encontrado == false && iterador <= NCASILLAS){

        settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
		if(aux == NULL){
			objG.recorrerPosicionesBorrar(pos);
            delay(DELAYBORRAR);
			pos++;
			//objG.recorrerPosicionesBorrar(pos);
            //delay(DELAYBORRAR);
			aux = tabla[pos];
			iterador++;
			if (pos > NCASILLAS-1){
				pos = 0;
                objG.recorrerPosicionesBorrar(pos);
	            delay(DELAYBORRAR);
				aux = tabla[pos];
			}
		}else{
			if(aux->getValor() == valor){
			    tabla[pos] = tabla[pos]->getSig();
			    objG.recorrerPosicionesBorrar(pos);
                delay(DELAYBORRAR);
                objG.borrarCasillas(pos);
                delay(DELAYBORRAR);
		        aux = NULL;
				encontrado = true;
			}
			    objG.recorrerPosicionesBorrar(pos);
                delay(DELAYBORRAR);
			pos++;
			aux = tabla[pos];
			iterador++;
		}
		if (iterador >= NCASILLAS){
            encontrado = true;
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(700,380,"Valor no encontrado");
            settextstyle(5,HORIZ_DIR,1);
		}
	}
}

/**
 * Es una función que elimina un valor de una tabla hash usando sondeo cuadrático
 * 
 * @param valor el valor a buscar
 */
void TablaCerradaEnteros::eliminarSondeoCuadratico(int valor){

	int pos = valor%NCASILLAS;
    NodoHash *aux = tabla[pos];
    bool encontrado = false;
    int iterador = 0;
    int i = 0;
    int poscuadratico = pos;

    while (encontrado == false && iterador <= NCASILLAS){
        settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
		if(aux == NULL){
            objG.recorrerPosicionesBorrar(pos);
            delay(DELAYBORRAR);
			i++;
	        pos = (poscuadratico + i*i) % NCASILLAS;
			aux = tabla[pos];
			iterador++;
			if (pos > NCASILLAS-1){
				pos = 0;
				aux = tabla[pos];
			}
		}else{
			if(aux->getValor() == valor){
			    tabla[pos] = tabla[pos]->getSig();
			    objG.recorrerPosicionesBorrar(pos);
                delay(DELAYBORRAR);
                objG.borrarCasillas(pos);
                delay(DELAYBORRAR);
		        aux = NULL;
				encontrado = true;
			}
            objG.recorrerPosicionesBorrar(pos);
            delay(DELAYBORRAR);
			i++;
	        pos = (poscuadratico + i*i) % NCASILLAS;
			aux = tabla[pos];
			iterador++;

		}
		if (iterador >= NCASILLAS){
            encontrado = true;
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(700,380,"Valor no encontrado");
            settextstyle(5,HORIZ_DIR,1);
		}
	}
}

/**
 * Es una función que elimina un valor de una tabla hash usando hash doble
 * 
 * @param valor el valor a borrar
 */
void TablaCerradaEnteros::eliminarSondeoDoble(int valor){


	int pos = valor%NCASILLAS;
	int auxp = pos;
    NodoHash *aux = tabla[pos];
    bool encontrado = false;
    int iterador = 0;
    int i = 0;


    while (encontrado == false && iterador <= NCASILLAS){
        settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
		if(aux == NULL){
            objG.recorrerPosicionesBorrar(pos);
            delay(DELAYBORRAR);
			pos += hash2(auxp);
			if(pos > NCASILLAS-1){
    		pos -=NCASILLAS;
    		aux = tabla[pos];
			}
			aux = tabla[pos];
			iterador++;
			if (pos > NCASILLAS-1){
			    objG.recorrerPosicionesBorrar(pos);
                delay(DELAYBORRAR);
				pos = 0;
				aux = tabla[pos];
			}
		}else{
			if(aux->getValor() == valor){
			    tabla[pos] = tabla[pos]->getSig();
			    objG.recorrerPosicionesBorrar(pos);
                delay(DELAYBORRAR);
                objG.borrarCasillas(pos);
                delay(DELAYBORRAR);
		        aux = NULL;
				encontrado = true;
			}
			pos += hash2(auxp);
			if(pos > NCASILLAS-1){
			    objG.recorrerPosicionesBorrar(pos);
                delay(DELAYBORRAR);
                pos -=NCASILLAS;
                aux = tabla[pos];
			}
			aux = tabla[pos];
			iterador++;

		}
		if (iterador >= NCASILLAS){
            encontrado = true;
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(700,380,"Valor no encontrado");
            settextstyle(5,HORIZ_DIR,1);;
		}
	}
}

/**
 * Imprime el contenido de la tabla hash.
 */
void TablaCerradaEnteros::imprimir(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoHash *aux = tabla[i];
        while(aux != NULL){
            cout <<"Posicion["<<i<<"]: "<< aux->getValor() << " ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}

/**
 * Busca un valor en una tabla hash
 * 
 * @param valor el valor a buscar
 */
void TablaCerradaEnteros::buscar(int valor) {



    //const int ELEMENTO_NO_ENCONTRADO{-1};
	int pos = valor%NCASILLAS;
    NodoHash *aux = tabla[pos];
	bool encontrado = false;
	int iterador = 0;

	while (encontrado == false && iterador <= NCASILLAS){

        settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
		if(aux == NULL){
            objG.recorrerPosicionesBuscar(pos);
            delay(DELAYBUSCAR);
			pos++;
			aux = tabla[pos];
			iterador++;
			if (pos > NCASILLAS-1){
                objG.recorrerPosicionesBuscar(pos);
                delay(DELAYBUSCAR);
				pos = 0;
				aux = tabla[pos];
			}
		}else{
			if(aux->getValor() == valor){
                objG.recorrerPosicionesBuscar(pos);
                delay(DELAYBUSCAR);
		        cout << "\nPosicion[" << pos << "]: " << tabla[pos]->getValor() << endl;
				cout << "Elemento encontrado!\n" << endl;
				settextstyle(4,HORIZ_DIR,3);
                outtextxy(700,380,"Valor Encontrado!!");
                settextstyle(5,HORIZ_DIR,1);
				//cout<<"\n Valor no encontrado"<<endl;
				encontrado = true;
			}
			objG.recorrerPosicionesBuscar(pos);
            delay(DELAYBUSCAR);
			pos++;
			aux = tabla[pos];
			iterador++;
		}
		if (iterador >= NCASILLAS){
            encontrado = true;
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(700,380,"Valor no encontrado");
            settextstyle(5,HORIZ_DIR,1);
		}
	}
}

/**
 * Busca un valor en una tabla hash utilizando el método de sondeo cuadrático
 * 
 * @param valor el valor a buscar
 */
void TablaCerradaEnteros::buscarCuadratico(int valor){
	int pos = valor%NCASILLAS;
    NodoHash *aux = tabla[pos];
    bool encontrado = false;
    int iterador = 0;
    int i = 0;
    int poscuadratico = pos;

    while (encontrado == false && iterador <= NCASILLAS){
        settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
		if(aux == NULL){
		    	objG.recorrerPosicionesBuscar(pos);
            delay(DELAYBUSCAR);
			i++;
	        pos = (poscuadratico + i*i) % NCASILLAS;
			aux = tabla[pos];
			iterador++;
			if (pos > NCASILLAS-1){
			    	objG.recorrerPosicionesBuscar(pos);
                delay(DELAYBUSCAR);
				pos = 0;
				aux = tabla[pos];
			}
		}else{
			if(aux->getValor() == valor){
                	objG.recorrerPosicionesBuscar(pos);
                delay(DELAYBUSCAR);
			    cout << "\nPosicion[" << pos << "]: " << tabla[pos]->getValor() << endl;
				cout << "Elemento encontrado!\n" << endl;
                settextstyle(4,HORIZ_DIR,3);
                outtextxy(700,380,"Valor Encontrado!!");
                settextstyle(5,HORIZ_DIR,1);
                delay(DELAYBUSCAR);
				encontrado = true;
			}
            	objG.recorrerPosicionesBuscar(pos);
            delay(DELAYBUSCAR);
			i++;
	        pos = (poscuadratico + i*i) % NCASILLAS;
			aux = tabla[pos];
			iterador++;
		}
		if (iterador >= NCASILLAS){
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(700,380,"Valor no encontrado");
            settextstyle(5,HORIZ_DIR,1);
            cout<<"\n Valor no encontrado"<<endl;
		}
	}
}

/**
 * Busca un valor en una tabla hash utilizando hash doble
 * 
 * @param valor el valor a buscar
 */
void TablaCerradaEnteros::buscarDoble(int valor){

	int pos = valor%NCASILLAS;
	int auxp = pos;
    NodoHash *aux = tabla[pos];
    bool encontrado = false;
    int iterador = 0;

    while (encontrado == false && iterador <= NCASILLAS){
        settextstyle(4,HORIZ_DIR,3);
        outtextxy(700,380,"                                           ");
        settextstyle(5,HORIZ_DIR,1);
		if(aux == NULL){
			pos += hash2(auxp);
			objG.recorrerPosicionesBuscar(pos);
            delay(DELAYBUSCAR);
			if(pos > NCASILLAS-1){
                objG.recorrerPosicionesBuscar(pos);
                delay(DELAYBUSCAR);
                pos -=NCASILLAS;
                objG.recorrerPosicionesBuscar(pos);
                delay(DELAYBUSCAR);
                aux = tabla[pos];
			}
			aux = tabla[pos];
			iterador++;
			if (iterador >= NCASILLAS){
                encontrado = true;
                settextstyle(4,HORIZ_DIR,3);
                outtextxy(700,380,"Valor no encontrado");
                settextstyle(5,HORIZ_DIR,1);
            }
		}else{
			if(aux->getValor() == valor){
                objG.recorrerPosicionesBuscar(pos);
                delay(DELAYBUSCAR);
			   	cout << "\nPosicion[" << pos << "]: " << tabla[pos]->getValor() << endl;
				cout << "Elemento encontrado!\n" << endl;
                settextstyle(4,HORIZ_DIR,3);
                outtextxy(700,380,"Valor Encontrado!!");
                settextstyle(5,HORIZ_DIR,1);
                delay(DELAYBUSCAR);
				encontrado = true;
			}
			objG.recorrerPosicionesBuscar(pos);
            delay(DELAYBUSCAR);
			pos += hash2(auxp);
			if(pos > NCASILLAS-1){
                objG.recorrerPosicionesBuscar(pos);
                delay(DELAYBUSCAR);
                pos -=NCASILLAS;
                aux = tabla[pos];
			}
			aux = tabla[pos];
			iterador++;
			if (iterador >= NCASILLAS){
                encontrado = true;
                settextstyle(4,HORIZ_DIR,3);
                outtextxy(700,380,"Valor no encontrado");
                settextstyle(5,HORIZ_DIR,1);
            }
		}
	}

}

/**
 * La función devuelve el resto de la división del valor por el número de celdas
 * 
 * @param valor el valor a ser hash
 * 
 * @return El resto de la división del valor por el número de celdas.
 */
int TablaCerradaEnteros::hash(int valor){
    return valor % NCASILLAS;
}

/**
 * Devuelve la segunda función hash para la tabla hash cerrada.
 * 
 * @param valor el valor a ser hash
 * 
 * @return La función hash devuelve el índice de la matriz donde se debe almacenar el valor.
 */
int TablaCerradaEnteros::hash2(int valor){
	int resultado = (-valor)%7;
	if (resultado <= 0) {
        resultado += abs(7);
	}
    return resultado;
}

/**
 * Esta función establece todos los valores de la matriz en NULL.
 */
void TablaCerradaEnteros::vaciarTabla(){
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }
}

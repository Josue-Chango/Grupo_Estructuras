/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Programar una suma fracciones       *
 * Autor:                          Josue Chango                        *
 * Fecha de creacion:              06/10/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

int ingresar(char *);

//Ingresar enteros------------------------------------------------------------------------

int ingresar(char *msj){
    char cad[10];
    char c;
    int i = 0;
    int valor = 0;
    printf("%s", msj);
    while((c = getch()) != 13){
        if (c >= '0' && c <= '9'){
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        }
    }
    cad[i++] = '\0';
    valor = atoi(cad);
    return valor;
}


//Ingresar letras-------------------------------------------------------------------------

/*int ingresar(char *msj) {
    char cad[10];
    char c;
    int i = 0;
    int valor = 0;
    printf("%s", msj);
    while ((c = getch()) != 13) {
        if (isalpha(c)) {
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        }
    }
    cad[i] = '\0';
    for (int j = 0; cad[j] != '\0'; j++) {
        valor = valor * 10;
    }
    
    return valor;
}*/


//Ingresar float------------------------------------------------------------------------------

float ingresarFloat(char *);
float ingresarFloat(char *msj){
    char cad[100];
    char c;
    int i = 0;
    float valor = 0;
    printf("%s", msj);
    while((c = getch()) != 13){
        if (c >= '0' && c <= '9'){
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (c == 46) {
            bool aux = false;
            for (int j = 0; cad[j] != '\0'; j++) {
                if (cad[j] == 46){
                    aux = true;
                    break;
                }
            }
            if(aux == false){
                printf("%c", c);
                cad[i++] = c;
            }
        }
    }
    cad[i++] = '\0';
    for (int j = 0; cad[j] != '\0'; j++) {
        valor = atof(cad);
    }
    return valor;
}


int main(){
    float imprimir = ingresarFloat("ingrese un valor entero: ");
    cout << endl;
    cout << imprimir << endl;
}
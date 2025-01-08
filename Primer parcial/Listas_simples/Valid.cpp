#include "Valid.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

int ingresar(char* msj) {
    char cad[10];
    char c;
    int i = 0, valor = 0;
    printf("%s", msj);
    while ((c = getch()) != 13) {  // 13 es el c�digo ASCII de Enter
        if (c >= '0' && c <= '9') {  // Solo se aceptan d�gitos
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8 && i > 0) {  // Backspace para borrar caracteres
            printf("\b \b");
            i--;
        }
    }
    cad[i] = '\0';  // Terminador de cadena
    valor = atoi(cad);  // Conversi�n a entero
    return valor;
}

char ingresarLetra(char* msj) {
    char c;
    printf("%s", msj);
    while (true) {
        c = getch();  // Captura de car�cter
        if (isalpha(c)) {  // Verifica si es una letra
            printf("%c", c);
            return c;
        } else if (c == 8) {  // Backspace
            printf("\b \b");
        }
    }
}

float ingresarFloat(char* msj) {
    char cad[10];
    char c;
    int i = 0;
    printf("%s", msj);
    while ((c = getch()) != 13) {  // 13 es el c�digo ASCII de Enter
        if ((c >= '0' && c <= '9') || (c == '.' && strchr(cad, '.') == nullptr)) {
            // Acepta d�gitos y un �nico punto decimal
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8 && i > 0) {  // Backspace
            printf("\b \b");
            i--;
        }
    }
    cad[i] = '\0';  // Terminador de cadena
    return atof(cad);  // Conversi�n a flotante
}

std::string ingresarString(char* msj) {
    char cad[10];
    char c;
    int i = 0;
    std::string valor;
    printf("%s", msj);
    while ((c = getch()) != 13) {  // 13 es el c�digo ASCII de Enter
        if (isalpha(c)) {  // Solo letras
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8 && i > 0) {  // Backspace
            printf("\b \b");
            i--;
        }
    }
    cad[i] = '\0';  // Terminador de cadena
    valor = cad;  // Conversi�n a string
    return valor;
}

double ingresarDouble(char* msj) {
    char cad[20];
    char c;
    int i = 0;
    double valor = 0;
    bool puntoDecimal = false;
    printf("%s", msj);
    while ((c = getch()) != 13) {  // 13 es el c�digo ASCII de Enter
        if (c >= '0' && c <= '9') {  // Acepta d�gitos
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8 && i > 0) {  // Backspace
            printf("\b \b");
            i--;
        } else if (c == '.' && !puntoDecimal) {  // Acepta un �nico punto decimal
            puntoDecimal = true;
            printf("%c", c);
            cad[i++] = c;
        }
    }
    cad[i] = '\0';  // Terminador de cadena
    valor = atof(cad);  // Conversi�n a double
    return valor;
}

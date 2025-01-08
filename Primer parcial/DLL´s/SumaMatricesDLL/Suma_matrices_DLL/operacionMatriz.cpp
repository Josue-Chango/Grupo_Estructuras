#define MI_DLL_EXPORTS
#include "operacionMatriz.h"


int sumaRecursivaMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int f, int c) {
    if (f == 0 && c == 0) {
        return mat1[f][c] + mat2[f][c];  // Base case: Sumar el primer elemento
    } else {
        if (c >= 0) {
            return mat1[f][c] + mat2[f][c] + sumaRecursivaMatrices(mat1, mat2, f, c - 1);
        } else if (f > 0) {
            return sumaRecursivaMatrices(mat1, mat2, f - 1, MAX - 1);
        }
    }
    return 0;  // Solo un valor predeterminado en caso de error
}

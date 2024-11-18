#include <iostream> // Asegúrate de incluir este encabezado
#include <windows.h>

using namespace std; // Esto hace que no sea necesario usar std:: antes de objetos estándar

#define MAX 3

// Definir el tipo de puntero a la función que vamos a cargar desde la DLL
typedef int (*SumaMatricesFunc)(int[MAX][MAX], int[MAX][MAX], int, int);

void imprimirMatriz(int mat[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // Cargar la DLL
    HINSTANCE hDLL = LoadLibrary("Suma_matrices_DLL.dll");  // Se usa LoadLibrary de windows.h
    if (!hDLL) {
        cerr << "No se pudo cargar la DLL.\n";  // Muestra error en caso de no cargar la DLL
        return 1;
    }

    // Obtener la dirección de la función sumaRecursivaMatrices
    SumaMatricesFunc sumaRecursivaMatrices = (SumaMatricesFunc)GetProcAddress(hDLL, "sumaRecursivaMatrices");
    if (!sumaRecursivaMatrices) {
        cerr << "No se pudo encontrar la función en la DLL.\n";  // Error si no se encuentra la función
        FreeLibrary(hDLL);  // Liberar la DLL en caso de error
        return 1;
    }

    // Crear matrices de prueba
    int mat1[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[MAX][MAX] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Imprimir las matrices antes de la suma
    cout << "Matriz 1:" << endl;
    imprimirMatriz(mat1);

    cout << "Matriz 2:" << endl;
    imprimirMatriz(mat2);

    // Llamar a la función importada de la DLL para sumar las matrices
    int suma = sumaRecursivaMatrices(mat1, mat2, MAX - 1, MAX - 1);

    // Mostrar el resultado de la suma
    cout << "\nLa suma recursiva de las matrices es: " << suma << endl;

    // Liberar la DLL
    FreeLibrary(hDLL);  // Siempre liberar la DLL después de usarla

    return 0;

    return 0;
}


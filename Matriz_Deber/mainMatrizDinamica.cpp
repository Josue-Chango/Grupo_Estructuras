#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.cpp"

using namespace std;




int main(int argc, char** argv) {
    int** mat1 = new int*[3];
    int** mat2 = new int*[3];

    for (int i = 0; i < 3; i++) {
        *(mat1+i) = new int[3];
        *(mat2+i) = new int[3];
    }

    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(mat1+i)+j) = (int)((rand() / 32768.1) * 1000);
            *(*(mat2+i)+j) = (int)((rand() / 32768.1) * 1000);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *(*(mat1+i)+j) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *(*(mat2+i)+j) << "\t";
        }
        cout << endl;
    }
    cout << "Suma de Matrices es: " << sumaRecursivaMatrices(mat1, mat2, 2, 2) << endl;

    // Liberar la memoria dinámica
    for (int i = 0; i < 3; i++) {
        delete[] *(mat1+i);
        delete[] *(mat2+i);
    }
    system("pause");
    delete[] mat1;
    delete[] mat2;

    return 0;
}



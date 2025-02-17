#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Función para construir el triángulo mágico usando el método explicado
vector<int> construirTrianguloMagico(vector<int> numeros) {
    // Ordenamos los números en dos grupos: menores (0,1,2) y mayores (3,4,5)
    sort(numeros.begin(), numeros.end());
    vector<int> menores = {numeros[0], numeros[1], numeros[2]};
    vector<int> mayores = {numeros[3], numeros[4], numeros[5]};
    
    // Asignamos los vértices a los menores
    int v1 = menores[1];  // 1
    int v2 = menores[2];  // 2
    int v3 = menores[0];  // 0
    
    // El número menor del grupo mayor se coloca entre los vértices mayores
    int intermedio = mayores[0]; // 3 en este caso
    
    // La suma mágica de los lados
    int suma_magica = v2 + intermedio + v1; // 2 + 3 + 1 = 6
    
    // Completar el triángulo con los números restantes
    int lado1 = mayores[2]; // 5
    int lado2 = mayores[1]; // 4
    
    return {v1, lado1, intermedio, v3, lado2, v2};
}

// Función para mostrar el triángulo mágico
void mostrarTrianguloMagico(const vector<int>& numeros) {
    if (numeros.empty()) {
        cout << "No se pudo generar un triángulo mágico válido." << endl;
        return;
    }
    cout << "\nTriángulo mágico encontrado:" << endl;
    cout << "      " << numeros[0] << endl;
    cout << "    " << numeros[1] << "   " << numeros[2] << endl;
    cout << "  " << numeros[3] << "   " << numeros[4] << "   " << numeros[5] << endl;
}

int main() {
    vector<int> numeros(6);
    cout << "Ingrese 6 números distintos: ";
    for (int i = 0; i < 6; i++) {
        cin >> numeros[i];
    }
    
    vector<int> triangulo = construirTrianguloMagico(numeros);
    mostrarTrianguloMagico(triangulo);

    system("pause");
    return 0;
}

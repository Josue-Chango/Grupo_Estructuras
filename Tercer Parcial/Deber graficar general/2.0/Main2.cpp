#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <functional>

using namespace std;
using namespace std::chrono;

// ------------------ PROTOTIPO GENERAL ------------------
void measureExecutionTime(function<void(int)> func, const string& name, int size);

// ------------------ FUNCIONES DE ORDENAMIENTO ------------------
// Generar datos aleatorios de tamaño "size"
vector<int> generateRandomData(int size, int minVal, int maxVal) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minVal, maxVal);

    vector<int> data(size);
    for (int& val : data) {
        val = dist(gen);
    }
    return data;
}

// Bubble Sort
void bubbleSort(int size) {
    vector<int> arr = generateRandomData(size, 1, 100000);
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortWrapper(int size) {
    vector<int> arr = generateRandomData(size, 1, 100000);
    quickSort(arr, 0, arr.size() - 1);
}

// ------------------ FUNCIONES DE ESTRUCTURAS ------------------
// Insertar elementos en una lista enlazada
void insertIntoList(int size) {
    list<int> lst;
    for (int i = 0; i < size; i++) {
        lst.push_back(rand() % 100000);
    }
}

// Simulación de inserción en un árbol binario (usamos vector como estructura simple)
void insertIntoTree(int size) {
    vector<int> tree;
    for (int i = 0; i < size; i++) {
        tree.push_back(rand() % 100000);
    }
}

// ------------------ MEDICIÓN DE TIEMPOS ------------------
void measureExecutionTime(function<void(int)> func, const string& name, int size) {
    ofstream file("resultados.csv", ios::app); // Modo append para no sobrescribir
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    auto start = high_resolution_clock::now();
    func(size); // Ejecutar la función con el tamaño proporcionado
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << name << " (" << size << ") tomó " << duration.count() << " microsegundos.\n";
    file << name << "," << size << "," << duration.count() << "\n";
    file.close();
}

// ------------------ PROGRAMA PRINCIPAL ------------------
int main() {
    // Lista de tamaños a evaluar
    vector<int> sizes = {1000, 2000, 5000, 10000, 20000, 50000};

    // Crear archivo CSV con encabezado
    ofstream file("resultados.csv");
    file << "Estructura/Tarea,Tamaño,Tiempo (microsegundos)\n";
    file.close();

    cout << "Ejecutando medición de tiempos...\n";

    for (int size : sizes) {
        measureExecutionTime(bubbleSort, "Bubble Sort", size);
        measureExecutionTime(quickSortWrapper, "Quick Sort", size);
        measureExecutionTime(insertIntoList, "Inserción en Lista Enlazada", size);
        measureExecutionTime(insertIntoTree, "Inserción en Árbol Binario", size);
    }

    cout << "Datos guardados en resultados.csv\n";

    // Intentar ejecutar MATLAB o Python para graficar
    int matlabStatus = system("matlab -r \"graficar_tiempos\"");
    if (matlabStatus != 0) {
        cout << "MATLAB no encontrado, intentando graficar con Python..." << endl;
        system("python graficar.py");
    }

    cout << "Presiona Enter para salir...";
    cin.get();
    return 0;
}

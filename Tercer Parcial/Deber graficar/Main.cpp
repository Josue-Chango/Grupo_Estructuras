/*#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <fstream>  // Para guardar datos en un archivo
#include <cstdlib>  // Para ejecutar MATLAB desde C++

using namespace std;
using namespace std::chrono;

// Prototipos de funciones
void bubbleSort(vector<int>& arr);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void measureExecutionTime(const function<void(vector<int>&)>& func, vector<int> arr, const string& name, ofstream& file);
void quickSortWrapper(vector<int>& arr);

// Implementaciones de funciones
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Funcion envolvente para Quick Sort
void quickSortWrapper(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// Funcion para medir tiempo y guardar en archivo
void measureExecutionTime(const function<void(vector<int>&)>& func, vector<int> arr, const string& name, ofstream& file) {
    auto start = high_resolution_clock::now();
    func(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);  // Medir en milisegundos



    cout << name << " tomo " << duration.count() << " microsegundos.\n";
    //cout << "Duracion: " << stop - start << " nanosegundos." << endl;  // Mostrar en nanosegundos para ver más detalle

    file << name << "," << duration.count() << "\n";  // Guardar en archivo
}


int main() {
    vector<int> data(100000, 5);  // Más elementos en el arreglo

    ofstream file("resultados.txt");  // Archivo para almacenar los tiempos
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    cout << "Ejecutando medicion de tiempos..." << endl;
    file << "Algoritmo,Tiempo (microsegundos)\n";
    
    measureExecutionTime(bubbleSort, data, "Bubble Sort", file);
    measureExecutionTime(quickSortWrapper, data, "Quick Sort", file);
    
    file.close();
    system("pause");
    cout << "Datos guardados en resultados.txt\n";

    // Ejecutar MATLAB y graficar los resultados
    system("matlab -r \"graficar_tiempos\"");
    system("pause");
    return 0;
}

*/




/*#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <fstream>
#include <cstdlib>  
#include <random>   // Para generar números aleatorios

using namespace std;
using namespace std::chrono;

// Prototipos de funciones
void bubbleSort(vector<int>& arr);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void quickSortWrapper(vector<int>& arr);
void measureExecutionTime(const function<void(vector<int>&)>& func, vector<int>& arr, const string& name, ofstream& file);
void generateRandomData(vector<int>& data, int size, int minVal, int maxVal);

// Implementaciones de funciones
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Funcion envolvente para Quick Sort
void quickSortWrapper(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// Funcion para medir tiempo y guardar en archivo (pasando vector por referencia)
void measureExecutionTime(const function<void(vector<int>&)>& func, vector<int>& arr, const string& name, ofstream& file) {
    vector<int> copy = arr;  // Crear una copia para mantener la misma entrada para cada algoritmo
    auto start = high_resolution_clock::now();
    func(copy);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << name << " tomo " << duration.count() << " microsegundos.\n";
    file << name << "," << duration.count() << "\n";  // Guardar en archivo
}

// Genera un vector con valores aleatorios
void generateRandomData(vector<int>& data, int size, int minVal, int maxVal) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minVal, maxVal);
    
    data.clear();
    data.reserve(size);
    for (int i = 0; i < size; i++) {
        data.push_back(dist(gen));
    }
}

int main() {
    vector<int> data;
    generateRandomData(data, 10000, 1, 100000);  // Generar 10,000 números aleatorios entre 1 y 100,000

    ofstream file("resultados.txt");  // Archivo para almacenar los tiempos
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    cout << "Ejecutando medicion de tiempos..." << endl;
    file << "Algoritmo,Tiempo (microsegundos)\n";

    measureExecutionTime(bubbleSort, data, "Bubble Sort", file);
    measureExecutionTime(quickSortWrapper, data, "Quick Sort", file);

    file.close();
    cout << "Datos guardados en resultados.txt\n";

    // Ejecutar MATLAB si está disponible
    int matlabStatus = system("matlab -r \"graficar_tiempos\"");

    if (matlabStatus != 0) {
        cerr << "No se pudo ejecutar MATLAB. Asegúrate de que está instalado y configurado correctamente.\n";
    }

    cout << "Presiona Enter para salir...";
    cin.get();  // Espera entrada del usuario en lugar de system("pause")

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <random>

using namespace std;
using namespace std::chrono;

// Prototipos de funciones
void bubbleSort(vector<int>& arr);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void quickSortWrapper(vector<int>& arr);
void measureExecutionTime(void (*func)(vector<int>&), vector<int>& arr, const string& name, ofstream& file);
void generateRandomData(vector<int>& data, int size, int minVal, int maxVal);

// Implementaciones
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortWrapper(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

void measureExecutionTime(void (*func)(vector<int>&), vector<int>& arr, const string& name, ofstream& file) {
    vector<int> copy = arr;
    auto start = high_resolution_clock::now();
    func(copy);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << name << " tomo " << duration.count() << " microsegundos.\n";
    file << name << "," << arr.size() << "," << duration.count() << "\n";
}

void generateRandomData(vector<int>& data, int size, int minVal, int maxVal) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minVal, maxVal);
    
    data.clear();
    data.reserve(size);
    for (int i = 0; i < size; i++) {
        data.push_back(dist(gen));
    }
}

int main() {
    vector<int> sizes = {1000, 2000, 5000, 10000, 20000, 50000};
    ofstream file("resultados.csv");
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    cout << "Ejecutando medicion de tiempos..." << endl;
    file << "Algoritmo,Tamaño,Tiempo (microsegundos)\n";
    
    for (int size : sizes) {
        vector<int> data;
        generateRandomData(data, size, 1, 100000);
        measureExecutionTime(bubbleSort, data, "Bubble Sort", file);
        measureExecutionTime(quickSortWrapper, data, "Quick Sort", file);
    }

    file.close();
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

/*#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <functional>
//#include <Lista_Simple-Proyecto>

using namespace std;
using namespace std::chrono;

class Main2 {
public:
    // ------------------ FUNCIONES DE ORDENAMIENTO ------------------
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
    void insertIntoList(int size) {
        list<int> lst;
        for (int i = 0; i < size; i++) {
            lst.push_back(rand() % 100000);
        }
    }

    void insertIntoTree(int size) {
        vector<int> tree;
        for (int i = 0; i < size; i++) {
            tree.push_back(rand() % 100000);
        }
    }
};

// ------------------ MEDICIoN DE TIEMPOS ------------------
void measureExecutionTime(function<void()> func, const string& name, int size) {
    ofstream file("resultados.csv", ios::app);
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    auto start = high_resolution_clock::now();
    func(); // Ejecutar la funcion
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Asegurar que el tamaño se guarda correctamente en el CSV
    cout << name << " (" << size << ") tomo " << duration.count() << " microsegundos.\n";
    file << name << "," << size << "," << duration.count() << "\n";
    file.close();
}

// ------------------ PROGRAMA PRINCIPAL ------------------
int main() {
    vector<int> sizes = {1000, 2000, 5000, 10000, 20000, 50000};
    Main2 objeto;
    //Lista_Simple_Proyecto<string> listaAutos;
    // Crear archivo CSV con encabezado
    ofstream file("resultados.csv");
    file << "Estructura/Tarea,Tamaño,Tiempo (microsegundos)\n";
    file.close();

    //listaAutos.insertar("ABC-123", "Toyota");
        //listaAutos.insertar("XYZ-789", "Honda");
        //listaAutos.insertar("DEF-456", "Ford");

        // Placa a buscar
        string placaBusqueda = "ABC-123";

    cout << "Ejecutando medicion de tiempos...\n";

    for (int size : sizes) {
        measureExecutionTime([&]() { objeto.bubbleSort(size); }, "Bubble Sort", size);
        measureExecutionTime([&]() { objeto.quickSortWrapper(size); }, "Quick Sort", size);
        measureExecutionTime([&]() { objeto.insertIntoList(size); }, "Insercion en Lista Enlazada", size);
        measureExecutionTime([&]() { objeto.insertIntoTree(size); }, "Insercion en Árbol Binario", size);
        //measureExecutionTime([&]() { listaAutos.buscarPorPlaca(placaBusqueda); }, "Buscar Auto por Placa", size);
    }

    cout << "Datos guardados en resultados.csv\n";

    // Intentar ejecutar MATLAB o Python para graficar
    int matlabStatus = system("matlab -r \"graficar_tiempos3\"");
    system("Complejidad.py");
    if (matlabStatus != 0) {
        cout << "MATLAB no encontrado, intentando graficar con Python..." << endl;
        system("python graficar.py");
    }

    cout << "Presiona Enter para salir...";
    cin.get();
    return 0;
}
*/

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

class Main2 {
public:
    // ------------------ FUNCIONES DE ORDENAMIENTO ------------------
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
    void insertIntoList(int size) {
        list<int> lst;
        for (int i = 0; i < size; i++) {
            lst.push_back(rand() % 100000);
        }
    }

    void insertIntoTree(int size) {
        vector<int> tree;
        for (int i = 0; i < size; i++) {
            tree.push_back(rand() % 100000);
        }
    }

    // ------------------ FUNCIoN DE BÚSQUEDA ------------------
    void buscarPorPlaca(string placa) {
        // Simulacion de búsqueda (sin lista real)
        for (volatile int i = 0; i < 100000; i++) {
            if (to_string(i) == placa) {
                break;
            }
        }
    }
};

// ------------------ MEDICIoN DE TIEMPOS ------------------
void measureExecutionTime(function<void()> func, const string& name, int size) {
    ofstream file("resultados.csv", ios::app);
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    auto start = high_resolution_clock::now();
    func(); // Ejecutar la funcion
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Asegurar que el tamaño se guarda correctamente en el CSV
    cout << name << " (" << size << ") tomo " << duration.count() << " microsegundos.\n";
    file << name << "," << size << "," << duration.count() << "\n";
    file.close();
}

// ------------------ PROGRAMA PRINCIPAL ------------------
int main() {
    vector<int> sizes = {1000, 2000, 5000, 10000, 20000, 50000};
    Main2 objeto;

    // Crear archivo CSV con encabezado
    ofstream file("resultados.csv");
    file << "Estructura/Tarea,Tamaño,Tiempo (microsegundos)\n";
    file.close();

    cout << "Ejecutando medicion de tiempos...\n";

    for (int size : sizes) {
        measureExecutionTime([&]() { objeto.bubbleSort(size); }, "Bubble Sort", size);
        measureExecutionTime([&]() { objeto.quickSortWrapper(size); }, "Quick Sort", size);
        measureExecutionTime([&]() { objeto.insertIntoList(size); }, "Insercion en Lista Enlazada", size);
        measureExecutionTime([&]() { objeto.insertIntoTree(size); }, "Insercion en Árbol Binario", size);
    }

    // Medir el tiempo de búsqueda con una placa aleatoria
    vector<string> placasRegistradas = {"ABC-123", "XYZ-789", "DEF-456"};
    string placaAleatoria = placasRegistradas[rand() % placasRegistradas.size()];
    measureExecutionTime([&]() { objeto.buscarPorPlaca(placaAleatoria); }, "Búsqueda de Auto", 0);

    cout << "Datos guardados en resultados.csv\n";

    // Intentar ejecutar MATLAB o Python para graficar y analizar complejidad
    int matlabStatus = system("matlab -r \"analizar_complejidad\"");
    system("Complejidad.py");
    if (matlabStatus != 0) {
        cout << "MATLAB no encontrado, intentando graficar con Python..." << endl;
        system("Complejidad.py");
    }

    cout << "Presiona Enter para salir...";
    cin.get();
    return 0;
}

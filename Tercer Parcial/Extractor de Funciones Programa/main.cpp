#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <filesystem>
#include "FunctionExtractor.h"

using namespace std;
namespace fs = std::filesystem;

// Definición de tipos para la DLL
typedef void (*ExtractFunc)(const char*, char***, int*);
typedef void (*FreeFunc)(char**, int);

// Cargar la DLL y extraer funciones de los archivos
vector<string> extractFunctionsFromProject(const string& projectPath) {
    vector<string> allFunctions;
    
    // Cargar la DLL
    HINSTANCE hDLL = LoadLibrary("FunctionExtractor.dll");
    if (!hDLL) {
        cerr << "Error al cargar la DLL." << endl;
        return allFunctions;
    }

    ExtractFunc extractFunctionNames = (ExtractFunc)GetProcAddress(hDLL, "extractFunctionNames");
    FreeFunc freeFunctionNames = (FreeFunc)GetProcAddress(hDLL, "freeFunctionNames");

    if (!extractFunctionNames || !freeFunctionNames) {
        cerr << "Error al obtener funciones de la DLL." << endl;
        FreeLibrary(hDLL);
        return allFunctions;
    }

    // Recorrer todos los archivos .cpp en la carpeta
    for (const auto& entry : fs::recursive_directory_iterator(projectPath)) {
        if (entry.path().extension() == ".cpp") {
            char** functions;
            int count;
            extractFunctionNames(entry.path().string().c_str(), &functions, &count);

            cout << "Archivo: " << entry.path().filename() << endl;
            for (int i = 0; i < count; i++) {
                cout << "  - " << functions[i] << endl;
                allFunctions.push_back(functions[i]);
            }

            freeFunctionNames(functions, count);
        }
    }

    FreeLibrary(hDLL);
    return allFunctions;
}

// Medir el tiempo de ejecución de una función simulada
void measureExecutionTime(const string& functionName, ofstream& file) {
    auto start = chrono::high_resolution_clock::now();

    // Simulación de ejecución de función
    for (int i = 0; i < 1000000; i++); 

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    file << functionName << "," << duration.count() << "\n";
}

// Analizar la complejidad Big O de una función simulada
string analyzeBigO(const string& function) {
    if (function.find("bubbleSort") != string::npos) return "O(n^2)";
    if (function.find("quickSort") != string::npos) return "O(n log n)";
    return "O(?)"; // Desconocido
}

int main() {
    string projectPath;
    cout << "Ingrese la ruta del proyecto: ";
    getline(cin, projectPath);

    // Extraer funciones del proyecto
    vector<string> functions = extractFunctionsFromProject(projectPath);

    if (functions.empty()) {
        cout << "No se encontraron funciones en el proyecto." << endl;
        return 1;
    }

    // Guardar análisis de funciones en un archivo CSV
    ofstream file("resultados.csv");
    if (!file) {
        cerr << "Error al abrir el archivo de resultados." << endl;
        return 1;
    }

    file << "Funcion,Tiempo (microsegundos),Complejidad\n";
    for (const auto& func : functions) {
        string complexity = analyzeBigO(func);
        measureExecutionTime(func, file);
        file << func << "," << complexity << "\n";
    }
    file.close();
    cout << "Datos guardados en resultados.csv\n";

    // Ejecutar MATLAB o Python para graficar
    int matlabStatus = system("matlab -r \"graficar_tiempos\"");
    if (matlabStatus != 0) {
        cout << "MATLAB no encontrado, intentando graficar con Python..." << endl;
        system("python graficar.py");
    }

    system("pause");

    return 0;
}

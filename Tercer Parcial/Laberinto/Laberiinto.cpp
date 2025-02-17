/*#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Función para inicializar el laberinto con paredes (0)
void inicializarMatriz(vector<vector<int>> &matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0; // Inicialmente todo es pared
        }
    }
}

// Función para generar un camino dentro del laberinto
void generarCamino(vector<vector<int>> &matriz, int n) {
    int x = 1, y = 1; // Empezamos en una posición dentro de los límites
    matriz[x][y] = 1; // Punto inicial
    
    srand(time(0));
    
    for (int i = 0; i < (n * n) / 2; i++) { // Generar caminos aleatorios
        int direccion = rand() % 4;
        
        switch (direccion) {
            case 0: if (x - 2 > 0) { matriz[x - 1][y] = 1; matriz[x - 2][y] = 1; x -= 2; } break; // Arriba
            case 1: if (x + 2 < n - 1) { matriz[x + 1][y] = 1; matriz[x + 2][y] = 1; x += 2; } break; // Abajo
            case 2: if (y - 2 > 0) { matriz[x][y - 1] = 1; matriz[x][y - 2] = 1; y -= 2; } break; // Izquierda
            case 3: if (y + 2 < n - 1) { matriz[x][y + 1] = 1; matriz[x][y + 2] = 1; y += 2; } break; // Derecha
        }
    }
}

// Función para imprimir la matriz en consola
void imprimirMatriz(const vector<vector<int>> &matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para guardar la matriz en un archivo
void guardarMatrizEnArchivo(const vector<vector<int>> &matriz, int n, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                archivo << matriz[i][j] << " ";
            }
            archivo << endl;
        }
        archivo.close();
        cout << "Laberinto guardado en " << nombreArchivo << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño del laberinto (n x n): ";
    cin >> n;
    
    if (n < 5) {
        cout << "El tamaño del laberinto debe ser al menos 5x5." << endl;
        system("pause");
        return 1;
    }
    system("pause");
    vector<vector<int>> laberinto(n, vector<int>(n));
    inicializarMatriz(laberinto, n);
    generarCamino(laberinto, n);
    imprimirMatriz(laberinto, n);
    guardarMatrizEnArchivo(laberinto, n, "laberinto.txt");
    system("pause");
    return 0;
}*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*
/*#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

// Dirección de movimiento (arriba, abajo, izquierda, derecha)
const int dx[] = {-2, 2, 0, 0};
const int dy[] = {0, 0, -2, 2};

// Función para inicializar el laberinto con paredes (0)
void inicializarMatriz(vector<vector<int>> &matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0; // Inicialmente todo es pared
        }
    }
}

// Función para verificar si una celda está dentro de los límites y es una pared
bool esValido(int x, int y, int n, vector<vector<int>> &matriz) {
    return (x > 0 && x < n - 1 && y > 0 && y < n - 1 && matriz[x][y] == 0);
}

// Generación de laberinto con DFS para asegurar solución única
void generarLaberinto(vector<vector<int>> &matriz, int n) {
    stack<pair<int, int>> pila;
    pila.push({1, 1}); // Comenzamos en (1,1)
    matriz[1][1] = 1; // Marcamos como camino
    srand(time(0));
    
    while (!pila.empty()) {
        int x = pila.top().first;
        int y = pila.top().second;
        
        vector<int> dir = {0, 1, 2, 3};
        shuffle(dir.begin(), dir.end(), default_random_engine(time(0))); // Mezclamos direcciones
        bool avanzamos = false;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[dir[i]];
            int ny = y + dy[dir[i]];
            
            if (esValido(nx, ny, n, matriz)) {
                matriz[nx][ny] = 1;
                matriz[x + dx[dir[i]] / 2][y + dy[dir[i]] / 2] = 1; // Abrimos paso intermedio
                pila.push({nx, ny});
                avanzamos = true;
                break;
            }
        }
        
        if (!avanzamos) {
            pila.pop(); // Retrocedemos si no hay camino
        }
    }
    
    // Entrada y salida
    matriz[1][0] = 1; // Entrada
    matriz[n-2][n-1] = 1; // Salida
}

// Función para imprimir la matriz en consola
void imprimirMatriz(const vector<vector<int>> &matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (matriz[i][j] ? "  " : "  "); // Formato visual
        }
        cout << endl;
    }
}

// Función para guardar la matriz en un archivo
void guardarMatrizEnArchivo(const vector<vector<int>> &matriz, int n, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                archivo << matriz[i][j] << " ";
            }
            archivo << endl;
        }
        archivo.close();
        cout << "Laberinto guardado en " << nombreArchivo << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño del laberinto (n x n, impar): ";
    cin >> n;
    
    if (n < 5 || n % 2 == 0) {
        cout << "El tamaño del laberinto debe ser un número impar mayor o igual a 5." << endl;
        system("pause");
        return 1;
    }
    
    vector<vector<int>> laberinto(n, vector<int>(n));
    inicializarMatriz(laberinto, n);
    generarLaberinto(laberinto, n);
    imprimirMatriz(laberinto, n);
    guardarMatrizEnArchivo(laberinto, n, "laberinto.txt");
    system("pause");
    
    return 0;
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

// Dirección de movimiento (arriba, abajo, izquierda, derecha)
const int dx[] = {-2, 2, 0, 0};
const int dy[] = {0, 0, -2, 2};

// Función para inicializar el laberinto con paredes (0)
void inicializarMatriz(vector<vector<int>> &matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0; // Inicialmente todo es pared
        }
    }
}

// Función para verificar si una celda está dentro de los límites y es una pared
bool esValido(int x, int y, int n, vector<vector<int>> &matriz) {
    return (x > 0 && x < n - 1 && y > 0 && y < n - 1 && matriz[x][y] == 0);
}

// Generación de laberinto con DFS con caminos falsos adicionales
void generarLaberinto(vector<vector<int>> &matriz, int n) {
    stack<pair<int, int>> pila;
    pila.push({1, 1}); // Comenzamos en (1,1)
    matriz[1][1] = 1; // Marcamos como camino
    srand(time(0));
    
    while (!pila.empty()) {
        int x = pila.top().first;
        int y = pila.top().second;
        
        vector<int> dir = {0, 1, 2, 3};
        shuffle(dir.begin(), dir.end(), default_random_engine(rand())); // Mezclamos direcciones
        bool avanzamos = false;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[dir[i]];
            int ny = y + dy[dir[i]];
            
            if (esValido(nx, ny, n, matriz)) {
                matriz[nx][ny] = 1;
                matriz[x + dx[dir[i]] / 2][y + dy[dir[i]] / 2] = 1; // Abrimos paso intermedio
                pila.push({nx, ny});
                avanzamos = true;
                break;
            }
        }
        
        if (!avanzamos) {
            pila.pop(); // Retrocedemos si no hay camino
        }
    }
    
    // Agregar caminos falsos aleatorios
    for (int i = 1; i < n - 1; i += 2) {
        for (int j = 1; j < n - 1; j += 2) {
            if (rand() % 3 == 0 && matriz[i][j] == 0) {
                matriz[i][j] = 1; // Agregamos caminos sin conexión a la solución
            }
        }
    }
    
    // Entrada y salida
    matriz[1][0] = 1; // Entrada
    matriz[n-2][n-1] = 1; // Salida
}

// Función para imprimir la matriz en consola
void imprimirMatriz(const vector<vector<int>> &matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (matriz[i][j] ? "  " : "  "); // Formato visual
        }
        cout << endl;
    }
}

// Función para guardar la matriz en un archivo
void guardarMatrizEnArchivo(const vector<vector<int>> &matriz, int n, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                archivo << matriz[i][j] << " ";
            }
            archivo << endl;
        }
        archivo.close();
        cout << "Laberinto guardado en " << nombreArchivo << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño del laberinto (n x n, impar): ";
    cin >> n;
    
    if (n < 5 || n % 2 == 0) {
        cout << "El tamaño del laberinto debe ser un número impar mayor o igual a 5." << endl;
        return 1;
    }
    
    vector<vector<int>> laberinto(n, vector<int>(n));
    inicializarMatriz(laberinto, n);
    generarLaberinto(laberinto, n);
    imprimirMatriz(laberinto, n);
    guardarMatrizEnArchivo(laberinto, n, "laberinto.txt");
    
    return 0;
}*/


// g++ -o Laberinto Laberiinto.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <SFML/Graphics.hpp>

using namespace std;

const int dx[] = {-2, 2, 0, 0};
const int dy[] = {0, 0, -2, 2};

void inicializarMatriz(vector<vector<int>> &matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }
}

bool esValido(int x, int y, int n, vector<vector<int>> &matriz) {
    return (x > 0 && x < n - 1 && y > 0 && y < n - 1 && matriz[x][y] == 0);
}

void generarLaberinto(vector<vector<int>> &matriz, int n) {
    stack<pair<int, int>> pila;
    pila.push({1, 1});
    matriz[1][1] = 1;
    srand(time(0));
    
    while (!pila.empty()) {
        int x = pila.top().first;
        int y = pila.top().second;
        
        vector<int> dir = {0, 1, 2, 3};
        shuffle(dir.begin(), dir.end(), default_random_engine(rand()));
        bool avanzamos = false;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[dir[i]];
            int ny = y + dy[dir[i]];
            
            if (esValido(nx, ny, n, matriz)) {
                matriz[nx][ny] = 1;
                matriz[x + dx[dir[i]] / 2][y + dy[dir[i]] / 2] = 1;
                pila.push({nx, ny});
                avanzamos = true;
                break;
            }
        }
        
        if (!avanzamos) {
            pila.pop();
        }
    }
    
    for (int i = 1; i < n - 1; i += 2) {
        for (int j = 1; j < n - 1; j += 2) {
            if (rand() % 3 == 0 && matriz[i][j] == 0) {
                matriz[i][j] = 1;
            }
        }
    }
    
    matriz[1][0] = 1;
    matriz[n-2][n-1] = 1;
}

void graficarLaberinto(const vector<vector<int>> &matriz, int n) {
    const int cellSize = 20;
    sf::RenderWindow window(sf::VideoMode(n * cellSize, n * cellSize), "Laberinto");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                
                if (matriz[i][j] == 0)
                    cell.setFillColor(sf::Color::Black);
                else
                    cell.setFillColor(sf::Color::White);
                
                window.draw(cell);
            }
        }
        
        window.display();
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño del laberinto (n x n, impar): ";
    cin >> n;
    
    if (n < 5 || n % 2 == 0) {
        cout << "El tamaño del laberinto debe ser un número impar mayor o igual a 5." << endl;
        return 1;
    }
    
    vector<vector<int>> laberinto(n, vector<int>(n));
    inicializarMatriz(laberinto, n);
    generarLaberinto(laberinto, n);
    graficarLaberinto(laberinto, n);
    
    return 0;
}

//g++ CuadradoLatino.cpp -o CuadradoLatino.exe -IC:\SFML\include -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using namespace sf;

// Función para generar un cuadrado latino de tamaño n x n
vector<vector<int>> generarCuadradoLatino(int n) {
    vector<vector<int>> cuadrado(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cuadrado[i][j] = (i + j) % n + 1;

    return cuadrado;
}

int main() {
    int n;
    cout << "Ingrese el tamaño del cuadrado latino: ";
    cin >> n;

    if (n <= 0) {
        cout << "El tamaño debe ser mayor que 0." << endl;
        return 1;
    }

    // Generar el cuadrado latino
    vector<vector<int>> cuadradoLatino = generarCuadradoLatino(n);

    // Parámetros de la ventana
    int cellSize = 60;  // Tamaño de cada celda
    int width = n * cellSize, height = n * cellSize;

    // Crear ventana SFML
    RenderWindow window(VideoMode(width, height), "Cuadrado Latino - SFML");

    // Fuente para los números
    Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        cout << "No se pudo cargar la fuente." << endl;
        return 1;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Limpiar pantalla
        window.clear(Color::White);

        // Dibujar la cuadrícula y los números
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Dibujar rectángulo
                RectangleShape cell(Vector2f(cellSize - 2, cellSize - 2));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor(Color(200, 200, 255));
                cell.setOutlineThickness(2);
                cell.setOutlineColor(Color::Black);
                window.draw(cell);

                // Dibujar número en la celda
                Text text;
                text.setFont(font);
                text.setString(to_string(cuadradoLatino[i][j]));
                text.setCharacterSize(24);
                text.setFillColor(Color::Black);
                text.setPosition(j * cellSize + 20, i * cellSize + 10);
                window.draw(text);
            }
        }

        // Mostrar contenido
        window.display();
    }

    system("pause");
    return 0;
}
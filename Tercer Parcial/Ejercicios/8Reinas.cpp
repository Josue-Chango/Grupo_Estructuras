/*
g++ -o 8Reinas.exe 8Reinas.cpp -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Función para verificar si una reina puede ser colocada en la posición (filas, col)
bool esvalido(std::vector<int>& reinas, int filas, int col) {
    for (int i = 0; i < filas; i++) {
        if (reinas[i] == col || abs(i - filas) == abs(reinas[i] - col))
            return false;
    }
    return true;
}

// Función recursiva para resolver el problema de las 8 reinas
bool solveNreinas(std::vector<int>& reinas, int filas, int N) {
    if (filas == N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (esvalido(reinas, filas, col)) {
            reinas[filas] = col;
            if (solveNreinas(reinas, filas + 1, N))
                return true;
        }
    }

    return false;
}

int main() {
    const int N = 8;
    std::vector<int> reinas(N, -1);

    if (!solveNreinas(reinas, 0, N)) {
        std::cout << "No se encontró una solución" << std::endl;
        return 1;
    }

    // Crea la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(800, 800), "Problema de las 8 reinas");

    // Establece el tamaño de cada casilla
    float cellSize = 800.0f / N;

    // Dibuja el tablero y las reinas
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Dibuja el tablero
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                if ((i + j) % 2 == 0) {
                    cell.setFillColor(sf::Color::White);
                } else {
                    cell.setFillColor(sf::Color::Black);
                }
                window.draw(cell);
            }
        }

        // Dibuja las reinas
        for (int i = 0; i < N; i++) {
            sf::CircleShape queen(cellSize / 2.5f);
            queen.setFillColor(sf::Color::Red);
            queen.setPosition(reinas[i] * cellSize, i * cellSize);
            window.draw(queen);
        }

        window.display();
    }

    return 0;
}*/

/*#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

// Función para verificar si una reina puede ser colocada en la posición (filas, col)
bool esvalido(std::vector<int>& reinas, int filas, int col) {
    for (int i = 0; i < filas; i++) {
        if (reinas[i] == col || abs(i - filas) == abs(reinas[i] - col))
            return false;
    }
    return true;
}

// Función recursiva para resolver el problema de las 8 reinas generando soluciones aleatorias
bool solveNreinas(std::vector<int>& reinas, int filas, int N, std::mt19937& gen) {
    if (filas == N) {
        return true;
    }

    std::vector<int> possibleCols;
    for (int col = 0; col < N; col++) {
        if (esvalido(reinas, filas, col)) {
            possibleCols.push_back(col);
        }
    }

    if (possibleCols.empty()) {
        return false;
    }

    std::shuffle(possibleCols.begin(), possibleCols.end(), gen);
    for (int col : possibleCols) {
        reinas[filas] = col;
        if (solveNreinas(reinas, filas + 1, N, gen)) {
            return true;
        }
    }
    return false;
}

int main() {
    const int N = 8;
    std::vector<int> reinas(N, -1);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Intenta encontrar una solución válida generando diferentes permutaciones aleatorias
    while (!solveNreinas(reinas, 0, N, gen));

    // Crea la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(500, 500), "Problema de las 8 reinas");

    // Establece el tamaño de cada casilla
    float cellSize = 500.0f / N;

    // Dibuja el tablero y las reinas
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                // Genera una nueva solución cuando se presiona la barra espaciadora
                while (!solveNreinas(reinas, 0, N, gen));
            }
        }

        window.clear();

        // Dibuja el tablero
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                if ((i + j) % 2 == 0) {
                    cell.setFillColor(sf::Color::White);
                } else {
                    cell.setFillColor(sf::Color::Black);
                }
                window.draw(cell);
            }
        }

        // Dibuja las reinas
        for (int i = 0; i < N; i++) {
            sf::CircleShape queen(cellSize / 2.5f);
            queen.setFillColor(sf::Color::Red);
            queen.setPosition(reinas[i] * cellSize, i * cellSize);
            window.draw(queen);
        }

        window.display();
    }
    return 0;
}*/


/*#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

// Función para verificar si una reina puede ser colocada en la posición (filas, col)
bool esvalido(std::vector<int>& reinas, int filas, int col) {
    for (int i = 0; i < filas; i++) {
        if (reinas[i] == col || abs(i - filas) == abs(reinas[i] - col))
            return false;
    }
    return true;
}

// Función recursiva para resolver el problema de las 8 reinas generando soluciones paso a paso
bool solveNreinas(std::vector<int>& reinas, int filas, int N, std::mt19937& gen, sf::RenderWindow& window, float cellSize) {
    if (filas == N) {
        return true;
    }

    std::vector<int> possibleCols;
    for (int col = 0; col < N; col++) {
        if (esvalido(reinas, filas, col)) {
            possibleCols.push_back(col);
        }
    }

    if (possibleCols.empty()) {
        return false;
    }

    std::shuffle(possibleCols.begin(), possibleCols.end(), gen);
    for (int col : possibleCols) {
        reinas[filas] = col;
        
        // Visualizar el paso actual
        window.clear();
        
        // Dibuja el tablero
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
                window.draw(cell);
            }
        }
        
        // Dibuja las reinas colocadas hasta el momento
        for (int i = 0; i <= filas; i++) {
            sf::CircleShape queen(cellSize / 2.5f);
            queen.setFillColor(sf::Color::Red);
            queen.setPosition(reinas[i] * cellSize, i * cellSize);
            window.draw(queen);
        }
        
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(550)); // Pausa para visualización
        
        if (solveNreinas(reinas, filas + 1, N, gen, window, cellSize)) {
            return true;
        }
    }
    return false;
}

int main() {
    const int N = 8;
    std::vector<int> reinas(N, -1);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Crea la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(500, 500), "Problema de las 8 reinas - Paso a Paso");
    float cellSize = 500.0f / N;
    
    // Resolver paso a paso
    solveNreinas(reinas, 0, N, gen, window, cellSize);
    
    // Mantener la ventana abierta
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    
    return 0;
}*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

// Función para verificar si una reina puede ser colocada en la posición (filas, col)
bool esvalido(std::vector<int>& reinas, int filas, int col) {
    for (int i = 0; i < filas; i++) {
        if (reinas[i] == col || abs(i - filas) == abs(reinas[i] - col))
            return false;
    }
    return true;
}

void columna(int i, int N, sf::RenderWindow& window, float cellSize){
    for (int j = 0; j < N; j++) {
        sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
        cell.setPosition(j * cellSize, i * cellSize);
        cell.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
        window.draw(cell);
    }
}

// Función recursiva para resolver el problema de las 8 reinas generando soluciones paso a paso
bool solveNreinas(std::vector<int>& reinas, int filas, int N, std::mt19937& gen, sf::RenderWindow& window, float cellSize, sf::Texture& queenTexture) {
    if (filas == N) {
        return true;
    }

    std::vector<int> possibleCols;
    for (int col = 0; col < N; col++) {
        if (esvalido(reinas, filas, col)) {
            possibleCols.push_back(col);
        }
    }

    if (possibleCols.empty()) {
        return false;
    }

    std::shuffle(possibleCols.begin(), possibleCols.end(), gen);
    for (int col : possibleCols) {
        reinas[filas] = col;
        
        // Visualizar el paso actual
        window.clear();
        
        // Dibuja el tablero
        for (int i = 0; i < N; i++) {
            columna(i, N, window, cellSize);
        }

        // Dibuja las reinas usando la imagen cargada
        for (int i = 0; i <= filas; i++) {
            sf::Sprite reinasprite;
            reinasprite.setTexture(queenTexture);
            reinasprite.setScale((cellSize) / queenTexture.getSize().x, (cellSize) / queenTexture.getSize().y);
            reinasprite.setPosition(reinas[i] * cellSize, i * cellSize);
            window.draw(reinasprite);
        }
        
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pausa para visualización
        
        if (solveNreinas(reinas, filas + 1, N, gen, window, cellSize, queenTexture)) {
            return true;
        }
    }
    return false;
}

int main() {
    const int N = 8;
    std::vector<int> reinas(N, -1);

    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Crea la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(500, 500), "Problema de las 8 reinas - Paso a Paso");
    float cellSize = 500.0f / N;
    
    // Cargar la imagen de la reina
    sf::Texture queenTexture;
    if (!queenTexture.loadFromFile("Reina.png")) {
        std::cerr << "Error al cargar la imagen de la reina." << std::endl;
        return -1;
    }
    
    // Resolver paso a paso
    solveNreinas(reinas, 0, N, gen, window, cellSize, queenTexture);

    // Mantener la ventana abierta
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    system("pause");
    return 0;
}


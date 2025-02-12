//g++ -o Caballos.exe Caballos.cpp -lsfml-graphics -lsfml-window-lsfml-system


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

// Movimientos posibles de un caballo en el ajedrez
std::vector<std::pair<int, int>> knightMoves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// Función para verificar si el movimiento es válido
bool isValidMove(int x, int y, int N) {
    // Verificar que el movimiento está dentro del tablero
    return x >= 0 && y >= 0 && x < N && y < N;
}

// Función para obtener los movimientos válidos de un caballo desde una posición
std::vector<std::pair<int, int>> getValidMoves(int x, int y, int N) {
    std::vector<std::pair<int, int>> validMoves;
    for (auto& move : knightMoves) {
        int newX = x + move.first;
        int newY = y + move.second;
        if (isValidMove(newX, newY, N)) {
            validMoves.push_back({newX, newY});
        }
    }
    return validMoves;
}

int main() {
    const int N = 8;  // Tamaño del tablero
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, N - 1);

    // Crear la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(500, 500), "Caballo en el tablero");
    float cellSize = 500.0f / N;

    // Generar una posición aleatoria para el caballo
    int knightX = dis(gen);
    int knightY = dis(gen);

    // Obtener los movimientos válidos del caballo
    std::vector<std::pair<int, int>> validMoves = getValidMoves(knightX, knightY, N);

    // Cargar la imagen del caballo
    sf::Texture knightTexture;
    if (!knightTexture.loadFromFile("Caballo.png")) {
        std::cerr << "Error al cargar la imagen del caballo." << std::endl;
        return -1;
    }

    // Ciclo principal para dibujar el tablero
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
                cell.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
                window.draw(cell);
            }
        }

        // Dibuja el caballo en su posición aleatoria
        sf::Sprite knightSprite;
        knightSprite.setTexture(knightTexture);
        knightSprite.setScale(cellSize / knightTexture.getSize().x, cellSize / knightTexture.getSize().y);
        knightSprite.setPosition(knightX * cellSize, knightY * cellSize);
        window.draw(knightSprite);

        // Dibuja los puntos a donde puede moverse el caballo
        for (const auto& move : validMoves) {
            sf::CircleShape moveCircle(cellSize / 4);
            moveCircle.setFillColor(sf::Color::Green);
            moveCircle.setPosition(move.first * cellSize + cellSize / 4, move.second * cellSize + cellSize / 4);
            window.draw(moveCircle);
        }

        window.display();
    }

    return 0;
}


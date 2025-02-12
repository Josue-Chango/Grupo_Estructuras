//g++ -o grafo grafo.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath> // Se añade cmath para usar cos() y sin()
#include <cstdlib>
#include <ctime>

using namespace std;

const int NODE_COUNT = 6;
const int WINDOW_SIZE = 600;
const float RADIUS = 30.0f;

vector<vector<int>> generateGraph(int n) {
    vector<vector<int>> graph(n, vector<int>(n, 0));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rand() % 2) {
                graph[i][j] = graph[j][i] = 1;
            }
        }
    }
    return graph;
}

bool isValid(vector<vector<int>> &graph, vector<int> &colors, int node, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool colorGraph(vector<vector<int>> &graph, vector<int> &colors, int node, int maxColors) {
    if (node == graph.size()) return true;
    for (int c = 1; c <= maxColors; c++) {
        if (isValid(graph, colors, node, c)) {
            colors[node] = c;
            if (colorGraph(graph, colors, node + 1, maxColors)) return true;
            colors[node] = 0;
        }
    }
    return false;
}

vector<sf::Color> generateColors() {
    return {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan};
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Graph Coloring with SFML");
    vector<vector<int>> graph = generateGraph(NODE_COUNT);
    vector<int> colors(NODE_COUNT, 0);
    colorGraph(graph, colors, 0, 4);
    vector<sf::Color> colorPalette = generateColors();
    vector<sf::Vector2f> positions;
    float angleStep = 360.0f / NODE_COUNT;

    for (int i = 0; i < NODE_COUNT; i++) {
        float angle = angleStep * i * M_PI / 180.0f; // Se usa M_PI en lugar de 3.14159f
        positions.push_back(sf::Vector2f(WINDOW_SIZE / 2 + cos(angle) * 200, WINDOW_SIZE / 2 + sin(angle) * 200));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);

        for (int i = 0; i < NODE_COUNT; i++) {
            for (int j = i + 1; j < NODE_COUNT; j++) {
                if (graph[i][j]) {
                    sf::Vertex line[] = {
                        sf::Vertex(positions[i], sf::Color::Black),
                        sf::Vertex(positions[j], sf::Color::Black)
                    };
                    window.draw(line, 2, sf::Lines);
                }
            }
        }

        for (int i = 0; i < NODE_COUNT; i++) {
            sf::CircleShape node(RADIUS);
            node.setFillColor(colorPalette[colors[i] - 1]);
            node.setPosition(positions[i].x - RADIUS, positions[i].y - RADIUS);
            window.draw(node);
        }

        window.display();
    }
    return 0;
}

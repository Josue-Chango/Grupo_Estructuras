// g++ -o Triangulo Triangulo_Magico.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++11


#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

const int CIRCLE_RADIUS = 25;
const int OFFSET_X = 400;
const int OFFSET_Y = 100;
const int SPACING = 10;

vector<vector<int>> resolverTrianguloMagico(int n) {
    vector<vector<int>> triangulo(n);
    for (int i = 0; i < n; i++) {
        triangulo[i].resize(i + 1, 0);
    }

    int num = 1, i = 0, j = n / 2;
    for (int num = 1; num <= (n * (n + 1)) / 2; num++) {
        if (i < n && j < triangulo[i].size()) {
            triangulo[i][j] = num;
        }
        int ni = i - 1;
        int nj = j + 1;
        
        if (ni < 0 || nj >= triangulo[ni].size() || triangulo[ni][nj] != 0 || ni >= n) {
            i++;
        } else {
            i = ni;
            j = nj;
        }
    }
    return triangulo;
}

void dibujarTrianguloMagico(sf::RenderWindow& window, const vector<vector<int>>& triangulo) {
    window.clear(sf::Color::White);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Error cargando la fuente!" << endl;
        return;
    }

    for (size_t i = 0; i < triangulo.size(); i++) {
        for (size_t j = 0; j < triangulo[i].size(); j++) {
            if (triangulo[i][j] == 0) continue;
            
            sf::CircleShape circle(CIRCLE_RADIUS);
            circle.setFillColor(sf::Color::White);
            circle.setOutlineColor(sf::Color::Black);
            circle.setOutlineThickness(2);
            circle.setPosition(OFFSET_X + j * (2 * CIRCLE_RADIUS + SPACING) - (i * CIRCLE_RADIUS),
                               OFFSET_Y + i * (2 * CIRCLE_RADIUS + SPACING));
            
            sf::Text text;
            text.setFont(font);
            text.setString(to_string(triangulo[i][j]));
            text.setCharacterSize(18);
            text.setFillColor(sf::Color::Black);
            text.setPosition(OFFSET_X + j * (2 * CIRCLE_RADIUS + SPACING) - (i * CIRCLE_RADIUS) + CIRCLE_RADIUS / 2,
                             OFFSET_Y + i * (2 * CIRCLE_RADIUS + SPACING) + CIRCLE_RADIUS / 2);

            window.draw(circle);
            window.draw(text);
        }
    }
    window.display();
}

int main() {
    int n;
    cout << "Ingrese el tamaño impar del triángulo mágico: ";
    cin >> n;
    if (n % 2 == 0 || n < 1) {
        cout << "Solo se admiten números impares positivos." << endl;
        return 1;
    }
    
    vector<vector<int>> triangulo = resolverTrianguloMagico(n);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Triángulo Mágico");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        dibujarTrianguloMagico(window, triangulo);
    }
    return 0;
}

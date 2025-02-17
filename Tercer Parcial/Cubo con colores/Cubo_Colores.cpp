/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

char cube[6][3][3] = {
    {{'AZ', 'AZ', 'AZ'}, {'AZ', 'AZ', 'AZ'}, {'AZ', 'AZ', 'AZ'}}, // Arriba
    {{'A', 'A', 'A'}, {'A', 'A', 'A'}, {'A', 'A', 'A'}}, // Abajo
    {{'V', 'V', 'V'}, {'V', 'V', 'V'}, {'V', 'V', 'V'}}, // Frente
    {{'AZ', 'AZ', 'AZ'}, {'AZ', 'AZ', 'AZ'}, {'AZ', 'AZ', 'AZ'}}, // Atrás
    {{'N', 'N', 'N'}, {'N', 'N', 'N'}, {'N', 'N', 'N'}}, // Izquierda
    {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}}  // Derecha
};

void mostrarCubo() {
    for (int i = 0; i < 6; i++) {
        cout << "Cara " << i << ":" << endl;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << cube[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void rotarCara(int cara) {
    char temp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[j][2 - i] = cube[cara][i][j];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[cara][i][j] = temp[i][j];
}

int main() {
    cout << "Cubo de Rubik inicial:" << endl;
    mostrarCubo();
    
    cout << "Rotando la cara frontal..." << endl;
    rotarCara(2); // Rotar la cara frontal
    mostrarCubo();
    system("pause");
    return 0;
}
*/

// g++ -o CuboCol Cubo_Colores.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

const int SIZE = 3;
char cube[6][SIZE][SIZE] = {
    {{'AZ', 'AZ', 'AZ'}, {'AZ', 'AZ', 'AZ'}, {'AZ', 'AZ', 'AZ'}}, // Arriba
    {{'A', 'A', 'A'}, {'A', 'A', 'A'}, {'A', 'A', 'A'}}, // Abajo
    {{'V', 'V', 'V'}, {'V', 'V', 'V'}, {'V', 'V', 'V'}}, // Frente
    {{'AZ', 'AZ', 'AZ'}, {'AZ', 'AZ', 'AZ'}, {'AZ', 'AZ', 'AZ'}}, // Atrás
    {{'N', 'N', 'N'}, {'N', 'N', 'N'}, {'N', 'N', 'N'}}, // Izquierda
    {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}}  // Derecha
};

void rotarCara(int cara) {
    char temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[j][SIZE - 1 - i] = cube[cara][i][j];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cube[cara][i][j] = temp[i][j];
}

void dibujarCubo(sf::RenderWindow& window) {
    float size = 50;
    sf::Font font;
    font.loadFromFile("arial.ttf");

    for (int face = 0; face < 6; face++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                sf::RectangleShape square(sf::Vector2f(size, size));
                square.setOutlineColor(sf::Color::Black);
                square.setOutlineThickness(2);
                square.setPosition(100 + j * size + (face % 3) * 200, 100 + i * size + (face / 3) * 200);
                
                sf::Text letter;
                letter.setFont(font);
                letter.setString(string(1, cube[face][i][j]));
                letter.setCharacterSize(24);
                letter.setFillColor(sf::Color::Black);
                letter.setPosition(115 + j * size + (face % 3) * 200, 110 + i * size + (face / 3) * 200);
                
                window.draw(square);
                window.draw(letter);
            }
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cubo de Rubik");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        dibujarCubo(window);
        window.display();
    }
    
    return 0;
}

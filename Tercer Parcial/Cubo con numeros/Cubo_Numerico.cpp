/*#include <iostream>
#include <vector>

using namespace std;

void generarCuboMagico(int n) {
    vector<vector<vector<int>>> cubo(n, vector<vector<int>>(n, vector<int>(n, 0)));
    int i = 0, j = n / 2, k = n / 2;
    
    for (int num = 1; num <= n * n * n; num++) {
        cubo[i][j][k] = num;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;
        int nk = (k + 1) % n;
        
        if (cubo[ni][nj][nk] != 0) {
            i = (i + 1) % n;
        } else {
            i = ni;
            j = nj;
            k = nk;
        }
    }
    
    cout << "Cubo Magico generado:" << endl;
    for (int x = 0; x < n; x++) {
        cout << "Nivel " << x + 1 << ":\n";
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                cout << cubo[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el tamanio impar del cubo msgico: ";
    cin >> n;
    if (n % 2 == 0) {
        cout << "Solo se admiten numeros impares." << endl;
        return 1;
    }
    
    generarCuboMagico(n);
    system("pause");
    return 0;
}
*/


// g++ -o CuboNum Cubo_Numerico.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
/*#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

void generarCuboMagico(int n, vector<vector<vector<int>>>& cubo) {
    cubo = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 0)));
    int i = 0, j = n / 2, k = n / 2;
    
    for (int num = 1; num <= n * n * n; num++) {
        cubo[i][j][k] = num;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;
        int nk = (k + 1) % n;
        
        if (cubo[ni][nj][nk] != 0) {
            i = (i + 1) % n;
        } else {
            i = ni;
            j = nj;
            k = nk;
        }
    }
}

void dibujarCuboMagico(const vector<vector<vector<int>>>& cubo, int n) {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Cubo Mágico");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        float size = 40;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int z = 0; z < n; z++) {
                    sf::RectangleShape cubeShape(sf::Vector2f(size, size));
                    cubeShape.setFillColor(sf::Color::White);
                    cubeShape.setOutlineColor(sf::Color::Black);
                    cubeShape.setOutlineThickness(1);
                    cubeShape.setPosition(100 + y * size, 100 + x * size);
                    window.draw(cubeShape);
                }
            }
        }
        window.display();
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño impar del cubo mágico: ";
    cin >> n;
    if (n % 2 == 0) {
        cout << "Solo se admiten números impares." << endl;
        return 1;
    }
    
    vector<vector<vector<int>>> cubo;
    generarCuboMagico(n, cubo);
    dibujarCuboMagico(cubo, n);
    
    return 0;
}*/

// g++ -o CuboNum Cubo_Numerico.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

const int SIZE = 3;
const int CELL_SIZE = 50;
const int OFFSET_X = 300;
const int OFFSET_Y = 150;
const int SPACING = 5; // Espaciado entre capas
const int CUBE_OFFSET = 200; // Espaciado entre caras

sf::Color obtenerColor(int cara) {
    switch (cara) {
        case 0: return sf::Color::White;
        case 1: return sf::Color::Yellow;
        case 2: return sf::Color::Green;
        case 3: return sf::Color::Blue;
        case 4: return sf::Color::Red;
        case 5: return sf::Color::Magenta;
        default: return sf::Color::Black;
    }
}

vector<vector<vector<int>>> generarCuboMagico(int n) {
    vector<vector<vector<int>>> cubo(n, vector<vector<int>>(n, vector<int>(n, 0)));
    int i = 0, j = n / 2, k = n / 2;
    
    for (int num = 1; num <= n * n * n; num++) {
        cubo[i][j][k] = num;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;
        int nk = (k + 1) % n;
        
        if (cubo[ni][nj][nk] != 0) {
            i = (i + 1) % n;
        } else {
            i = ni;
            j = nj;
            k = nk;
        }
    }
    return cubo;
}

void dibujarCuboMagico(sf::RenderWindow& window, const vector<vector<vector<int>>>& cubo, int n) {
    window.clear();
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error cargando la fuente!" << endl;
        return;
    }

    for (int cara = 0; cara < 6; cara++) {
        int offsetX = OFFSET_X + (cara % 3) * CUBE_OFFSET;
        int offsetY = OFFSET_Y + (cara / 3) * CUBE_OFFSET;
        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                cell.setFillColor(obtenerColor(cara));
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(2);
                cell.setPosition(offsetX + y * (CELL_SIZE + SPACING), 
                                 offsetY + x * (CELL_SIZE + SPACING));

                sf::Text text;
                text.setFont(font);
                text.setString(to_string(cubo[x][y][cara % n]));
                text.setCharacterSize(18);
                text.setFillColor(sf::Color::Black);
                text.setPosition(offsetX + y * (CELL_SIZE + SPACING) + 15, 
                                 offsetY + x * (CELL_SIZE + SPACING) + 10);

                window.draw(cell);
                window.draw(text);
            }
        }
    }
    window.display();
}

int main() {
    int n;
    cout << "Ingrese el tamanio impar del cubo magico: ";
    cin >> n;
    if (n % 2 == 0) {
        cout << "Solo se admiten numeros impares." << endl;
        return 1;
    }
    
    vector<vector<vector<int>>> cubo = generarCuboMagico(n);
    sf::RenderWindow window(sf::VideoMode(900, 700), "Cubo Magico");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        dibujarCuboMagico(window, cubo, n);
    }
    return 0;
}



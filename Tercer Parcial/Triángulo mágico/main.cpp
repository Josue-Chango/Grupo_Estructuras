#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//g++ -o main main.cpp -I"C:\SFML-2.5.1\include" -L"C:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
// Función para construir el triángulo mágico usando el método explicado
vector<int> construirTrianguloMagico(vector<int> numeros) {
    sort(numeros.begin(), numeros.end());
    vector<int> menores = {numeros[0], numeros[1], numeros[2]};
    vector<int> mayores = {numeros[3], numeros[4], numeros[5]};
    
    int v1 = menores[1];
    int v2 = menores[2];
    int v3 = menores[0];
    
    int intermedio = mayores[0];
    int suma_magica = v2 + intermedio + v1;
    
    int lado1 = mayores[2];
    int lado2 = mayores[1];
    
    return {v1, lado1, intermedio, v3, lado2, v2};
}

// Función para mostrar el triángulo mágico en consola
void mostrarTrianguloMagico(const vector<int>& numeros) {
    if (numeros.empty()) {
        cout << "No se pudo generar un triángulo mágico válido." << endl;
        return;
    }
    cout << "\nTriángulo mágico encontrado:" << endl;
    cout << "      " << numeros[0] << endl;
    cout << "    " << numeros[1] << "   " << numeros[2] << endl;
    cout << "  " << numeros[3] << "   " << numeros[4] << "   " << numeros[5] << endl;
}

// Función para graficar el triángulo mágico usando SFML
void graficarTrianguloMagico(const vector<int>& numeros) {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Triángulo Mágico");
    
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "No se pudo cargar la fuente." << endl;
        return;
    }
    
    vector<sf::CircleShape> nodos(6);
    vector<sf::Text> textos(6);
    vector<sf::Vector2f> posiciones = {
        {200, 50}, {130, 150}, {270, 150}, {70, 250}, {200, 250}, {330, 250}
    };
    
    for (int i = 0; i < 6; i++) {
        nodos[i].setRadius(20);
        nodos[i].setFillColor(sf::Color::Cyan);
        nodos[i].setPosition(posiciones[i]);
        
        textos[i].setFont(font);
        textos[i].setString(to_string(numeros[i]));
        textos[i].setCharacterSize(20);
        textos[i].setFillColor(sf::Color::Black);
        textos[i].setPosition(posiciones[i].x + 10, posiciones[i].y + 5);
    }
    
    vector<pair<int, int>> conexiones = {{0, 1}, {1, 3}, {3, 4}, {4, 5}, {5, 2}, {2, 0}};
    sf::Vertex lineas[12];
    for (size_t i = 0; i < conexiones.size(); i++) {
        lineas[i * 2].position = posiciones[conexiones[i].first] + sf::Vector2f(20, 20);
        lineas[i * 2 + 1].position = posiciones[conexiones[i].second] + sf::Vector2f(20, 20);
        lineas[i * 2].color = sf::Color::White;
        lineas[i * 2 + 1].color = sf::Color::White;
    }
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(lineas, 12, sf::Lines);
        for (int i = 0; i < 6; i++) {
            window.draw(nodos[i]);
            window.draw(textos[i]);
        }
        window.display();
    }
}

int main() {
    vector<int> numeros(6);
    cout << "Ingrese 6 numeros distintos: ";
    for (int i = 0; i < 6; i++) {
        cin >> numeros[i];
    }
    
    vector<int> triangulo = construirTrianguloMagico(numeros);
    mostrarTrianguloMagico(triangulo);
    graficarTrianguloMagico(triangulo);
    system("pause");
    return 0;
}
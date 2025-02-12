
///g++ Tablero.cpp -o tablero.exe -L"C:\SFML\lib" -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Pide al usuario que ingrese el tamaño del tablero
    int N;
    std::cout << "Ingrese el tamaño del tablero (N): ";
    std::cin >> N;

    // Crea la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(700, 700), "Tablero de ajedrez");

    // Establece el tamaño de cada casilla
    float cellSize = 700.0f / N;

    // Dibuja el tablero
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Crea un rectángulo para cada casilla
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));

            // Establece la posición de la casilla
            cell.setPosition(j * cellSize, i * cellSize);

            // Establece el color de la casilla (blanco o negro)
            if ((i + j) % 2 == 0)
            {
                cell.setFillColor(sf::Color::White);
            }
            else
            {
                cell.setFillColor(sf::Color::Black);
            }

            // Dibuja la casilla en la ventana
            window.draw(cell);
        }
    }

    // Muestra el tablero
    window.display();

    // Mantiene la ventana abierta hasta que se cierre
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}

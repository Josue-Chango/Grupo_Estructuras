#include "HashTable.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Definición de las variables estáticas
float HashTable::prevx = 0;
float HashTable::prevy = 0;

HashTable::HashTable(bool letterMode, int probingMethod, int tableSize) : isLetterMode(letterMode), probingMethod(probingMethod), TABLE_SIZE(tableSize)
{
    std::cout << "Inicializando tabla hash..." << std::endl; // Mensaje de depuración
    table = new HashNode*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
    initializeGraphicsDimensions();
}

void HashTable::initializeGraphicsDimensions()
{
    WINDOW_WIDTH = 800; // Tamaño fijo de la ventana
    WINDOW_HEIGHT = 600;
    CELL_WIDTH = (WINDOW_WIDTH / (TABLE_SIZE + 2));
    CELL_HEIGHT = CELL_WIDTH / 2;
    VERTICAL_SPACING = CELL_HEIGHT * 2;
    ARROW_HEIGHT = VERTICAL_SPACING / 2;
    START_X = (WINDOW_WIDTH - (TABLE_SIZE * CELL_WIDTH)) / 2;
    START_Y = (WINDOW_HEIGHT * 3) / 4;
    MAX_ELEMENTS_VERTICAL = (START_Y - 100) / VERTICAL_SPACING;
}

HashTable::~HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashNode *current = table[i];
        while (current != nullptr)
        {
            HashNode *next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] table;
}

int HashTable::calculateXORHash(const std::string &value)
{
    int hash = 0;
    for (char c : value)
    {
        hash = (hash * 31 + (isLetterMode ? toupper(c) : c)) % TABLE_SIZE;
    }
    return hash;
}

// Definición de hashFunction
int HashTable::hashFunction(std::string value)
{
    if (value.empty())
        return 0;
    return calculateXORHash(value);
}

// Definición de linearProbing
int HashTable::linearProbing(int index, int i)
{
    return (index + i) % TABLE_SIZE;
}

// Definición de quadraticProbing
int HashTable::quadraticProbing(int index, int i)
{
    return (index + i * i) % TABLE_SIZE;
}

// Definición de doubleHashing
int HashTable::doubleHashing(int index, int i, const std::string &value)
{
    return (index + i * hash2(value)) % TABLE_SIZE;
}

// Función hash2 usada en doubleHashing
int HashTable::hash2(const std::string &value)
{
    int hash = 0;
    for (char c : value)
    {
        hash = (hash * 17 + (isLetterMode ? toupper(c) : c)) % TABLE_SIZE;
    }
    return hash == 0 ? 1 : hash; // Ensure hash2 is not zero
}

void HashTable::insert(std::string value)
{
    std::cout << "Insertando valor: " << value << std::endl; // Mensaje de depuración
    if (value.empty())
        return;

    int index = hashFunction(value);
    int i = 0;
    int newIndex = index;

    while (table[newIndex] != nullptr)
    {
        i++;
        if (probingMethod == 1)
        {
            newIndex = linearProbing(index, i);
        }
        else if (probingMethod == 2)
        {
            newIndex = quadraticProbing(index, i);
        }
        else if (probingMethod == 3)
        {
            newIndex = doubleHashing(index, i, value);
        }
    }

    table[newIndex] = new HashNode(value);
}

bool HashTable::search(std::string value)
{
    if (value.empty())
        return false;

    int index = hashFunction(value);
    int i = 0;
    int newIndex = index;

    while (table[newIndex] != nullptr)
    {
        if (table[newIndex]->data == value)
            return true;

        i++;
        if (probingMethod == 1)
        {
            newIndex = linearProbing(index, i);
        }
        else if (probingMethod == 2)
        {
            newIndex = quadraticProbing(index, i);
        }
        else if (probingMethod == 3)
        {
            newIndex = doubleHashing(index, i, value);
        }
    }

    return false;
}

void HashTable::visualize()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Visualizacion de Tabla Hash");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            int cellX = START_X + i * CELL_WIDTH;

            // Dibujar celdas
            sf::RectangleShape cell(sf::Vector2f(CELL_WIDTH - 10, CELL_HEIGHT));
            cell.setPosition(cellX, START_Y);
            cell.setFillColor(sf::Color(200, 200, 200));
            window.draw(cell);

            // Dibujar índice
            sf::Font font;
            font.loadFromFile("arial.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("[" + std::to_string(i) + "]");
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Green);
            text.setPosition(cellX + 10, START_Y + CELL_HEIGHT + 5);
            window.draw(text);

            // Dibujar nodos
            HashNode *current = table[i];
            int nodeY = START_Y - VERTICAL_SPACING;
            while (current != nullptr)
            {
                sf::RectangleShape node(sf::Vector2f(CELL_WIDTH - 10, CELL_HEIGHT));
                node.setPosition(cellX, nodeY);
                node.setFillColor(sf::Color::Blue);
                window.draw(node);

                sf::Text nodeText;
                nodeText.setFont(font);
                nodeText.setString(current->data);
                nodeText.setCharacterSize(18);
                nodeText.setFillColor(sf::Color::White);
                nodeText.setPosition(cellX + 10, nodeY + 10);
                window.draw(nodeText);

                current = current->next;
                nodeY -= VERTICAL_SPACING;
            }
        }

        window.display();
    }
}

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashNode.h"
#include <SFML/Graphics.hpp>
#include <string>

class HashTable
{
private:
    int TABLE_SIZE;
    HashNode **table;
    bool isLetterMode;
    int probingMethod;

    // Dimensiones y configuración visual
    int CELL_WIDTH;
    int CELL_HEIGHT;
    int START_X;
    int START_Y;
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    int VERTICAL_SPACING;
    int ARROW_HEIGHT;
    int MAX_ELEMENTS_VERTICAL;

    // Miembros estáticos
    static float prevx;
    static float prevy;

    // Métodos internos
    int hashFunction(std::string value);
    void initializeGraphicsDimensions();
    int calculateXORHash(const std::string &value);
    int linearProbing(int index, int i);
    int quadraticProbing(int index, int i);
    int doubleHashing(int index, int i, const std::string &value);
    int hash2(const std::string &value);

public:
    explicit HashTable(bool letterMode, int probingMethod, int tableSize);
    ~HashTable();
    void insert(std::string value);
    bool search(std::string value);
    void visualize();
};

#endif

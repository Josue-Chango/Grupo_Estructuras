//g++ -o laberinto laberinto.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAZE_SIZE = 10;
const int CELL_SIZE = 50;
const int WINDOW_SIZE = MAZE_SIZE * CELL_SIZE;
const sf::Color WALL_COLOR = sf::Color::Black;
const sf::Color PATH_COLOR = sf::Color::White;
const sf::Color PLAYER_COLOR = sf::Color::Red;

vector<vector<int>> generateMaze(int size) {
    vector<vector<int>> maze(size, vector<int>(size, 1));
    srand(time(0));
    stack<pair<int, int>> s;
    s.push({1, 1});
    maze[1][1] = 0;

    int dx[] = {0, 0, -2, 2};
    int dy[] = {-2, 2, 0, 0};
    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();
        vector<int> directions = {0, 1, 2, 3};
        random_shuffle(directions.begin(), directions.end());
        for (int i : directions) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx > 0 && ny > 0 && nx < size - 1 && ny < size - 1 && maze[nx][ny] == 1) {
                maze[nx - dx[i] / 2][ny - dy[i] / 2] = 0;
                maze[nx][ny] = 0;
                s.push({nx, ny});
            }
        }
    }
    return maze;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Maze Solver with SFML");
    vector<vector<int>> maze = generateMaze(MAZE_SIZE);
    sf::RectangleShape player(sf::Vector2f(CELL_SIZE - 10, CELL_SIZE - 10));
    player.setFillColor(PLAYER_COLOR);
    int px = 1, py = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                int nx = px, ny = py;
                if (event.key.code == sf::Keyboard::W) ny--;
                if (event.key.code == sf::Keyboard::S) ny++;
                if (event.key.code == sf::Keyboard::A) nx--;
                if (event.key.code == sf::Keyboard::D) nx++;
                if (maze[nx][ny] == 0) {
                    px = nx;
                    py = ny;
                }
            }
        }
        window.clear(WALL_COLOR);
        for (int i = 0; i < MAZE_SIZE; i++) {
            for (int j = 0; j < MAZE_SIZE; j++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                if (maze[i][j] == 1)
                    cell.setFillColor(WALL_COLOR);
                else
                    cell.setFillColor(PATH_COLOR);
                window.draw(cell);
            }
        }
        player.setPosition(py * CELL_SIZE + 5, px * CELL_SIZE + 5);
        window.draw(player);
        window.display();
    }
    return 0;
}

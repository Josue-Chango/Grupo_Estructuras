#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y, cost;
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

int dijkstra(vector<vector<int>> &maze, pair<int, int> start, pair<int, int> end) {
    int n = maze.size(), m = maze[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    pq.push({start.first, start.second, 0});
    dist[start.first][start.second] = 0;
    
    while (!pq.empty()) {
        Node current = pq.top(); pq.pop();
        int x = current.x, y = current.y, cost = current.cost;
        
        if (x == end.first && y == end.second) return cost;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                int new_cost = cost + 1;
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push({nx, ny, new_cost});
                }
            }
        }
    }
    return -1; // No hay camino
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };
    
    pair<int, int> start = {0, 0}, end = {4, 4};
    int result = dijkstra(maze, start, end);
    
    if (result != -1)
        cout << "El camino mas corto tiene longitud: " << result << endl;
    else
        cout << "No hay camino disponible." << endl;
    system("pause");
    return 0;
}

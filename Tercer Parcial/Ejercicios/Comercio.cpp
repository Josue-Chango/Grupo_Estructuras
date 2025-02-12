// Problema del Viajante de Comercio
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int TSP(vector<vector<int>> &dist, vector<int> &path, vector<bool> &visited, int pos, int n, int count, int cost, int &minCost) {
    if (count == n && dist[pos][0]) {
        minCost = min(minCost, cost + dist[pos][0]);
        return minCost;
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[pos][i]) {
            visited[i] = true;
            path.push_back(i);
            TSP(dist, path, visited, i, n, count + 1, cost + dist[pos][i], minCost);
            visited[i] = false;
            path.pop_back();
        }
    }
    return minCost;
}

int main() {
    vector<vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int n = dist.size();
    vector<int> path;
    vector<bool> visited(n, false);
    visited[0] = true;
    int minCost = INF;
    TSP(dist, path, visited, 0, n, 1, 0, minCost);
    cout << "Costo mínimo del circuito del viajante: " << minCost << endl;
    return 0;
}
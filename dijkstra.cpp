#include <iostream>
using namespace std;
#define INF 9999999
#define V 8
int G[V][V] = {
    {0,8,1,5,3,0,0,0},
    {8,0,0,0,6,1,0,0},
    {1,0,0,6,0,7,0,3},
    {5,0,6,0,2,0,0,0},
    {3,6,0,2,0,0,9,0},
    {0,1,7,0,0,0,3,1},
    {0,0,0,0,9,3,0,4},
    {0,0,3,0,0,1,4,0}
};
int minDistance(int dist[], bool visited[]) {
    int min = INF, index = -1;
    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    return index;
}
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        cout << j + 1;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j + 1;
}
void dijkstra(int src) {
    int dist[V];
    bool visited[V];
    int parent[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && G[u][v] && dist[u] + G[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + G[u][v];
            }
    }
    cout << "Shortest paths from node " << src + 1 << ":\n";
    for (int i = 0; i < V; i++) {
        cout << src + 1 << " -> " << i + 1 << ": distance = " << dist[i] << ", path: ";
        printPath(parent, i);
        cout << "\n";
    }
}
int main() {
    dijkstra(0);
    return 0;
}

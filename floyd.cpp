#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1000000000;

int main() {
    const int n = 8;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    auto add_edge = [&](int u, int v, int w) {
        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    };

    add_edge(1, 3, 1);
    add_edge(1, 2, 8);
    add_edge(1, 5, 3);
    add_edge(1, 4, 5);
    add_edge(4, 5, 2);
    add_edge(3, 4, 6);
    add_edge(2, 5, 6);
    add_edge(2, 6, 1);
    add_edge(3, 8, 3);
    add_edge(3, 6, 7);
    add_edge(6, 8, 1);
    add_edge(6, 7, 3);
    add_edge(7, 8, 4);
    add_edge(5, 7, 9);

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "All-pairs shortest path distance matrix (Floyd-Warshall):\n";
    cout << "    ";
    for (int j = 1; j <= n; ++j) {
        cout << setw(4) << j;
    }
    cout << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << setw(3) << i << " ";
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] >= INF / 2) {
                cout << setw(4) << "INF";
            } else {
                cout << setw(4) << dist[i][j];
            }
        }
        cout << "\n";
    }

    return 0;
}

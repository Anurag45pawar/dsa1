#include <iostream>
using namespace std;

int main() {
    int n, start;
    int adj[10][10], visited[10] = {0};
    int q[10], front = 0, rear = -1;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    cout << "Enter starting vertex: ";
    cin >> start;

    // BFS logic
    visited[start] = 1;
    q[++rear] = start;

    cout << "BFS Traversal: ";
    while (front <= rear) {
        int v = q[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
    }

    return 0;
}

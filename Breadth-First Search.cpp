#include <iostream>
#include <queue>
#include <climits> 
using namespace std;

void BFS(int adjMatrix[100][100], int vertices, int source) {
    string color[100];
    int distance[100];
    int predecessor[100];
    for (int i = 0; i < vertices; i++) {
        color[i] = "WHITE";
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }

    color[source] = "GRAY";
    distance[source] = 0;
    queue<int> Q;
    Q.push(source);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 0; v < vertices; v++) {
            if (adjMatrix[u][v] == 1 && color[v] == "WHITE") { 
                color[v] = "GRAY";
                distance[v] = distance[u] + 1;
                predecessor[v] = u;
                Q.push(v);
            }
        }
        color[u] = "BLACK";
    }
    cout << "\nVertex\tDistance\tPredecessor\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t" << (distance[i] == INT_MAX ? -1 : distance[i]) << "\t\t"
             << (predecessor[i] == -1 ? "NIL" : to_string(predecessor[i])) << endl;
    }
}
int main() 
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    int adjMatrix[100][100] = {0}; 
    cout << "Enter the edges (u v) where u and v are connected (0-based indexing):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    BFS(adjMatrix, vertices, source);
    return 0;
}

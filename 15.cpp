#include <iostream>
#include <climits>
using namespace std;

class Graph {
public:
    int V; 
    int E; 
    int **edges; 
    int *dist; 
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges = new int*[E];
        for (int i = 0; i < E; i++) {
            edges[i] = new int[3]; 
        }
        dist = new int[V]; 
    }
    void addEdge(int edgeIndex, int u, int v, int weight) {
        edges[edgeIndex][0] = u;
        edges[edgeIndex][1] = v;
        edges[edgeIndex][2] = weight;
    }
    void relax(int u, int v, int weight) {
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            dist[v] = dist[u] + weight;
        }
    }
    bool bellmanFord(int source) {
        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX; 
        }
        dist[source] = 0; 
        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];
                relax(u, v, weight);
            }
        }
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                return false; 
            }
        }
        return true; 
    }
    void printDistances() {
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << i << " \t INF" << endl;
            } else {
                cout << i << " \t " << dist[i] << endl;
            }
        }
    }
    ~Graph() {
        for (int i = 0; i < E; i++) {
            delete[] edges[i];
        }
        delete[] edges;
        delete[] dist;
    }
};
int main() 
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Graph g(V, E);
    cout << "Enter edges in the form (u v weight): " << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(i, u, v, weight);
    }
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    if (g.bellmanFord(source)) {
        cout << "No negative weight cycle detected." << endl;
        g.printDistances();
    } else {
        cout << "Graph contains a negative weight cycle." << endl;
    }
    return 0;
}
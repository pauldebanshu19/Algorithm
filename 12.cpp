#include <iostream>
#include <climits>  
using namespace std;

const int MAX_VERTICES = 100;
struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};
struct Node {
    int key;        
    int parent;     
    bool inMST;     
};
int extractMin(Node nodes[], int vertices) {
    int minKey = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < vertices; i++) {
        if (!nodes[i].inMST && nodes[i].key < minKey) {
            minKey = nodes[i].key;
            minIndex = i;
        }
    }
    return minIndex;
}
void primMST(Graph &G, int start) {
    Node nodes[MAX_VERTICES];
    for (int i = 0; i < G.vertices; i++) {
        nodes[i].key = INT_MAX;
        nodes[i].parent = -1;
        nodes[i].inMST = false;
    }
    nodes[start].key = 0;
    for (int i = 0; i < G.vertices - 1; i++) {
        int u = extractMin(nodes, G.vertices);  
        nodes[u].inMST = true;                 
        for (int v = 0; v < G.vertices; v++) {
            if (G.adjMatrix[u][v] && !nodes[v].inMST && G.adjMatrix[u][v] < nodes[v].key) {
                nodes[v].key = G.adjMatrix[u][v];
                nodes[v].parent = u;
            }
        }
    }
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (int i = 0; i < G.vertices; i++) {
        if (nodes[i].parent != -1) {
            cout << nodes[i].parent << " - " << i << " (Weight: " << nodes[i].key << ")\n";
            totalWeight += nodes[i].key;
        }
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}
int main() 
{
    Graph G;
    int edges;
    cout << "Enter the number of vertices: ";
    cin >> G.vertices;
    for (int i = 0; i < G.vertices; i++) {
        for (int j = 0; j < G.vertices; j++) {
            G.adjMatrix[i][j] = 0;  
        }
    }
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (u v w) where u and v are vertices and w is the weight:\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.adjMatrix[u][v] = w;
        G.adjMatrix[v][u] = w;  
    }
    int start;
    cout << "Enter the starting vertex for Prim's algorithm: ";
    cin >> start;
    primMST(G, start);
    return 0;
}

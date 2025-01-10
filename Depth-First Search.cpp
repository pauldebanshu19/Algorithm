#include <iostream>
#include <climits>
using namespace std;

struct Graph {
    int vertices;
    int adjMatrix[100][100] = {0}; 
};

void DFS_VISIT(Graph &G, int u);
void DFS(Graph &G);
int color[100];        
int discoveryTime[100];
int finishTime[100];    
int predecessor[100];
int timeVar = 0;        
void DFS(Graph &G) {
    for (int u = 0; u < G.vertices; u++) {
        color[u] = 0;             
        predecessor[u] = -1;      
    }
    timeVar = 0;
    for (int u = 0; u < G.vertices; u++) {
        if (color[u] == 0) { 
            DFS_VISIT(G,u);
        }
    }
}
void DFS_VISIT(Graph &G, int u) {
    timeVar++;
    discoveryTime[u] = timeVar;  
    color[u] = 1;               
    for (int v = 0; v < G.vertices; v++) {
        if (G.adjMatrix[u][v] == 1 && color[v] == 0) { 
            predecessor[v] = u;  
            DFS_VISIT(G, v);     
        }
    }
    color[u] = 2;             
    timeVar++;
    finishTime[u] = timeVar;    
}
int main() 
{
    Graph G;
    int edges;
    cout << "Enter the number of vertices: ";
    cin >> G.vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (u v) where u and v are connected (0-based indexing):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        G.adjMatrix[u][v] = 1; 
    }
    DFS(G);
    cout << "\nVertex\tDiscovery Time\tFinish Time\tPredecessor\n";
    for (int i = 0; i < G.vertices; i++) {
        cout << i << "\t" << discoveryTime[i] << "\t\t" << finishTime[i] << "\t\t"
             << (predecessor[i] == -1 ? "NIL" : to_string(predecessor[i])) << endl;
    }
    return 0;
}

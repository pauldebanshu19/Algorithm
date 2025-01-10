#include <iostream>
#include <stack>
using namespace std;

const int MAX_VERTICES = 100;
struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
};
void DFS_VISIT(Graph &G, int u);
void DFS(Graph &G);
void TopologicalSort(Graph &G);
int color[MAX_VERTICES];       
int discoveryTime[MAX_VERTICES];
int finishTime[MAX_VERTICES];
int predecessor[MAX_VERTICES];
int timeVar = 0;               
stack<int> topoStack;
void DFS(Graph &G) {
    for (int u = 0; u < G.vertices; u++) {
        color[u] = 0;          
        predecessor[u] = -1;   
    }
    timeVar = 0;
    for (int u = 0; u < G.vertices; u++) {
        if (color[u] == 0) { 
            DFS_VISIT(G, u);
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

    topoStack.push(u);          
}
void TopologicalSort(Graph &G) 
{
    DFS(G); 
    cout << "\nTopological Order:\n";
    while (!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;
}
int main() 
{
    Graph G;
    int edges;
    cout << "Enter the number of vertices: ";
    cin >> G.vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (u v) where u -> v (directed edge, 0-based indexing):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        G.adjMatrix[u][v] = 1; 
    }
    TopologicalSort(G);
    return 0;
}

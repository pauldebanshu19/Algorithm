#include <iostream>
#include <algorithm>  
using namespace std;

struct Edge {
    int u, v, weight;
};
class DisjointSet {
    int* parent;
    int* rank;
    int size;
public:
    DisjointSet(int n) {
        size = n;
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = i;  
            rank[i] = 0;    
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  
        }
        return parent[x];
    }
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    ~DisjointSet() {
        delete[] parent;
        delete[] rank;
    }
};
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}
void kruskalMST(int vertices, int edgesCount, Edge edges[]) {
    sort(edges, edges + edgesCount, compare);
    DisjointSet ds(vertices);
    Edge* mst = new Edge[vertices - 1];  
    int mstIndex = 0, totalWeight = 0;
    for (int i = 0; i < edgesCount && mstIndex < vertices - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (ds.find(u) != ds.find(v)) {
            mst[mstIndex++] = edges[i];
            totalWeight += edges[i].weight;
            ds.unionSets(u, v);  
        }
    }
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < mstIndex; i++) {
        cout << mst[i].u << " - " << mst[i].v << " (Weight: " << mst[i].weight << ")\n";
    }
    cout << "Total Weight of MST: " << totalWeight << endl;

    delete[] mst;
}
int main() 
{
    int vertices, edgesCount;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edgesCount;
    Edge* edges = new Edge[edgesCount];
    cout << "Enter the edges (u v w) where u and v are vertices and w is the weight:\n";
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    kruskalMST(vertices, edgesCount, edges);
    delete[] edges;
    return 0;
}
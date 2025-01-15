#include <iostream>
#include <climits>
using namespace std;

class Graph {
public:
    int n;  
    int **W; 
    Graph(int n) {
        this->n = n;
        W = new int*[n];
        for (int i = 0; i < n; i++) {
            W[i] = new int[n];
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    W[i][j] = 0; 
                } else {
                    W[i][j] = INT_MAX; 
                }
            }
        }
    }
    void addEdge(int u, int v, int weight) {
        W[u][v] = weight;
    }
    void floydWarshall() {
        int **D = new int*[n];
        for (int i = 0; i < n; i++) {
            D[i] = new int[n];
            for (int j = 0; j < n; j++) {
                D[i][j] = W[i][j];
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (D[i][k] != INT_MAX && D[k][j] != INT_MAX) {
                        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                    }
                }
            }
        }
        cout << "Shortest distances between every pair of vertices:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][j] == INT_MAX) {
                    cout << "INF" << "\t";
                } else {
                    cout << D[i][j] << "\t";
                }
            }
            cout << endl;
        }
        for (int i = 0; i < n; i++) {
            delete[] D[i];
        }
        delete[] D;
    }
    ~Graph() {
        for (int i = 0; i < n; i++) {
            delete[] W[i];
        }
        delete[] W;
    }
};
int main() 
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    Graph g(n);
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges in the form (u v weight): " << endl;
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }
    g.floydWarshall();
    return 0;
}

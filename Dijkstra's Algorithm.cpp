#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int vertices, vector<vector<pair<int, int>>> &adjList, int source, int destination) {
    vector<int> distance(vertices, INT_MAX);
    vector<int> parent(vertices, -1); 
    distance[source] = 0; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); 
    while (!pq.empty()) {
        int dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (current == destination) break;

        for (auto neighbor : adjList[current]) {
            int next = neighbor.first;
            int weight = neighbor.second;
            if (distance[current] + weight < distance[next]) {
                distance[next] = distance[current] + weight;
                parent[next] = current;
                pq.push({distance[next], next});
            }
        }
    }
    if (distance[destination] == INT_MAX) {
        cout << "No path exists from " << source << " to " << destination << "." << endl;
    } else {
        cout << "Shortest distance from " << source << " to " << destination << ": " << distance[destination] << endl;
        vector<int> path;
        for (int v = destination; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << (i > 0 ? " -> " : "");
        }
        cout << endl;
    }
}
int main() 
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    vector<vector<pair<int, int>>> adjList(vertices);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    int source, destination;
    cout << "Enter the source and destination: ";
    cin >> source >> destination;
    dijkstra(vertices, adjList, source, destination);
    return 0;
}

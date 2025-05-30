#include<iostream>;
using namespace std;

void floydWarshall(vector<vector<int>>& graph) {
    const int numVertices = graph.size();

    // Replace -1 with INT_MAX for convenience
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (graph[i][j] == -1) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) {
                    continue;
                }
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // Convert back to -1
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (graph[i][j] == INT_MAX) {
                graph[i][j] = -1;
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, -1));
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
    }

    floydWarshall(graph);

    cout << "Shortest paths matrix:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == -1) {
                cout << "INF ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


//Used for multiple source shortest path
//condition -> directed + postive/negative wts graph

//Time C: O(v^3)
//space C: O(1)
//its simple so we use this instead dijkstra

//it also detect the negative cycle
//whenever there is negative cycle -> all the algo fails

// we can also use dijkstra for this multi source but only if E =(aprox) V
//if E = V^2 don't use dijkstra 

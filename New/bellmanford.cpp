#include <iostream>;

using namespace std;

vector<int> bellmanFord(int numVertices, vector<vector<int>> &edges, int startVertex)
{
    vector<int> distances(numVertices, INT_MAX);
    distances[startVertex] = 0;

    int numEdges = edges.size();

    for (int i = 0; i < numVertices - 1; i++)
    {
        // Relax the edges
        bool hasRelaxation = false;

        for (int j = 0; j < numEdges; j++)
        {
            int sourceVertex = edges[j][0];
            int destinationVertex = edges[j][1];
            int edgeWeight = edges[j][2];

            if (distances[sourceVertex] == INT_MAX)
                continue;

            if (distances[sourceVertex] + edgeWeight < distances[destinationVertex])
            {
                hasRelaxation = true;
                distances[destinationVertex] = distances[sourceVertex] + edgeWeight;
            }
        }

        if (!hasRelaxation)
            return distances;
    }

    // Detect negative cycles
    for (int j = 0; j < numEdges; j++)
    {
        int sourceVertex = edges[j][0];
        int destinationVertex = edges[j][1];
        int edgeWeight = edges[j][2];

        if (distances[sourceVertex] == INT_MAX)
            continue;

        if (distances[sourceVertex] + edgeWeight < distances[destinationVertex])
        {
            vector<int> negativeCycleDetected;
            negativeCycleDetected.push_back(-1);
            return negativeCycleDetected;
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> edges(numEdges, vector<int>(3));
    cout << "Enter each edge as a triplet (source destination weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int startVertex;
    cout << "Enter the start vertex: ";
    cin >> startVertex;

    vector<int> distances = bellmanFord(numVertices, edges, startVertex);

    if (!distances.empty() && distances[0] == -1) {
        cout << "A negative weight cycle is detected in the graph." << endl;
    } else {
        cout << "Shortest distances from vertex " << startVertex << ":" << endl;
        for (int i = 0; i < numVertices; i++) {
            if (distances[i] == INT_MAX) {
                cout << i << ": INF" << endl;
            } else {
                cout << i << ": " << distances[i] << endl;
            }
        }
    }

    return 0;
}

//for single sorce shortest path

//Bellman ford = for directed graph only
//Don't use this for undirected graph
//Time c : V*E

//Dijkstra = postive wts + directed/undirected wt
// T C : ElogV

//for  negative wt + undirected graph: can't use both (shortest path can't be found)

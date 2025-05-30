#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for(const auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Initialize distances
        vector<int> distances(V, INT_MAX);
        distances[src] = 0;
        
        // Priority queue to always get the vertex with minimum distance
        // pair<distance, vertex> - min heap based on distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});  // {distance, vertex}
        
        while(!pq.empty()) {
            // Get vertex with minimum distance
            int currentDistance = pq.top().first;
            int currentVertex = pq.top().second;
            pq.pop();
            
            // Skip if we've already found a better path to this vertex
            // This can happen because we don't remove outdated entries from priority queue
            if(currentDistance > distances[currentVertex]) {
                continue;
            }
            
            // Process all neighbors
            for(const auto &neighbor : adj[currentVertex]) {
                int neighborVertex = neighbor.first;
                int edgeWeight = neighbor.second;
                int newDistance = distances[currentVertex] + edgeWeight;
                
                // If we found a shorter path, update and add to queue
                if(newDistance < distances[neighborVertex]) {
                    distances[neighborVertex] = newDistance;
                    pq.push({newDistance, neighborVertex});
                }
            }
        }
        
        return distances;
}

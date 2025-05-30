#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

// Calculate Manhattan distance between two houses
int manhattanDistance(vector<int>& house1, vector<int>& house2) {
    return abs(house1[0] - house2[0]) + abs(house1[1] - house2[1]);
}

// Solution 1: Using Kruskal's Algorithm with Union-Find
class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        
        // Union by rank
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        
        return true;
    }
};

// Kruskal's Algorithm
int minCostConnectHousesKruskal(vector<vector<int>>& houses) {
    int n = houses.size();
    if (n <= 1) return 0;
    
    // Create all edges with their costs
    vector<pair<int, pair<int, int>>> edges; // {cost, {house1, house2}}
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cost = manhattanDistance(houses[i], houses[j]);
            edges.push_back({cost, {i, j}});
        }
    }
    
    // Sort edges by cost
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n);
    int totalCost = 0;
    int edgesUsed = 0;
    
    // Process edges in order of increasing cost
    for (auto& edge : edges) {
        int cost = edge.first;
        int house1 = edge.second.first;
        int house2 = edge.second.second;
        
        if (uf.unionSets(house1, house2)) {
            totalCost += cost;
            edgesUsed++;
            if (edgesUsed == n - 1) break; // MST complete
        }
    }
    
    return totalCost;
}

// Solution 2: Using Prim's Algorithm
int minCostConnectHousesPrim(vector<vector<int>>& houses) {
    int n = houses.size();
    if (n <= 1) return 0;
    
    vector<bool> inMST(n, false);
    vector<int> minCost(n, INT_MAX);
    
    // Priority queue: {cost, house_index}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Start with house 0
    minCost[0] = 0;
    pq.push({0, 0});
    
    int totalCost = 0;
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        
        // Add house u to MST
        inMST[u] = true;
        totalCost += cost;
        
        // Update costs to all adjacent houses
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int edgeCost = manhattanDistance(houses[u], houses[v]);
                if (edgeCost < minCost[v]) {
                    minCost[v] = edgeCost;
                    pq.push({edgeCost, v});
                }
            }
        }
    }
    
    return totalCost;
}

// Main function to solve the problem (using Kruskal's by default)
int minCostConnectHouses(vector<vector<int>>& houses) {
    return minCostConnectHousesKruskal(houses);
}

// Test function
#include <iostream>
int main() {
    // Test case 1
    vector<vector<int>> houses1 = {{0, 7}, {0, 9}, {20, 7}, {30, 7}, {40, 70}};
    cout << "Test 1 - Expected: 105, Got: " << minCostConnectHouses(houses1) << endl;
    
    // Test case 2
    vector<vector<int>> houses2 = {{0, 0}, {1, 1}, {1, 3}, {3, 0}};
    cout << "Test 2 - Expected: 7, Got: " << minCostConnectHouses(houses2) << endl;
    
    // Compare both algorithms
    cout << "\nKruskal's result: " << minCostConnectHousesKruskal(houses1) << endl;
    cout << "Prim's result: " << minCostConnectHousesPrim(houses1) << endl;
    
    return 0;
}
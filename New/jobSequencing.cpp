#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    
public:
    UnionFind(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findNextAvailable(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = findNextAvailable(parent[x]);
        return parent[x];
    }
    
    void markOccupied(int x) {
        if (x > 0) {
            parent[x] = x - 1;
        }
    }
};

vector<int> jobSchedulingOptimized(vector<int>& deadline, vector<int>& profit) {
    int n = deadline.size();
    
    vector<int> jobIndices(n);
    iota(jobIndices.begin(), jobIndices.end(), 0); 
    
    sort(jobIndices.begin(), jobIndices.end(), [&](int i, int j) {
        return profit[i] > profit[j];
    });
    
    int maxDeadline = *max_element(deadline.begin(), deadline.end());
    
    UnionFind slotManager(maxDeadline + 1);
    
    int jobCount = 0;
    int totalProfit = 0;
    
    for (int jobIdx : jobIndices) {
        int jobDeadline = deadline[jobIdx];
        int jobProfit = profit[jobIdx];
        
        int availableSlot = slotManager.findNextAvailable(jobDeadline);
        
        if (availableSlot > 0) {
            slotManager.markOccupied(availableSlot);
            jobCount++;
            totalProfit += jobProfit;
        }
    }
    
    return {jobCount, totalProfit};
}

void compareApproaches(vector<int> deadline, vector<int> profit) {
    cout << "=== Comparing Job Scheduling Approaches ===" << endl;
    cout << "Input: ";
    cout << "deadline = [";
    for (int i = 0; i < deadline.size(); i++) {
        cout << deadline[i];
        if (i < deadline.size() - 1) cout << ", ";
    }
    cout << "], profit = [";
    for (int i = 0; i < profit.size(); i++) {
        cout << profit[i];
        if (i < profit.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    vector<int> indices(deadline.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return profit[i] > profit[j];
    });
    
    cout << "Jobs will be considered in this order (highest profit first):" << endl;
    for (int i = 0; i < indices.size(); i++) {
        int jobIdx = indices[i];
        cout << "Job " << (jobIdx + 1) << " (profit: " << profit[jobIdx] 
             << ", deadline: " << deadline[jobIdx] << ")" << endl;
    }
    cout << endl;
    
    vector<int> result = jobSchedulingOptimized(deadline, profit);
    cout << "Optimized Solution Result: [" << result[0] << ", " << result[1] << "]" << endl;
    cout << "Jobs completed: " << result[0] << ", Total profit: " << result[1] << endl;
    cout << endl;
}

int main() {
    cout << "=== Optimized Job Scheduling Algorithm ===" << endl;
    cout << "Time Complexity: O(n log n)" << endl;
    cout << "Space Complexity: O(n)" << endl << endl;
    
    vector<int> deadline1 = {4, 1, 1, 1};
    vector<int> profit1 = {20, 10, 40, 30};
    compareApproaches(deadline1, profit1);
    
    vector<int> deadline2 = {2, 1, 2, 1, 1};
    vector<int> profit2 = {100, 19, 27, 25, 15};
    compareApproaches(deadline2, profit2);
    
    vector<int> deadline3 = {3, 1, 2, 2};
    vector<int> profit3 = {50, 10, 20, 30};
    compareApproaches(deadline3, profit3);
    
    return 0;
}

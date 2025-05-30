#include<iostream>
#include<climits>
#include<vector>
using namespace std;


class Solution {
public:
    // Solution 1: Dynamic Programming (Bottom-up) - Most Efficient
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return 0; // No matrices to multiply
        
        // dp[i][j] represents minimum cost to multiply matrices from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // l is chain length (number of matrices)
        for (int l = 2; l < n; l++) {
            for (int i = 1; i < n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                
                // Try all possible splits between i and j
                for (int k = i; k <= j - 1; k++) {
                    // Cost of multiplying matrices from i to k and k+1 to j
                    // Plus cost of multiplying the two resulting matrices
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[1][n - 1];
    }
};

// Alternative Solutions:

class SolutionMemoization {
public:
    // Solution 2: Recursive with Memoization (Top-down)
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return 0;
        
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(arr, 1, n - 1, memo);
    }
    
private:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& memo) {
        // Base case: single matrix
        if (i >= j) return 0;
        
        // Check memoization
        if (memo[i][j] != -1) return memo[i][j];
        
        int minCost = INT_MAX;
        
        // Try all possible splits
        for (int k = i; k < j; k++) {
            int cost = solve(arr, i, k, memo) + 
                       solve(arr, k + 1, j, memo) + 
                       arr[i - 1] * arr[k] * arr[j];
            minCost = min(minCost, cost);
        }
        
        return memo[i][j] = minCost;
    }
};

class SolutionWithPath {
public:
    // Solution 3: DP with optimal parenthesization tracking
    struct Result {
        int minCost;
        string optimalOrder;
    };
    
    Result matrixMultiplicationWithPath(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return {0, ""};
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> split(n, vector<int>(n, 0));
        
        // Fill DP table
        for (int l = 2; l < n; l++) {
            for (int i = 1; i < n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                
                for (int k = i; k <= j - 1; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k; // Store optimal split point
                    }
                }
            }
        }
        
        string order = buildOptimalOrder(split, 1, n - 1);
        return {dp[1][n - 1], order};
    }
    
private:
    string buildOptimalOrder(vector<vector<int>>& split, int i, int j) {
        if (i == j) {
            return "M" + to_string(i);
        }
        
        int k = split[i][j];
        string left = buildOptimalOrder(split, i, k);
        string right = buildOptimalOrder(split, k + 1, j);
        
        return "(" + left + " x " + right + ")";
    }
};

// Test function with detailed explanation
#include <iostream>
#include <climits>
using namespace std;

void explainExample(vector<int>& arr) {
    cout << "Matrix dimensions: ";
    for (int i = 0; i < arr.size() - 1; i++) {
        cout << "M" << (i + 1) << "(" << arr[i] << "x" << arr[i + 1] << ") ";
    }
    cout << endl;
    
    Solution sol;
    int result = sol.matrixMultiplication(arr);
    cout << "Minimum multiplications: " << result << endl;
    
    SolutionWithPath solPath;
    auto pathResult = solPath.matrixMultiplicationWithPath(arr);
    cout << "Optimal parenthesization: " << pathResult.optimalOrder << endl;
    cout << "-------------------" << endl;
}

int main() {
    cout << "Matrix Chain Multiplication Solutions" << endl;
    cout << "====================================" << endl;
    
    // Test case 1
    vector<int> arr1 = {2, 1, 3, 4};
    cout << "Test 1: ";
    explainExample(arr1);
    
    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4, 3};
    cout << "Test 2: ";
    explainExample(arr2);
    
    // Test case 3
    vector<int> arr3 = {3, 4};
    cout << "Test 3: ";
    explainExample(arr3);
    
    // Additional test case
    vector<int> arr4 = {5, 4, 6, 2, 7};
    cout << "Test 4: ";
    explainExample(arr4);
    
    // Performance comparison
    cout << "\nVerifying all solutions give same result:" << endl;
    Solution sol1;
    SolutionMemoization sol2;
    
    int result1 = sol1.matrixMultiplication(arr2);
    int result2 = sol2.matrixMultiplication(arr2);
    
    cout << "DP Solution: " << result1 << endl;
    cout << "Memoization: " << result2 << endl;
    cout << "Results match: " << (result1 == result2 ? "Yes" : "No") << endl;
    
    return 0;
}
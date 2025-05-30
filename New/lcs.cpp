class Solution {
public:
    int lcs(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        
        // Create DP table with dimensions (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    // Characters match: add 1 to diagonal value
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    // Characters don't match: take maximum from left or top
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};

// Alternative Space-Optimized Solution (O(min(m,n)) space)
class SolutionOptimized {
public:
    int lcs(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        
        // Ensure s1 is the shorter string for space optimization
        if (m > n) {
            swap(s1, s2);
            swap(m, n);
        }
        
        // Use only two arrays instead of full 2D table
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                if (s1[i-1] == s2[j-1]) {
                    curr[i] = prev[i-1] + 1;
                } else {
                    curr[i] = max(prev[i], curr[i-1]);
                }
            }
            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }
        
        return prev[m];
    }
};

// Test the solution
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    Solution sol;
    
    // Test cases
    string s1_1 = "ABCDGH", s2_1 = "AEDFHR";
    cout << "Test 1: " << sol.lcs(s1_1, s2_1) << " (Expected: 3)" << endl;
    
    string s1_2 = "ABC", s2_2 = "AC";
    cout << "Test 2: " << sol.lcs(s1_2, s2_2) << " (Expected: 2)" << endl;
    
    string s1_3 = "XYZW", s2_3 = "XYWZ";
    cout << "Test 3: " << sol.lcs(s1_3, s2_3) << " (Expected: 3)" << endl;
    
    return 0;
}
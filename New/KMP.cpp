class Solution {
public:
    // Solution 1: KMP Algorithm (Most Efficient)
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int m = pat.length();
        int n = txt.length();
        
        if (m > n) return result;
        
        // Build LPS (Longest Proper Prefix which is also Suffix) array
        vector<int> lps = buildLPS(pat);
        
        int i = 0; // index for txt
        int j = 0; // index for pat
        
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            
            if (j == m) {
                // Pattern found at index (i - j)
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && txt[i] != pat[j]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return result;
    }
    
private:
    // Build LPS array for KMP algorithm
    vector<int> buildLPS(string& pat) {
        int m = pat.length();
        vector<int> lps(m, 0);
        int len = 0; // length of previous longest prefix suffix
        int i = 1;
        
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
};

// Alternative Solutions for comparison:

class SolutionNaive {
public:
    // Solution 2: Naive Approach (Simple but less efficient)
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int m = pat.length();
        int n = txt.length();
        
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == m) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

class SolutionRabinKarp {
public:
    // Solution 3: Rabin-Karp Algorithm (Rolling Hash)
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int m = pat.length();
        int n = txt.length();
        
        if (m > n) return result;
        
        const int PRIME = 101;
        long long patHash = 0, txtHash = 0, h = 1;
        
        // Calculate hash value for pattern and first window of text
        for (int i = 0; i < m - 1; i++) {
            h = (h * 256) % PRIME;
        }
        
        for (int i = 0; i < m; i++) {
            patHash = (256 * patHash + pat[i]) % PRIME;
            txtHash = (256 * txtHash + txt[i]) % PRIME;
        }
        
        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // Check hash values
            if (patHash == txtHash) {
                // Check for exact match
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    result.push_back(i);
                }
            }
            
            // Calculate hash value for next window
            if (i < n - m) {
                txtHash = (256 * (txtHash - txt[i] * h) + txt[i + m]) % PRIME;
                if (txtHash < 0) {
                    txtHash += PRIME;
                }
            }
        }
        
        return result;
    }
};

// Test function
#include <iostream>
using namespace std;

void printResult(const vector<int>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // Test cases
    string txt1 = "abcab", pat1 = "ab";
    cout << "Test 1: txt=\"" << txt1 << "\", pat=\"" << pat1 << "\"" << endl;
    vector<int> result1 = sol.search(pat1, txt1);
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [0, 3]" << endl << endl;
    
    string txt2 = "abesdu", pat2 = "edu";
    cout << "Test 2: txt=\"" << txt2 << "\", pat=\"" << pat2 << "\"" << endl;
    vector<int> result2 = sol.search(pat2, txt2);
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: []" << endl << endl;
    
    string txt3 = "aabaacaadaabaaba", pat3 = "aaba";
    cout << "Test 3: txt=\"" << txt3 << "\", pat=\"" << pat3 << "\"" << endl;
    vector<int> result3 = sol.search(pat3, txt3);
    cout << "Output: ";
    printResult(result3);
    cout << "Expected: [0, 9, 12]" << endl << endl;
    
    // Performance comparison for large inputs
    string largeTxt = string(100000, 'a') + "abc" + string(100000, 'a');
    string largePat = "abc";
    
    cout << "Performance test with large input:" << endl;
    auto start = chrono::high_resolution_clock::now();
    vector<int> kmpResult = sol.search(largePat, largeTxt);
    auto end = chrono::high_resolution_clock::now();
    auto kmpTime = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "KMP found " << kmpResult.size() << " matches in " << kmpTime.count() << " microseconds" << endl;
    
    return 0;
}
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
  public:
    int knapsack(int Capacity, vector<int> &val, vector<int> &wt) {
        // code here
        
        vector<vector<int>> K(val.size()+1,vector<int>(Capacity+1,0));
        
        for(int i = 0;i<=val.size();i++){
            for(int j  = 0;j<=Capacity;j++){
                if(i==0 ||j ==0)
                    K[i][j] = 0;
                else if(wt[i-1] <=j)
                    K[i][j] = max(val[i-1]+K[i-1][j-wt[i-1]],K[i-1][j]);
                else
                    K[i][j] = K[i-1][j];
            }
        }
        return K[val.size()][Capacity];
    }
};
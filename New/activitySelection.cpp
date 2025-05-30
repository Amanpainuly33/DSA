#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
  public:
  
    int as(vector<int>& start,vector<int>& finish){
        int n = start.size();
        
        vector<int>indices;
        for(int i = 0;i<n;i++){
           indices.push_back(i);
        }
        if(indices.size()==0) return 0;
        
        sort(indices.begin(),indices.end(),[&](int a ,int b){
            return finish[a]<finish[b];
        });
        
        int count  = 1;
        int lastFinishTime = finish[indices[0]];
        
        for(int i =1;i<n;i++){
            int currentActivity = indices[i];
            if(start[currentActivity] >lastFinishTime){
                count ++;
                lastFinishTime = finish[currentActivity];
            }
        }
        return count;
    }  
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        return as(start,finish);
    }
};
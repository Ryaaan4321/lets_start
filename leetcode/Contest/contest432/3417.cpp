#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        bool iseven=m%2==0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<m;j+=2){
                    ans.push_back(grid[i][j]);
                }
            }else{
               int value=iseven?m-1:m-2;
               for(int j=value;j>=0;j-=2){
                ans.push_back(grid[i][j]);
               }
            }
        }
        return ans;
    }
};
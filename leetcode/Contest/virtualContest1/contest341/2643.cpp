#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int prev=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
              if(grid[i][j]==1){
                cnt++;
              }
            }
            if(cnt>ans){
                ans=cnt;
                prev=i;
            }
        }
        return vector<int>(ans,prev);
    }
};
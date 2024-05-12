#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool satisfiesConditions(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+1<n && j+1<m){
                    if(grid[i][j]!=grid[i+1][j] || grid[i][j]==grid[i][j+1]){
                        return 0;
                    }
                }else if(i+1<n){
                    if(grid[i][j]!=grid[i+1][j]){
                        return 0;
                    }
                }else if(j+1<m){
                    if(grid[i][j]==grid[i][j+1]){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};
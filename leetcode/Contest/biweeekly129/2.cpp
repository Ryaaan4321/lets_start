#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && grid[i-1][j]==1 && grid[i][j+1]==1){
                    

                }
            }
        }
    }
};
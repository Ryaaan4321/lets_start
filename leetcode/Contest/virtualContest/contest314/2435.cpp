#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    const int mod=1e9+7;
    bool isvalid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int fucc(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp,int k) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        int cnt = 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1 && j==m-1 && grid[i][j]!=-1){
            sum+=grid[i][j];
            grid[i][j]=-1;
        }
        fucc(i+1,j,grid,dp,k);
        fucc(i,j+1,grid,dp,k);
        return cnt;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = fucc(0, 0, grid, dp, k);
        return ans;
    }
};
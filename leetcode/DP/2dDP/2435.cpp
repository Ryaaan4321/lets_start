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
    int fucc(int i,int j,int sm,int k,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        if(!isvalid(i,j,n,m)){
            return 0;
        }
        if(i==n-1 && j==m-1){
            sm+=grid[i][j];
            if(sm%k==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][sm%k]!=-1){
            return dp[i][j][sm%k];
        }
        int down=fucc(i+1,j,sm+grid[i][j],k,dp,grid);
        int right=fucc(i,j+1,sm+grid[i][j],k,dp,grid);
        return dp[i][j][sm%k]=(down%mod+right%mod)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return fucc(0, 0, 0, k, dp, grid);
        
    }
};
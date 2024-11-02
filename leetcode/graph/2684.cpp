#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int dp[1002][1002];
    int fucc(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int cnt=0;
        if(i==n-1 && j==m-1){
          return cnt;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        int dr[4]={0,-1,0,1};
        int dc[4]={0,1,1,1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(dp[nr][nc]>dp[i][j] && !vis[nr][nc]){
                take=1+fucc(nr,nc,n,m,grid,vis);
                vis[nr][nc]=1;
            }
        }
        int ntkae=fucc(i+1,j+1,n,m,grid,vis);
        return max(take,ntkae);
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>vis(n,vector<int>(m));
        return fucc(0,0,n,m,grid,vis);
    }
};
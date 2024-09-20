#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    bool isvalid(int i,int j,int n,int m){
        return (i>=0) && (i<n) && (j>=0) && (j<m);
    }
    bool fucc(int i,int j,int health,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid){
        if(!isvalid || health==0 || grid[i][j]==-1){
            return 0;
        }
        if(dp[i][j][health]!=-1){
            return dp[i][j][health];
        }
        int f=0;
        if(grid[i][j]==1){
            health--;
            f=1;
        }
        if(i==(int)grid.size() && j==(int)grid[0].size() && health>=1){
            return 1;
        }
        int prev=grid[i][j];
        grid[i][j]=-1;
        int r=fucc(i+1,j,health,dp,grid);
        int l=fucc(i-1,j,health,dp,grid);
        int u=fucc(i,j+1,health,dp,grid);
        int d=fucc(i,j-1,health,dp,grid);

        grid[i][j]=prev;
        if(f==1){
            return dp[i][j][health]=r||l||u||d;
        }
        return dp[i][j][health]=r||l||u||d;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(health+1,-1)));
        bool ans=fucc(0,0,health,dp,grid);
        return (ans==1?1:0);
    }
    /*dijakstra code is running check the dp code once if u are going with it*/
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<int, pair<int, int>>> q;
        if (grid[0][0] == 1) {
            health = health - 1;
            q.push({health, {0, 0}});
        } else {
            q.push({health, {0, 0}});
        }
        vis[0][0] = health;
        while (!q.empty()) {
            auto node = q.front();
            int h = node.first;
            int ro = node.second.first;
            int co = node.second.second;
            if (ro == n - 1 && co == m - 1) {
                return 1;
            }
            q.pop();
            int dr[4] = {0, 1, 0, -1};
            int dc[4] = {-1, 0, 1, 0};
            for (int i = 0; i < 4; i++) {
                int nr = ro + dr[i];
                int nc = co + dc[i];
                if (isvalid(nr, nc, n, m)) {
                    int nhealth = (grid[nr][nc] == 1) ? h - 1 : h;
                    if (nhealth > 0 && nhealth > vis[nr][nc]) {
                        vis[nr][nc] = nhealth;
                        q.push({nhealth, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};
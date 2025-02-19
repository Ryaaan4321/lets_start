#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
    public:
        int dr[3]={-1,0,1};
        int dc[3]={+1,1,1};
        bool isvalid(int i,int j,int n,int m){
            return i>=0 && i<n && j>=0 && j<m;
        };
        int max_Moves(vector<vector<int>>& grid) {
            int n=grid.size();int m=grid[0].size();int ans=0;
            vector<vector<bool>>vis(n,vector<bool>(m,0));
            queue<pair<int,pair<int,int>>>q;
            for(int i=0;i<n;i++){
                q.push({0,{i,0}});
                vis[i][0]=1;
            }
            while(!q.empty()){
                int sz=q.size();
                while (sz--)
                {
                    auto node=q.front();
                    q.pop();
                    int row=node.second.first;
                    int col=node.second.second;
                    int cnt=node.first;
                    ans=max(cnt,ans);
                    for(int i=0;i<3;i++){
                        int nrow=row+dr[i];
                        int ncol=col+dc[i];
                        if(isvalid(nrow,ncol ,n,m) && grid[nrow][ncol]>grid[row][col] && !vis[nrow][ncol]){
                            q.push({cnt+1,{nrow,ncol}});
                            vis[nrow][ncol]=1;
                        }
                    }
                }
                
            }
            return ans;
        }
        int fucc(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
            int n=grid.size();int m=grid[0].size();
            if(dp[row][col]!=-1){
                return dp[row][col];
            }
            int max_moves=0;
            for(int i=0;i<3;i++){
                int newrow=row+dr[i];
                int newcol=col+dc[i];
                if(isvalid(newrow,newcol,n,m) && grid[row][col]<grid[newrow][newcol]){
                    max_moves=max(max_moves,1+fucc(newrow,newcol,grid,dp));
                }
            }
            return dp[row][col]=max_moves;
        }
        int maxMoves(vector<vector<int>>&grid){
            int n=grid.size();int m=grid[0].size();
            vector<vector<int>>dp(n,vector<int>(m,-1));
            int ans=0;
            for(int i=0;i<n;i++){
                ans=max(ans,fucc(i,0,grid,dp));
            }
            return ans;
        }
    };
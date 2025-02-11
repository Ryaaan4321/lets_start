#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
    public:
        int dr[3]={-1,0,1};
        int dc[3]={+1,1,1};
        bool isvalid(int i,int j,int n,int m){
            return i>=0 && i<n && j>=0 && j<n;
        };
        int mx(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
            int n=grid.size();
            int m=grid[0].size();
            vis[i][j]=1;
            queue<pair<int,pair<int,int>>>q;
            int ans=INT_MIN;
            q.push({grid[i][j],{i,j}});
            while (!q.empty())
            {
                int cnt=0;
                auto node=q.front();
                q.pop();
                int val=node.first;
                int i_=node.second.first;
                int j_=node.second.second;
                cnt++;
                if(i_==n-1 && j_==m-1){
                  ans=max(ans,cnt);
                  return ans;
                }
                for(int k=0;k<3;k++){
                    int ni=i_+dr[k];
                    int nj=j_+dc[k];
                    if(grid[ni][nj]>grid[i_][j_] && !vis[ni][nj]){
                        q.push({grid[ni][nj],{ni,nj}});
                        vis[ni][nj]=true;
                    }
                }
            }
            return ans;
            
        }
        int maxMoves(vector<vector<int>>& grid) {
            int n=grid.size();int m=grid[0].size();
            vector<vector<bool>>vis(n,vector<bool>(m,0));
            int ans=mx(0,0,grid,vis);
            return ans;
        }
    };
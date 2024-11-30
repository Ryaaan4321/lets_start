#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    bool isvalid(int i, int j, int n, int m)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int minTimeToReach(vector<vector<int>> &grid)
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({0, {0, 0}});
        vis[0][0]=1;
        int ans=0;
        while (!q.empty())
        {
            auto node = q.top();
            q.pop();
            int time=INT_MAX;
            int tm = node.first;
            int row = node.second.first;
            int col = node.second.second;
            if(row==n-1 && col==m-1){
                ans=time;
                break;
            }
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(isvalid(nrow,ncol,n,m) && !vis[nrow][ncol]){
                    if(grid[nrow][ncol]==0){
                        q.push({tm+1,{nrow,ncol}});
                        time=min(time,tm)
                    }else{
                        q.push({tm+grid[nrow][ncol],{nrow,ncol}});
                        time=min(time,tm);
                    }
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
};
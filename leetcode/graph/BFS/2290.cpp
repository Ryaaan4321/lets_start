#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0, {0, 0}});
        vis[0][0] = true;
        int ans = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int dis = node.first;
            int row = node.second.first;
            int col = node.second.second;
            if(row==m-1 && col==n-1){
                ans=dis;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]) {
                    vis[nrow][ncol]=1;
                    if (grid[nrow][ncol]) {
                        pq.push({dis+1, {nrow, ncol}});
                    } else {
                        pq.push({dis, {nrow, ncol}});
                    }
                }
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    int dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        if (!isvalid(i, j, n, m) || grid[i][j] == 0 || vis[i][j]) {
            return 0;
        }
        vis[i][j] = true; 
        int sum = grid[i][j];
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            sum += dfs(nr, nc, n, m, grid, vis);
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxFish = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(i, j, n, m, grid, vis));
                }
            }
        }

        return maxFish;
    }
};

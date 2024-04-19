#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Solution {
public:
    bool check(int i, int j, int n, int m) {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (!check(i, j, n, m) || grid[i][j] == -1) {
            return 0;
        }
        grid[i][j]=-1;
        return dfs(i - 1, j, n, m, grid) +dfs(i + 1, j, n, m, grid) + 
        dfs(i, j + 1, n, m, grid) + dfs(i, j - 1, n, m, grid) + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, n, m, grid));
                }
            }
        }

        return ans;
    }
};

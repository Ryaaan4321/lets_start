#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isv(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int fuc(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cur = grid[r][c];
        int res = grid[r][c];

        grid[r][c] = 0;
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (isv(nr, nc, n, m) && grid[nr][nc]) {
                res = max(res, cur + fuc(nr, nc, grid));
            }
        }
        grid[r][c] = cur;
        return res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, fuc(i, j, grid));
            }
        }
        return res;
    }
};
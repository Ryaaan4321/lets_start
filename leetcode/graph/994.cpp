#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis = grid;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 2) {
                    q.push({0, {row, col}});
                    vis[row][col] = 2;
                }
            }
        }
        int mintime = 0;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int time = node.first;
            int row = node.second.first;
            int col = node.second.second;
            mintime = max(time, mintime);

            for (int i = 0; i < 4; i++) {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];

                if (isvalid(newrow, newcol, n, m) &&
                    grid[newrow][newcol] == 1 && vis[newrow][newcol] != 2) {
                    q.push({time + 1, {newrow, newcol}});
                    vis[newrow][newcol] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 1) {
                    return -1;
                }
            }
        }
        return mintime;
    }
};
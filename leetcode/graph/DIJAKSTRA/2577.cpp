#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

using namespace std;
class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }

    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto node = pq.top();
            int tm = node[0];
            int i = node[1];
            int j = node[2];
            pq.pop();
            if (i == n - 1 && j == m - 1) {
                return tm;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if (!isvalid(ni, nj, n, m)) {
                    continue;
                }
                bool isok = (grid[ni][nj] - tm) % 2 == 0;
                int nt = max(grid[ni][nj] + isok, tm + 1);
                pq.push({nt, ni, nj});
            }
        }
        return -1;
    }
};
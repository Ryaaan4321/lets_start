#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    bool dp[41][41][1601];
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        memset(dp, false, sizeof(dp));
        q.push({k, {0, 0}});
        dp[0][0][k]=1;
        int cnt = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                int itm = node.first;
                int nr = node.second.first;
                int nc = node.second.second;
                q.pop();
                if (nr == n - 1 && nc == m - 1) {
                    return cnt;
                }
                for (int i = 0; i < 4; i++) {
                    int r = nr + dr[i];
                    int c = nc + dc[i];
                    if (isvalid(r, c, n, m)) {
                        if (grid[r][c] == 0 && !dp[r][c][itm]) {
                            q.push({itm, {r, c}});
                            dp[r][c][itm] = 1;
                        } else if (grid[r][c] == 1 && itm>0 && !dp[r][c][itm-1]) {
                            q.push({itm - 1, {r, c}});
                            dp[r][c][itm - 1] = 1;
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};
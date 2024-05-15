#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    bool check(vector<vector<int>> dis, int mid) {
        queue<pair<int, int>> q;
        int n = dis.size();
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vis[0][0] = 1;
        q.push({0, 0});
        if (dis[0][0] < mid) {
            return 0;
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int cr = node.first;
            int cc = node.second;

            if (cr == n - 1 && cc == n - 1) {
                return 1;
            }
            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (isvalid(nr, nc, n, n) && !vis[nr][nc]) {
                    if (dis[nr][nc] < mid) {
                        continue;
                    }
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vector<vector<int>> distance(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int> node = q.front();
                int cr = node.first;
                int cc = node.second;
                distance[cr][cc] = level;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = cr + dr[i];
                    int nc = cc + dc[i];
                    if (isvalid(nr, nc, n, n) && !vis[nr][nc]) {
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
            level++;
        }
        int l = 0;
        int r = 400;
        int res = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(distance, m)) {
                res = m;
                l = m + 1;

            } else {
                r = m - 1;
            }
        }
        return res;
    }
};
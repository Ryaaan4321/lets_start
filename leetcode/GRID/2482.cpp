#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<pair<int, int>> row(n, pair<int, int>(0, 0));
        vector<pair<int, int>> col(m, pair<int, int>(0, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    row[i].first++;

                } else {
                    row[i].second++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    col[j].first++;
                } else {
                    col[j].second++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] =
                    row[i].second + col[j].second - row[i].first - col[j].first;
            }
        }
        return ans;
    }
};
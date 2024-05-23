#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return i >= 1 && i < n - 1 && j >= 1 && j < m - 1;
    }
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        int sm = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (isvalid(i, j, n, m)) {
                    sm = grid[i][j] + grid[i - 1][j] + grid[i - 1][j - 1] +
                         grid[i - 1][j + 1] + grid[i + 1][j] +
                         grid[i + 1][j - 1] + grid[i + 1][j + 1];
                }
                mx = max(mx, sm);
            }
        }
        return mx;
    }
};
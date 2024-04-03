#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int n;
    vector<vector<int>> del = {{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};
    int dp[51][51][51][51];
    int solve(vector<vector<int>> &grid, int r1, int c1, int r2, int c2)
    {
        if (r1 == n - 1 && c1 == n - 1 && r2 == n - 1 && c2 == n - 1)
        {
            return grid[r1][c1];
        }
        if (dp[r1][c1][r2][c2] != -1)
        {
            return dp[r1][c1][r2][c2];
        }
        int ro1, ro2, co1, co2;

        int ret = 0;
        if (r1 == r2 && c1 == c2)
            ret += grid[r1][c1];
        else
            ret += grid[r1][c1] + grid[r2][c2];

        int mx = -1e9;
        for (auto &d : del)
        {
            ro1 = r1 + d[0];
            co1 = c1 + d[1];
            ro2 = r2 + d[2];
            co2 = c2 + d[3];

            if (ro1 >= n || co1 >= n || co2 >= n || grid[ro1][co1] == -1 || grid[ro2][co2] == -1)
            {
                continue;
            }
            mx = max(mx, solve(grid, ro1, co1, ro2, co2));
        }
        ret += mx;
        return dp[r1][c1][r2][c2] = ret;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(grid, 0, 0, 0, 0);
        return ans < 0 ? 0 : ans;
    }
};